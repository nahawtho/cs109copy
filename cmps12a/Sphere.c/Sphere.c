/* Sphere.c
 * Nicholas Hawthorne
 * 1536694
 * lab7
 * determines volume and surface area of sphere from radius */

#include<stdio.h>
int main(){
	const double pi = 3.141592654;
	double r, v, s; /* initialize radius vol and surface area */

	printf("Enter the radius of the sphere: ");
	scanf("%lf", &r);
	v = ((4.0/3)*pi*r*r*r);
	s = (4*pi*r*r);
	printf("The volume is %f and the surface area is %f.\n", v, s);
}

