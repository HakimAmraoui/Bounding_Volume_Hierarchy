#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H
#include "vector3.hpp"

namespace Raytracing{
    class Ray{
        public:
            Vector3 origin;
            Vector3 direction;
            Ray(const Vector3& o, const Vector3& d);

            

    };
}
#endif