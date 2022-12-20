#include "material.hpp"

namespace Raytracing{
    Material::Material(){
        this->color = Vector3(1,1,1);
        this->roughness = .8;
        this->metallic = false;
    }

    Vector3 Material::get_color_at(Vector3 const &p, Vector3 const &uv){
        return this->color;
    }
    float Material::get_roughness_at(Vector3 const &p, Vector3 const &uv){
        return this->roughness;
    }

}