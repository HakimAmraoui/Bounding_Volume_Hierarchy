#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H

#include "../defines.hpp"
namespace Raytracing{


    class Light
	{
	public:
		Light() = default;
		Light(const Vec3f &color, const Vec3f &position);

		Vec3f& getPosition();
		Vec3f& getColor();

		//Fonction virtuelle implémenté par les classes héritant de celle ci
		virtual float getIntensity(const float length);

		protected:
			Vec3f _color;
			Vec3f _position;

	};
}

#endif