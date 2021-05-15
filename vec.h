#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cmath>

using namespace std;
using std::sqrt;

class vec{
    public:
        vec(){
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }
        vec(double e0, double e1, double e2){
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }

        double x() const {
            return e[0];
        }

        double y() const{
            return e[1];
        }

        double z() const{
            return e[2];
        }

        vec operator - () const {
            return vec(-e[0], -e[1], -e[2]);
        }

        double operator [] (int i) const{
            return e[i];
        }

        double& operator [] (int i) {
            return e[i];
        }

        vec& operator += (const vec &v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec& operator *= (const double t){
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec& operator /= (const double t){
            e[0] /= t;
            e[1] /= t;
            e[2] /= t;
            return *this;
        }

        double length() const{
            return sqrt(length_squared());
        }

        double length_squared() const{
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }

        inline static vec random(){
            return vec(random_double(), random_double(), random_double() );
        }

        inline static vec random(double min, double max){
            return vec(random_double(min, max), random_double(min, max), random_double(min, max));
        }

        bool near_zero() const{
            const auto s = 1e-8;
            return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
        }
    
    public:
        double e[3];
};
inline ostream& operator << (ostream &out, const vec &v){
    return out << v.e[0] << ' '<<v.e[1] << ' '<<v.e[2];
}

inline vec operator + (const vec &u, const vec &v){
    return vec(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec operator - (const vec &u, const vec &v){
    return vec(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec operator * (const vec &u, const vec &v){
    return vec(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec operator * (double t, const vec &v){
    return vec(t * v.e[0], t*v.e[1] , t*v.e[2]);
}

inline vec operator * (const vec &v, double t){
    return t * v;
}

inline vec operator / (vec v, double t){
    return (1/t) * v;
}

inline double dot(const vec &u, const vec &v){
    return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2];
}

inline vec cross(const vec &u, const vec &v){
    return vec(u.e[1] * v.e[2] - u.e[2] * v.e[1],
             -(u.e[0] * v.e[2] - u.e[2] * v.e[0]), 
               u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec unit_vector(vec v){
    return v / v.length();
}

inline vec random_in_unit_sphere(){
    while(true){
        auto p = vec::random(-1, 1);
        if (p.length_squared() >=1 ){
            continue;
        }
        return p;
    }
}

inline vec random_unit_vector(){
    return unit_vector(random_in_unit_sphere());
}

inline vec random_in_hemisphere(const vec& normal){
    vec in_unit_sphere = random_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0){
        return in_unit_sphere;
    }
    else {
        return -in_unit_sphere;
    }
}

inline vec reflect(const vec& v, const vec& n){
    return v - 2.0 * dot(v, n) * n; 
}
//Alias
using point = vec;
using color = vec;

#endif
