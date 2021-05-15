#ifndef CAMERA_H
#define CAMERA_H

#include "utility.h"

class camera{
    public:
        camera();
        ray get_ray(double u, double v) const; 
    public:
        point origin;
        vec horizontal;
        vec vertical;
        vec depth;
        point lower_left_corner;
};

camera::camera(){
    const auto aspect_ratio = 16.0 / 9.0;
    const auto image_width = 400;
    const auto image_height = static_cast<int>(image_width / aspect_ratio);

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    origin = point(0, 0, 0);
    horizontal = vec(viewport_width, 0, 0);
    vertical = vec(0, viewport_height, 0);
    depth = vec(0, 0, focal_length);
    lower_left_corner = origin - horizontal/2 - vertical/2 - depth;
}

ray camera::get_ray(double u, double v) const{
    return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}
#endif
