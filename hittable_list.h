#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H


#include <vector>


class hittable_list : public hittable {
    public:
        std::vector<shared_ptr<hittable> > objects;

        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;
            bool hit_anything = false;
            auto closest_so_far = ray_t.max;

            for (const auto& object : objects) {
                if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }

    // Explicitly define the destructor with the same exception specification as the base class
    // ~hittable_list() override = default;
};

#endif // HITTABLE_LIST_H


/*
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"


#include <vector>


class hittable_list : public hittable {
    public:
        std::vector<shared_ptr<hittable> > objects;

        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }

        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override
        {
            hit_record temp_rec;
            bool hit_anything = false;
            auto closest_so_far = t_max;

            for (const auto& object : objects) {
                if (object->hit(r, t_min, closest_so_far, temp_rec)) {
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }



    // Explicitly define the destructor with the same exception specification as the base class
    ~hittable_list() override = default;
};

#endif

*/