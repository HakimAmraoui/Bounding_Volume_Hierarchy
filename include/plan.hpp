#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H
#include "3D/aObject3D.hpp"
#include "triangleMesh.hpp"
#include "defines.hpp"
#include <vector>
namespace Raytracing{
    /*
	 * Representation of a 3D plan : AObject3D
	 * A plan is represented by its normal and points belonging to it
	 */


	class Plan : public AObject3D
	{
	public:
		Plan() = default;

		Plan(const Vec3f &normale, const Vec3f &p1, float reflectionAmount,
			 float refractionAmount, float refractionIdx, float rugosity,
			 Vec3f f0);

		std::vector<Intersection> intersect(const Ray &ray);

	private:
		Vec3f _p1;				 // Points belonging to the plan
		Vec3f _normale;          // Plan's normale
	};
}

#endif