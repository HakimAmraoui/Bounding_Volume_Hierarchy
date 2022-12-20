#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H
#include "vector3.hpp"
#include <iostream>
namespace Raytracing{
    class Material{
        public:
            Vector3 color;
            float roughness;
            bool metallic;
            Vector3 get_color_at(Vector3 const &position, Vector3 const &uv_coordinates);
            float get_roughness_at(Vector3 const &position, Vector3 const &uv_coordinates);
            Material();


    };
}

#endif