/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _CUBE_H_
#define _CUBE_H_

#include <vector>

#include "containable.h"
#include "point.h"

class Cube : public Containable3D {
    public:
        // do not modify or remove this constructor
	Cube(const Point3D uppper_face[4], const Point3D lower_face[4]);
};

#endif
