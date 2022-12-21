#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "defines.hpp"
#include "ray.hpp"

namespace Raytracing
{

	/*
	 * Classe repr�sentant la cam�ra de la sc�ne
	 */

	class Camera
	{
	public:
		Camera();
		Camera(uint width, uint height, float focale);

		Ray generateRay(Vec2f pixelPos);
		Vec3f getPosition();

	private:
		Vec3f _posCam = VEC3F_ZERO;
		Vec3f _direction = Vec3f(0.0f, 0.0f, 1.0f);
		float _ratio;
		float _focale;
		Vec3f _up = Vec3f(0.0f, 1.0f, 0.0f);

	};
}
#endif
