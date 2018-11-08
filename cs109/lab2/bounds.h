/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _BOUNDS_H_
#define _BOUNDS_H_

#include <stdbool.h>

typedef struct point_t {
    double x;
    double y;
} 
Point;

enum shape_type {
    CIRCLE,
    TRIANGLE,
    PENTAGON,
    REULEAUX_TRIANGLE,
};

#define TYPE enum shape_type type

typedef struct shape_t {
    TYPE;
}
Shape;

typedef struct circle_t {
    TYPE;
    Point center;
    double radius;
} 
Circle;

typedef struct triangle_t {
    TYPE;
    Point vertices[3];
} 
Triangle;

typedef struct pentagon_t {
    TYPE;
    Point vertices[5];
} 
Pentagon;

typedef struct reuleaux_triangle_t {
    TYPE;
    Point vertices[3];
} 
ReuleauxTriangle;

bool contained_by(Shape *inner, Shape *outer);

#endif
