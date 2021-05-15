#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"

class sphere : public object{
    public:
        sphere(){}
        sphere(point cen, double rad, shared_ptr<material> m){
            center = cen;
            radius = rad;
            mat_ptr = m;
        }
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
    public:
        point center;
        double radius;
        shared_ptr<material> mat_ptr;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const{
    vec oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto disc = half_b * half_b - a * c;
    if (disc < 0){
        return false;
    }
    auto root = (-half_b - sqrt(disc))/a;
    if (root < t_min || root > t_max){
        root = (-half_b + sqrt(disc))/a;
        if (root < t_min || root > t_max){
            return false;
        }
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    vec outward_normal = unit_vector(rec.p - center) ; 
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;
    return true;

}
#endif
