#ifndef RAYTRACING_INTERSECTION_H
#define RAYTRACING_INTERSECTION_H

// #include "defines.hpp"
#include "../defines.hpp"
#include <limits>

namespace Raytracing
{

	class AObject3D;

	/*
	 * Structure contenant les donn�es d'intersection entre un rayon et un objet
	 */


	struct Intersection
	{
		Intersection() = default;

		Intersection(float distance, const Vec3f &position,
					 const Vec3f &normale, AObject3D *intersectingObject);

		AObject3D * _object = nullptr;
		Vec3f _normale = VEC3F_ZERO;	
		Vec3f _position = VEC3F_ZERO;
		float _distance = -1.f;
	};
}

#endif