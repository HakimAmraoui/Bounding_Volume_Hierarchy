#ifndef RAYTRACING_SOLID_H
#define RAYTRACING_SOLID_H
#include "vector3.hpp"
#include "ray.hpp"
#include "material.hpp"
namespace Raytracing{
    class Solid{
        public:
            Vector3 origin;
            Material material;
            Solid();
            Solid(Vector3 origin);
            virtual float intersect(const Ray& r);
            virtual Vector3 normal(const Vector3 &position);
            virtual Vector3 get_color_at(const Vector3 &position);
    };
}
#endif