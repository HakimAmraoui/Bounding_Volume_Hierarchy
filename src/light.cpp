#include "light.hpp"
namespace Raytracing{
    Light::Light(){
        color= Vector3(1.0,1.0,1.0);
    }
    Vector3 Light::get_direction(Vector3 const &position) const{
        return Vector3();
    }
    float Light::get_minimum_dist(Vector3 const & p) const{
        return 100000;
    }
    Vector3 Light::get_color() const{
        return this->color;
    }
}