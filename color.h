#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "utility.h"

using namespace std;

void write_color(color pixel_color);

void write_color(color pixel_color, int samples_per_pixel){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;

    r = clamp(sqrt(r * scale), 0, 0.999);
    g = clamp(sqrt(g * scale), 0, 0.999);
    b = clamp(sqrt(b * scale), 0, 0.999);
    cout << static_cast<int>(256 * r)<<' '<<
        static_cast<int>(256 * g)<<' '<<
        static_cast<int>(256 * b)<<'\n';
}


#endif
