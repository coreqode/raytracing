#ifndef CAMERA_H
#define CAMERA_H

#include "utility.h"

class camera{
    public:
        camera(
                point lookfrom, point lookat, vec vup, double vfov, double aspect_ratio, 
                double aperture, double focus_dist
                );
        ray get_ray(double u, double v) const; 
    public:
        point origin;
        vec horizontal;
        vec vertical;
        point lower_left_corner;
        vec u, v, w;
        double lens_radius;
};

camera::camera(
        point lookfrom, point lookat, vec vup, double vfov, double aspect_ratio, 
        double aperture, double focus_dist
        ){
    auto theta = degrees_to_radians(vfov);
    auto h = tan(theta / 2);

    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    w = unit_vector(lookfrom  - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    origin = lookfrom;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist * w;
    lens_radius = aperture / 2;
}

ray camera::get_ray(double s, double t) const{
    vec rd = lens_radius * random_in_unit_disk();
    vec offset = u * rd.x() + v * rd.y();
    return ray(
            origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset);
}
#endif
