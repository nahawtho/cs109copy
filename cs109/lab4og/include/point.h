/*
 * Copyright (C) 2018 David C. Harrison. All right reserved.
 *
 * You may not use, distribute, publish, or modify this code without 
 * the express written permission of the copyright holder.
 */

#ifndef _POINT_H_
#define _POINT_H_

class Point {
    public:
        // do not remove or modify these attributes
        double x;
        double y;

        // do not remove or modify these constructors
        Point() { x = 0.0, y = 0.0; }
        Point(double dx, double dy) { x = dx; y = dy; }
        Point(const Point &p) { x = p.x; y = p.y; }
};

class Point3D : public Point {
    public:
        // do not remove or modify these attributes
        double z;

        // do not remove or modify these constructors
        Point3D() : Point() { z = 0.0; }
        Point3D(double dx, double dy, double dz) : Point(dx, dy) { z = dz; }
        Point3D(const Point3D &p) : Point(p.x, p.y) { z = p.z; }
};

#endif
