#ifndef RAY_H
#define RAY_H

#include "vec.h"

class ray{
    public:
        ray(){}
        ray(const point& origin, const point& direction){
            orig = origin;
            dir = direction;
        }
        point origin() const{
            return orig;
        }
        vec direction() const{
            return dir;
        }
        point at(double t) const{
            return orig + t * dir;
        }

    public:
        point orig;
        vec dir;
};

#endif
