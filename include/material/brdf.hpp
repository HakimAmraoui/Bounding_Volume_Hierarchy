#ifndef RAYTRACING_BRDF_H
#define RAYTRACING_BRDF_H

#include "../defines.hpp"

namespace Raytracing
{

	/*
	 * BRDF Microfacet implementation
	 */

	class BRDF
	{
	public:
		BRDF() = default;

		Vec3f fresnelTerm(const Vec3f &f0,const float lh);

		float beckmanTerm(const float nh, const float rugosity);

		float cook_torrance(const float nv, const float nh, const float vh,
							const float nl);

		Vec3f brdfTerm(const Vec3f &light, const Vec3f &view,
					   const Vec3f &normalLocal, const float rugosity,
					   const Vec3f f0);

	private:
	};

}

#endif