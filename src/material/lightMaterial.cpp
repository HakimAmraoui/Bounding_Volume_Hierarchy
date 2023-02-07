#include "../../include/material/lightMaterial.hpp"

namespace Raytracing
{
	/*
	 * Class constructor
	 */

	LightMaterial::LightMaterial(const std::vector<Light *> &lights,
								 const Camera &camera, int limit)
		: _camera(camera), _lights(lights), _limit(limit)
	{
	}

	/*
	 * Ici on va v�rifier si le point est dans l'ombre
	 * et modifire son intensit� lumineuse si besoin
	 */

	int LightMaterial::calculateShadow(const Intersection &hitpoint,
										 Light *&light, Vec3f &color,
										 AObject3D *&currentObject)
	{

		Vec3f lightVector = light->getPosition() - hitpoint._position;
		Vec3f normalizedLightVector = glm::normalize(lightVector);

		Ray shadowRay(hitpoint._position, normalizedLightVector);

		std::vector<std::vector<Intersection>> shadowIntersections;

		for (AObject3D *o : _objects)
		{
			shadowIntersections.push_back(o->intersect(shadowRay));
		}

		// for (BVHNode *b : _bvh)
		// {
		// 	shadowIntersections.push_back(
		// 		b->intersect(shadowRay, b).intersect(shadowRay));
		// }

		Intersection closestShadowIntersection;
		bool inShadow = false;

		for (std::vector<Intersection> i : shadowIntersections)
		{
			if (!i.empty())
			{
				inShadow = true;
				for (Intersection j : i)
					if (closestShadowIntersection._distance == -1.f
						|| j._distance < closestShadowIntersection._distance)
						closestShadowIntersection = j;
			}
		}

		if (inShadow
			&& closestShadowIntersection._distance < length(lightVector)
			&& closestShadowIntersection._object != currentObject)
		{
			color =glm::min(color,color/(1.3f * light->getIntensity(closestShadowIntersection._distance)));
			return 1;
		}
		return 0;
	}

	/*
	 * Fonction permettant de r�cup�rer la couleur de l'objet en un point donn�e
	 * Utilise la fonction getColor pour effectuer ceci
	 */

	Vec3f LightMaterial::shade(const Ray &ray, const Intersection &hitPoint)
	{
		return getColor(ray, hitPoint, 0);
	}

	/*
	 * Fonction permettant de r�cup�rer la couleur de l'objet en un point donn�e
	 * La fonction calcule la couleur de r�flection, celle de r�fraction,
	 * ainsi que la couleur diffuse de l'objet et la couleur sp�culaire
	 * au travers de la BRDF et du mat�riau de l'objet
	 */

