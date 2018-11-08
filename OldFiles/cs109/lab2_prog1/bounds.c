//https://opencast-player-1.lt.ucsc.edu:8443/engage/theodul/ui/core.html?id=ba4a7a48-7393-46b9-9a64-3654b7ad2b4e
//https://opencast-player-1.lt.ucsc.edu:8443/engage/theodul/ui/core.html?id=777cbe9d-fb9c-4ab5-a9d1-be9e26478f3e
//https://classes.soe.ucsc.edu/cmps109/Fall18/SECURE/CMPS109-Lab2-SecretSauce.pdf
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bounds.h"

static char *type_names[] = {
	"circle",
	"triangle",
};


static const char *get_shape_name_from_type(enum shape_type typpe)
{
	return type_names[typpe];
}

static double distance_between_two_points(Point *p1, Point *p2) {
	return sqrt(
		( (p1->x - p2->x ) * (p1->x - p2->x )) +
		( (p1->y - p2->y ) * (p1->y - p2->y )));
}

static bool circle_contained_by_circle(Circle *inner, Circle *outer){
	double dist_test = distance_between_two_points(&inner->center, &outer->center);
	printf("dist_test %f\n", dist_test);
	bool contained_not_offset = distance_between_two_points(&inner->center, &outer->center) <= outer->radius - inner->radius;
	bool tan_circles_outside = ( distance_between_two_points(&inner->center, &outer->center)
		 == outer->radius + inner->radius );
	printf("%f == %f + %f if tan_circles_outside\n", 
		distance_between_two_points(&inner->center, &outer->center),
		outer->radius, inner->radius); 
	printf("inner point %f, %f\n", inner->center.x, inner->center.y);	
	if (tan_circles_outside)	
		{
			printf("Return tan circles outside in first clause\n");
			return 0;
		}
	else {
		printf("contained_not_offset %d in 2nd\n", contained_not_offset );
		return contained_not_offset;
	}
}

/*
 * Determine if one shape is contained by another where "contained"
 * means enirely within the bounds of the containing shape.
 *
 * Return TRUE if INNER is contaned within OUTER, FALSE otherwise.
 */
bool contained_by(Shape *inner, Shape *outer) {
	printf("\ninner: %s\n", get_shape_name_from_type(inner->type));
	printf("outer: %s\n", get_shape_name_from_type(outer->type));
	if (inner->type == CIRCLE && outer->type == CIRCLE){
 		return circle_contained_by_circle((Circle *) inner, (Circle *) outer);
	}
	if (inner->type == CIRCLE && outer->type ==TRIANGLE){
		printf("Instance of Circle contained by Triangle\n");
		return 0; //false
//		return circle_contained_by_triangle((Circle *) inner, (Triangle *) outer);
	}
	if (inner->type == TRIANGLE && outer->type == CIRCLE){
		printf("Instance of Triangle contained by Circle\n");
		return 0; //false
	}
	exit(-1);
}
