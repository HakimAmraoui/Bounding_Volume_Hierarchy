#include "light/point_light.hpp"

namespace Raytracing{

    /*
	 * Class constructor
	 */


	PointLight::PointLight(const Vec3f &color, const Vec3f &position, const		float intensity)
	{
		_color = color;
		_position = position;
		_intensity = intensity;
	}

	/*
	 * Function to retrieve the intensity of the light
	  * as a function of the distance between a point and the center of the light
	 */

	float PointLight::getIntensity(const float length)
	{
		float intensity	= (_intensity) /M_PI * 4.f* (length * length);

		intensity = glm::clamp(intensity,0.f,1.0f);

		return intensity;

	}
}