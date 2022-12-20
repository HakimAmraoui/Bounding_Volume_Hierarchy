#include "solid.hpp"

namespace Raytracing{
    Solid::Solid(Vector3 v){
        this->origin = v;
    }
    Solid::Solid(){
        Solid(Vector3());
    }
    Vector3 Solid::get_color_at(const Vector3 &position){
        return this->material.get_color_at(position, Vector3());
    }
    float Solid::intersect(const Ray &r){
        return 0;
    }
    Vector3 Solid::normal(const Vector3 &position){
        return Vector3(1,0,0);
    }
}