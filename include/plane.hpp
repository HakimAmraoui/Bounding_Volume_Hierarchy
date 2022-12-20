#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H
#include "vector3.hpp"
#include "solid.hpp"
#include "ray.hpp"
namespace Raytracing{
    class Plane : public Solid{
        public:
            Vector3 normalVect;
            float intersect(Ray const &r) override;
            Vector3 normal(const Vector3 &position) override;
            Plane();
            Plane(Vector3 origin);
        private:
            void initNormal();
    };
}

#endif