#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "3D/aObject3D.hpp"
#include <vector>
namespace Raytracing
{
    	
	/*
	 * Classe repr�sentant une sph�re 3D.
	 * H�rite de AObject3D
	 */


	class Sphere : public AObject3D
	{
	public:
		Sphere() = default;

		Sphere(const Vec3f &center, const float radius,
			   const float reflectionAmount, const float refractionAmount,
			   const float refractionIndex, const float rugosity,
			   const Vec3f &f0);

		std::vector<Intersection> intersect(const Ray &ray);

	private:
		Vec3f _center = VEC3F_ZERO;
		float _radius = 1.f;
	};
} // namespace Raytracing

#endif