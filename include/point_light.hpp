#ifndef RAYTRACING_POINT_LIGHT_H
#define RAYTRACING_POINT_LIGHT_H
#include "light.hpp"
#include "vector3.hpp"
namespace Raytracing{
    class Point_light : public Light{
        public:
            Vector3 origin;
            Vector3 color;
            Vector3 get_direction(Vector3 const &position) const override;
            Point_light(Vector3 origin);
            Point_light();
            float get_minimum_dist(Vector3 const & p) const override;
            Vector3 get_color() const override;
    };
}

#endif