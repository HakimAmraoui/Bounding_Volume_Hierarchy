#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H
#include "defines.hpp"

namespace Raytracing{
    /*
	 * Classe contenant les donn�es d'un rayon
	 */


	class Ray
	{
	public:

		Ray() {}

		Ray(const Vec3f &origin, const Vec3f &direction)
			: _origin(origin),_direction(direction)
		{
		}

		Vec3f getOrigin() const ;
		
		Vec3f getDirection() const; 


	private:
		Vec3f _origin;
		Vec3f _direction;

	};
}
#endif