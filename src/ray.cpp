#include "ray.hpp"
namespace Raytracing{
    Ray::Ray(const Vector3& o, const Vector3& d){
        this->origin = o;
        this->direction = d;
    }
}