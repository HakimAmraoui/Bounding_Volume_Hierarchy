#include "camera.hpp"
#include "stdio.h"
#define PI 3.141592

namespace Raytracing{

    /*
	 * Class constructor
	 */

	Camera::Camera(uint width, uint height, float focale)
	{
		this->_focale = focale;
		this->_ratio = (float)width / (float)height;
	}

	/*
     * Generate a ray from the pixel's position on the screen
	 */

	Ray Camera::generateRay(Vec2f pixelPos)
	{
		Vec3f right = glm::cross(_up,Vec3f(0.0f, 0.0f, _focale) );

		Vec3f posCenter = _posCam + _direction*_focale;

		float posX = pixelPos.x -0.5f;
		float posY = 0.5f - pixelPos.y;

		Vec3f worldPos = posCenter + posY * _up + posX * right * _ratio;

		return Ray(_posCam, glm::normalize(worldPos - _posCam));
	}

    /*
    * Getter
    */
	Vec3f Camera::getPosition()
	{
		return _posCam;
	}

}
