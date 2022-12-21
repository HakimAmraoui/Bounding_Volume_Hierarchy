#ifndef RAYTRACING_PLANE_H
#define RAYTRACING_PLANE_H
#include "3D/aObject3D.hpp"
#include "triangleMesh.hpp"
#include "defines.hpp"
#include <vector>
namespace Raytracing{
    /*
	 * Classe  repr�sentant un plan 3D.
	 * H�rite de AObject3D
	 * Le plan est r�pr�sent� � l'aide de sa normale et d'un point appartenant
	 * � celui ci.
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
		Vec3f _p1;				 //Point appartenant au plan
		Vec3f _normale;          //Normale du plan
	};
}

#endif