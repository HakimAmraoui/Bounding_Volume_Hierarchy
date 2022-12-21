#ifndef RAYTRACING_
#define RAYTRACING_

#include "intersection.hpp"
#include "../ray.hpp"

namespace Raytracing
{
	/*
	 * Classe m�re repr�sentant les mat�riaux
	 */

	class AMaterial
	{
	public:

		//Fonction permettant de r�cup�rer la couleur de l'objet intersect�
		//� la position pos
		virtual Vec3f shade(const Ray &ray, const Intersection &pos) = 0;

	protected:



	};
} 

#endif 