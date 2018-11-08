/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <vector>

#include "containable.h"
#include "point.h"

class Sphere : public Containable3D {
    public:
        // do not modify or remove this constructor
	Sphere(const Point3D &center, double radius);
};

#endif
