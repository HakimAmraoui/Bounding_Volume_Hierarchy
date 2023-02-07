#ifndef RAYTRACING_FLATCOLORMATERIAL_H
#define RAYTRACING_FLATCOLORMATERIAL_H

#include "3D/aMaterial.hpp"

namespace Raytracing
{
	
	/*
	 * Materiel contant l'albedo de l'objet
	 */

	
	class FlatColorMaterial : public AMaterial
	{

	public:

		
	
		FlatColorMaterial(const Vec3f &color) : _color(color) {}


		Vec3f shade(const Ray &ray, const Intersection &pos)
		{
			return _color;
		}
	private:
		Vec3f _color = VEC3F_ZERO;
	};
}
#endif