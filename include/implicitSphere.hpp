#ifndef RAYTRACING_IMPLICITSPHERE_H
#define RAYTRACING_IMPLICITSPHERE_H

#include "3D/aObject3D.hpp"
#include "defines.hpp"
#include <vector>

namespace Raytracing
{
    /*
	 * Classe repr�sentant une sph�re 3D calcul�e de mani�re implicite
	 */

	class ImplicitSphere : public AObject3D
	{
	public:
		ImplicitSphere() = default;

		ImplicitSphere(const Vec3f &center, const float radius,
					   const float reflectionAmount,
					   const float refractionAmount, const float refractionIdx,
					   const float rugosity, const  Vec3f &f0);

		float distanceImplicitFunction(const Vec3f &position);

		Vec3f calcNormal(const Vec3f &pos);

		std::vector<Intersection> intersect(const Ray &ray);

	private:
		Vec3f _center;
		float _radius;
	};
}

#endif