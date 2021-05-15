#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

//Using

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979323846264338327950288;

//Utility Functions

inline double degrees_to_radians(double degrees){
    return degrees * pi / 180.0;
}

inline double random_double(){
    return rand() / ( RAND_MAX + 1.0 );
}

inline double random_double(double min, double max){
    return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max){
    if (x < min){
        return min;
    }
    if (x > max){
        return max;
    }
    return x;
}
//Common Headers
#include "vec.h"
#include "ray.h"

#endif
