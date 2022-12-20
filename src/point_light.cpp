#include "point_light.hpp"

namespace Raytracing{

    Vector3 Point_light::get_direction(Vector3 const &position) const{
        Vector3 pos = this->origin - position;
        pos.normalize();
        return pos;
    }

    Point_light::Point_light(Vector3 origin){
        this->origin = origin;
        this->color = Vector3(1.0,1.0,1.0);
    }

    Point_light::Point_light(){
        this->origin = Vector3();
        this->color = Vector3(1.0,1.0,1.0);
    }

    float Point_light::get_minimum_dist(Vector3 const & p) const{
        return (p - this->origin).length();
    }
    Vector3 Point_light::get_color() const{
        return this->color;
    }

}