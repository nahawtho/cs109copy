//http://alienryderflex.com/intersect/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bounds.h"

static char *type_names[] = {
	"Circle",
	"Triangle",
};


static const char *get_shape_name_from_type(enum shape_type type)
{
	return type_names[type];
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

bool lineIntersection(
double Ax, double Ay,
double Bx, double By,
double Cx, double Cy,
double Dx, double Dy,
double *X, double *Y) {

  double  distAB, theCos, theSin, newX, ABpos ;

  //  Fail if either line is undefined.
  if ((Ax==Bx && Ay==By) || (Cx==Dx && Cy==Dy)) return 0;

  //  (1) Translate the system so that point A is on the origin.
  Bx-=Ax; By-=Ay;
  Cx-=Ax; Cy-=Ay;
  Dx-=Ax; Dy-=Ay;

  //  Discover the length of segment A-B.
  distAB=sqrt(Bx*Bx+By*By);

  //  (2) Rotate the system so that point B is on the positive X axis.
  theCos=Bx/distAB;
  theSin=By/distAB;
  newX=Cx*theCos+Cy*theSin;
  Cy  =Cy*theCos-Cx*theSin; Cx=newX;
  newX=Dx*theCos+Dy*theSin;
  Dy  =Dy*theCos-Dx*theSin; Dx=newX;

  //  Fail if the lines are parallel.
  if (Cy==Dy) return 0;

  //  (3) Discover the position of the intersection point along line A-B.
  ABpos=Dx+(Cx-Dx)*Dy/(Dy-Cy);

  //  (4) Apply the discovered position to line A-B in the original coordinate system.
  *X=Ax+ABpos*theCos;
  *Y=Ay+ABpos*theSin;

  //  Success.
  return 1; }

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
		double Ax = -5;
		double Ay = 0;
		double Bx = 5;
		double By = 0;
		double Cx = 0;
		double Cy = 10;
		double Dx = 0;
		double Dy = 5;	
		double *X = &Dx; double *Y = &Dx; //useless declarations for warnings
		if (lineIntersection(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, X, Y)) printf("Something True\n");
		else printf("Something false\n");
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
