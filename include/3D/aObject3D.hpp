#ifndef RAYTRACING_AOBJECT3D_H
#define RAYTRACING_AOBJECT3D_H

// #include "defines.hpp"
#include "aMaterial.hpp"
#include "../defines.hpp"
#include "intersection.hpp"
#include <vector>

namespace Raytracing
{

	/*
	 * Classe m�re repr�sentant la famille de nos objets 3D de la sc�ne
	 */

	class AObject3D
	{
	public:

		void setMaterial(AMaterial *const &material);

		void setColorMaterial(AMaterial *const &colorMaterial);

		AMaterial * getColorMaterial();

		AMaterial *getMaterial();
		
		const float getReflectionAmount();

		const float getRefractionAmount();

		const float getRefractionIndex();

		const float getRugosity();

		const Vec3f& getf0();

		void setReflectionAmount(float refl);
		
		void setRefractionAmount(float refr);
		
		void setRefractionIndex(float refrI);

		void setRugosity(float rugosity);

		void setf0(const Vec3f &f0);

				
		// Compute ray/object intersection
		// return parameter t and set normal if intersection exists
		virtual std::vector<Intersection> intersect(const Ray &ray) = 0;


	protected:
		AMaterial *_material = nullptr;  // pointer for polymorphism

		AMaterial * _colorMaterial = nullptr; //pointer for polymorphism

		float _reflectionAmount=0.f;     //Montant de r�flection de l'objet

		float _refractionAmount = 0.f; // Montant de refraction de l'objet

		float _refractionIndex = 1.f; // Indice de refraction de l'objet

		float _rugosity = 0.5f; // Montant de r�flection de l'objet

		Vec3f _f0;  // Coefficient de Fresnel de l'objet
	};	
}

#endif