	Vec3f LightMaterial::getColor(const Ray &ray, const Intersection &hitpoint,
								  int loop)
	{
		AObject3D *currentObject = hitpoint._object;
		Vec3f currentObjectColor = currentObject->getf0();

		Vec3f rflColor = VEC3F_ZERO;
		Vec3f refrColor = VEC3F_ZERO;

		if (loop <= _limit)
		{
			loop++;

			Vec3f normale = hitpoint._normale;

			float etatAir = 1.f;														// Indice de r�fraction dans l'air
			float refractionIndex= etatAir / currentObject->getRefractionIndex();		// Si on est � l'int�rieur del'objet et qu'on en ressort	
																						// On inverse la normale et  l'indice de r�fraction																		
			if (glm::dot(ray.getDirection(), normale) > 0)

			{
				normale = -normale;
				refractionIndex = currentObject->getRefractionIndex();
			}

			float rflA = currentObject->getReflectionAmount();
			float rfrA = currentObject->getRefractionAmount();
			if (rflA > 0.f)															//Si l'objet refl�te
			{
				std::vector<std::vector<Intersection>> intersectionsReflection;

				Ray reflectedRay(
					hitpoint._position,
					glm::normalize(glm::reflect(ray.getDirection(), normale)));


				for (AObject3D *o : _objects)									//Ici on va tester les intersections entre le rayon r�fl�chi et les objets
				{
					intersectionsReflection.push_back(
						o->intersect(reflectedRay));
				}

				// for (BVHNode *b : _bvh)											 // Pareil pour les BVH
				// {
				// 	intersectionsReflection.push_back(b->intersect(reflectedRay, b).intersect(reflectedRay));
				// }

				bool rflRayHasIntersected = false;
				Intersection closestReflectIntersection;

				for (std::vector<Intersection> i : intersectionsReflection)		// Recherche de l'intersection la plus proche entre le rayon
																				// r�fl�chi et les objets de la sc�ne, si elle existe
				{
					if (!i.empty())
					{
						rflRayHasIntersected = true;
						for (Intersection j : i)
						{
							if (closestReflectIntersection._distance == -1.f
								|| j._distance
									   < closestReflectIntersection._distance)
							{
								closestReflectIntersection = j;
							}
						}
					}
				}

				if (rflRayHasIntersected)										// Si on a une intersection de reflection, on va r�effectuer un calcul de couleur avec
				{																// cette fois-ci comme rayon primaire le rayon
																				// r�fl�chi et l' intersection de reflection
					rflColor
						+= getColor(reflectedRay, closestReflectIntersection,	// on obtient r�cursivement la couleur de r�flexion
									loop);

				}
				else
				{
					rflColor += VEC3F_ZERO;
				}

			}

			if (rfrA > 0.f)														// Si l'objet refracte
			{
				std::vector<std::vector<Intersection>> intersectionsRefraction;


				Ray refractedRay(
					hitpoint._position,	glm::normalize(glm::refract(ray.getDirection(),	normale,	// Calcul du rayon r�fract� entre la normale �
					refractionIndex)));																// la position et le rayon primaire

				for (AObject3D *o : _objects)														// Ici on va tester les intersections entre le
																									// rayon refract� et tous les objets de la sc�ne
				{
					intersectionsRefraction.push_back(o->intersect(refractedRay));
				}

				// for (BVHNode *b : _bvh)																// Pareil pour les BVH
				// {
				// 	intersectionsRefraction.push_back(b->intersect(refractedRay, b).intersect(refractedRay));
				// }


				bool rfrRayHasIntersected = false;
				Intersection closestRefractIntersection;

				for (std::vector<Intersection> i : intersectionsRefraction)					// Recherche de l'intersection la plus proche entre le rayon																			
				{																			// r�fract� et les objets de la sc�ne, si elle existe
					if (!i.empty())
					{
						rfrRayHasIntersected = true;
						for (Intersection j : i)
							if (closestRefractIntersection._distance == -1.f
								|| j._distance
									   < closestRefractIntersection._distance)
								closestRefractIntersection = j;
						;
					}
				}
																							// Si on a une intersection de r�fraction, on va
																							// r�effectuer un calcul de couleur avec cette
																							// fois-ci comme rayon primaire
				if (rfrRayHasIntersected)													// le rayon r�fract� et l' intersection de r�fraction									  

				{
					refrColor += getColor(refractedRay, closestRefractIntersection,	loop);	// on obtient r�cursivement la couleur de r�fraction
				}
				else
				{
					refrColor += VEC3F_ZERO;
				}
			}

			//printf("%f %f %f \n", refrColor.x,refrColor.y, refrColor.z);
		
			Vec3f albedo = currentObject->getColorMaterial()->shade(ray, hitpoint);      //Albedo de l'objet

			Vec3f color = VEC3F_ZERO;
			Vec3f specular = VEC3F_ZERO;

			for (Light *light : _lights)												//Ici, on va calculer la couleur de l'objet � l'aide de la
			{																			//BRDF et des diff�rentes lumi�res de la sc�ne
				Vec3f lightVector = light->getPosition() - hitpoint._position;

				Vec3f normalizedLightVector = glm::normalize(lightVector);				//Vecteur lumi�re normalis�

				Vec3f normalizedViewVector												//Vecteur de vue normalis�
					= glm::normalize(_camera.getPosition() - hitpoint._position);

				float lightIntensity = light->getIntensity(length(lightVector));		//Intensit� de la lumi�re au point

				Vec3f diffuse = albedo / (float)M_PI;									//Couleur diffuse


				float cosine
					= fmaxf(0.f, glm::dot(normalizedLightVector, normale));				//Cosine entre le vecteur de lumi�re et la normale

				float currentObjectRugosity = currentObject->getRugosity();				//Rugosit� de l'objet

				Vec3f f0 = currentObject->getf0();										//Coefficient de fresnel de l'objet

				Vec3f fresnelDiff = _brdf.fresnelTerm(									//Terme de fresnel diffus
					f0, cosine);

				specular
					= _brdf.brdfTerm(normalizedLightVector, normalizedViewVector,		//Couleur sp�culaire de l'objet 
									 normale, currentObjectRugosity, f0);

		
				color += lightIntensity * cosine										//On combine les couleurs sp�culaires, diffuses et 
						 * glm::mix(diffuse,  specular + albedo, fresnelDiff);			//l'alb�do pour cette lumi�re

			}

			Vec3f finalColor;															//calcul de la couleur finale
			finalColor.x																//on combine la couleur de l'objet, celle de la r�fraction 
				= glm::min(rfrA * refrColor.x + rflA * rflColor.x + color.x, 1.0f);		//et de la r�flection

			finalColor.y
				= glm::min(rfrA * refrColor.y + rflA * rflColor.y + color.y, 1.0f);

			finalColor.z
				= glm::min(rfrA * refrColor.z + rflA * rflColor.z + color.z, 1.0f);

			int shadowed=0;																//On calcule l'ombre de la couleur finale
			for (Light* light : _lights){	
				shadowed += calculateShadow(hitpoint, light, finalColor,
											   currentObject);			
			}
			if (shadowed!=0)
				return finalColor / float(shadowed);

			return finalColor;
			}
		else 
			return Vec3f(0.0f);															
	} 

	/*
	 * Setters
	 */

	void LightMaterial::setObjects(std::vector<AObject3D *> &objects)
	{
		_objects = objects;
	}

	// void LightMaterial::setBVH(std::vector<BVHNode *> &bvh)
	// {
	// 	_bvh = bvh;
	// }


} // namespace ISICG_ISIR