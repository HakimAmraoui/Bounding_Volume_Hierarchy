#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H
#include "vector3.hpp"
namespace Raytracing{
    class Light{
        public:
            Vector3 color;
            virtual Vector3 get_direction(Vector3 const &p) const;
            virtual float get_minimum_dist(Vector3 const &p) const;
            virtual Vector3 get_color() const;
            Light();
    };
}

#endif