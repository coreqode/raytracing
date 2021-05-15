#ifndef OBJECTS_LIST_H
#define OBJECTS_LIST_H

#include "object.h"
#include <memory>
#include <vector>
#include "utility.h"

class objects_list: public object{
    public:
        objects_list(){}
        objects_list(shared_ptr<object> obj) { 
            add(obj);
        }
        void clear() { 
            objs.clear() ;
        }
        void add(shared_ptr<object> obj){
            objs.push_back(obj);
        }
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

    public:
        std::vector<shared_ptr<object>> objs;
};


bool objects_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& obj : objs){
        if (obj -> hit(r, t_min, closest_so_far, temp_rec)){
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}
#endif
