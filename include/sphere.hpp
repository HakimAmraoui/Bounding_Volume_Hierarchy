#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H
#include "vector3.hpp"
#include "solid.hpp"
#include <cmath>
namespace Raytracing
{
    class Sphere : public Solid{
        public:
            float radius = 1;
            float intersect(const Ray& r) override ;
            Sphere(Vector3 v = Vector3());
            Sphere();
            Vector3 get_color_at(const Vector3 &position) override;

            Vector3 normal(const Vector3 &position) override;
        private:
            Vector3 get_uv_at(const Vector3 &position);

    };
} // namespace Raytracing

#endif