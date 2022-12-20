#include "sphere.hpp"


namespace Raytracing{
    float Sphere::intersect(const Ray& r){
        //a est égal à 1, c n'a besoin d'être calculé qu'une fois.
        float b = 2*(
                    r.origin.x * r.direction.x +
                    r.origin.y * r.direction.y +
                    r.origin.z * r.direction.z -
                    this->origin.x * r.direction.x -
                    this->origin.y * r.direction.y -
                    this->origin.z * r.direction.z);

        float delta= b*b-4*(
                r.origin.x*r.origin.x - 2*this->origin.x * r.origin.x + this->origin.x*this->origin.x +
                r.origin.y*r.origin.y - 2*this->origin.y * r.origin.y + this->origin.y*this->origin.y + 
                r.origin.z*r.origin.z - 2*this->origin.z * r.origin.z + this->origin.z*this->origin.z -
                this->radius * this->radius);
            if (delta >0){
                float sqrtDelta = std::sqrt(delta);
                float sol1 = (-b+sqrtDelta)/2;
                float sol2 = (-b-sqrtDelta)/2;
                if ((sol1 < sol2 || sol2 < 0) && sol1 > 0)
                    return sol1;
                if (sol2 > 0)
                    return sol2;
            }
            return 0;
    }
    Sphere::Sphere(Vector3 origin){
        this->origin = origin;
    }
    Sphere::Sphere(){
        this->origin = Vector3();
    }

    Vector3 Sphere::normal(const Vector3 &position){
        Vector3 toRet = (position - this->origin);
        toRet.normalize();
        return toRet;
    }

    Vector3 Sphere::get_color_at(const Vector3 &position){
        return this->material.get_color_at(position, get_uv_at(position));
    }

    Vector3 Sphere::get_uv_at(const Vector3 & position){
        return Vector3(0,0,0);
    }
}
