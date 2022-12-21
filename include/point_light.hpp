#ifndef RAYTRACING_POINT_LIGHT_H
#define RAYTRACING_POINT_LIGHT_H
#include "light.hpp"
#include "defines.hpp"
namespace Raytracing{
    /*
	 * Classe repr�sentant les lumi�res sph�riques
	 * H�rite de Light
	 */
	
	class PointLight : public Light
	{
	public:
		
		PointLight() = default;
		PointLight(const Vec3f &color, const Vec3f &position, const float intensity);
		float getIntensity(const float length) override;

	private:
		float _intensity;
	};
}

#endif