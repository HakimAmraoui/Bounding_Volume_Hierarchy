#ifndef RAYTRACING_LIGHTMATERIAL_H
#define RAYTRACING_LIGHTMATERIAL_H
#define _USE_MATH_DEFINES

#include "../3D/aMaterial.hpp"
#include "../defines.hpp"
#include "../3D/aMaterial.hpp"
#include <vector>
// #include "BVH/bvhnode.hpp"
#include "brdf.hpp"
#include "../light/light.hpp"
#include "../camera.hpp"
#include <math.h>

namespace Raytracing
{
    // TODO 
	/*
     * Get object's color from data of its material
	 */

	class LightMaterial : public AMaterial
	{
	public:
		LightMaterial(const std::vector<Light *> &lights, const Camera &_camera,
					  int limit);

		Vec3f shade(const Ray &ray, const Intersection &hitPoint);

		Vec3f getColor(const Ray &ray, const Intersection &currentIntersection,
					int loop);

		int calculateShadow(const Intersection &hitpoint, Light *&light,
							  Vec3f &color, AObject3D *&currentObject);

		void setObjects(std::vector<AObject3D *> &objects);

		// void setBVH(std::vector<BVHNode *> &bvh);

	private:
		int _limit;									//Limite de r�cursion de la fonction getColor
		BRDF _brdf;									//BRDF
		std::vector<Light *> _lights;				//Lumi�res de la sc�ne
		Camera _camera;								//Cam�ra
		std::vector<AObject3D *> _objects;			//Objets de la sc�ne
		// std::vector<BVHNode *> _bvh;				//Objets BVH de la sc�ne
	};

}; // namespace ISICG_ISIR
#endif