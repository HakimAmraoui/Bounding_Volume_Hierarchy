#include "plane.hpp"

namespace Raytracing{
    void Plane::initNormal(){
        this->normalVect = Vector3(0,0,1);
    }
    Plane::Plane(){
        this->origin = Vector3();
        this->initNormal();
    }
    Plane::Plane(Vector3 origin){
        this->origin = origin;
        this->initNormal();
    }
    Vector3 Plane::normal(const Vector3 &position){
        return this->normalVect;
    }

    float Plane::intersect(Ray const &r){
        float lambda = -(r.origin - this->origin).dotProduct(this->normalVect)/
        (r.direction.dotProduct(this->normalVect));
        return lambda;
    }
}