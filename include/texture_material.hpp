#ifndef RAYTRACING_TEXTURE_MATERIAL_H
#define RAYTRACING_TEXTURE_MATERIAL_H
#include "vector3.hpp"
namespace Raytracing{
    class Texture_material{
        Vector3 colorAt(Vector3 position, Vector3 angle, Vector3 normal);
    };
}

#endif