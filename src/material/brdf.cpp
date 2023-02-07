#define _USE_MATH_DEFINES
#include "../../include/material/brdf.hpp"
#include <math.h>

namespace Raytracing
{

	/*
     * Compute the Fresnel term from the Fresnel coefficient f0 and from the
     * vectorial product (light - camera)
	 */

	Vec3f BRDF::fresnelTerm(const Vec3f & f0,const float lh)
	{
		return f0 + (Vec3f(1.f) - f0) * pow((1 - lh), 5);
	}


	/*
     * Compute the normale distribution with the Beckmann formula
     * from object's rugosity and from the vectorial product (normal - half)
	 */

	float BRDF::beckmanTerm(const float nh,const float rugosity)
	{
		float a = (nh * nh) - 1;
		float b = rugosity * rugosity * nh * nh;

		float c = glm::exp(a / b);
		b = M_PI * rugosity * rugosity * pow(nh, 4);

		return c / b;
	}

	/*
	 * Compute the shadowing/masking with the Cook-Torrance formula
	 */

	float BRDF::cook_torrance(const float nv, const float nh, const float vh,
							  const float nl)
	{
		float a = 2 * nh * nv / vh;
		float b = 2 * nh * nl / vh;
		return fminf(1, fminf(a, b));
	}

	/*
	 * Compute the specularity of an object at a point
     */

	Vec3f BRDF::brdfTerm(const Vec3f &light, const Vec3f &view,
						 const Vec3f &normalLocal, const float rugosity,
						 const Vec3f f0)
	{
		Vec3f h = glm::normalize((light + view) / 2.f);

		float nl = glm::dot(normalLocal, light);
		float nv = glm::dot(normalLocal, view);
		float nh = glm::dot(normalLocal, h);
		float vh = glm::dot(view, h);
		float lh = glm::dot(light, h);

		Vec3f a = fresnelTerm(f0,lh)
				  * cook_torrance(nv,nh,vh,nl)
				  * beckmanTerm(nh, rugosity);

		Vec3f Color = a / (4 * nl * nv);


		return Color;
	}

	
}