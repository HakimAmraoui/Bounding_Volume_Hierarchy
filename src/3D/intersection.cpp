#include "../../include/3D/intersection.hpp"
namespace Raytracing
{
    /*
	 * Constructeur de structure
	 */


	Intersection::Intersection(float distance, const Vec3f &position, const Vec3f &normale,
				 AObject3D *intersectingObject)
	{
		this->_distance = distance;
		this->_position = position;
		this->_normale = normale;
		this->_object = intersectingObject;
	}
}