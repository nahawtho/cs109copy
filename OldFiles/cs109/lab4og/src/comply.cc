/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

/******************  DO NOT MODIFY THIS FILE ****************************
 *
 * It is not included in the subission archive ceated by 'make submit' .
 *
 * If you modify it and your code relies on those modifications, your code
 * will not compile in the automated test harness and will be unable to
 * execute any tests.
 *
 * To put it another way, if you modify this file, you will get a big fat
 * ZERO on this lab.
 *
 ************************************************************************/

#include <iostream>

#include "circle.h"
#include "polygon.h"
#include "reuleaux.h"
#include "sphere.h"

static void twodim() 
{
    Point p1 = Point();
    Point p2 = Point(0.0, 0.0);
    Point p3 = Point(p2);

    Circle circle = Circle(Point(0.0,0.0), 0.0);
    double x = circle.center().x;
    double r = circle.radius();

    ConvexPolygon polygon = ConvexPolygon({Point(0,0), Point(0,0), Point(0,0)});
    polygon.vertices().size();

    RegularConvexPolygon regular = RegularConvexPolygon({Point(0,0), Point(0,0), Point(0,0)});
    regular.vertices().size();

    Point vertices[3] = {Point(0,0), Point(0,0), Point(0,0)};
    ReuleauxTriangle reuleaux = ReuleauxTriangle(vertices);
    reuleaux.vertices().size();

    circle.containedBy(circle);
    circle.containedBy(polygon);
    circle.containedBy(regular);
    circle.containedBy(reuleaux);

    polygon.containedBy(circle);
    polygon.containedBy(polygon);
    polygon.containedBy(regular);
    polygon.containedBy(reuleaux);

    regular.containedBy(circle);
    regular.containedBy(polygon);
    regular.containedBy(regular);
    regular.containedBy(reuleaux);

    reuleaux.containedBy(circle);
    reuleaux.containedBy(polygon);
    reuleaux.containedBy(regular);
    reuleaux.containedBy(reuleaux);
}

static void threedim() 
{
    Point3D p1 = Point3D();
    Point3D p2 = Point3D(0.0, 0.0, 0.0);
    Point3D p3 = Point3D(p2);

    Sphere sphere = Sphere(Point3D(0.0,0.0,0.0), 0.0);

    Point3D upper[4] = {Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0)};
    Point3D lower[4] = {Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0)};
    Cube cube = Cube(upper, lower);

    Point3D vertices[4] = {Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0), Point3D(0,0,0)};
    ReuleauxTetrahedron reuleaux = ReuleauxTetrahedron(vertices);

    cube.containedBy(cube);
    cube.containedBy(sphere);
    cube.containedBy(reuleaux);

    sphere.containedBy(cube);
    sphere.containedBy(sphere);
    sphere.containedBy(reuleaux);

    reuleaux.containedBy(cube);
    reuleaux.containedBy(sphere);
    reuleaux.containedBy(reuleaux);
}

int main(int argc, char *argv[]) 
{
    twodim();
    threedim();
}
