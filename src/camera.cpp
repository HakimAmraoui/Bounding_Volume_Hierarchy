#include "camera.hpp"
#include "stdio.h"
#define PI 3.141592

namespace Raytracing{
    Camera::Camera(Vector3 origin, Vector3 target){
        this->origin = origin;
        this->target = target;
        this->up = Vector3(0,0,1);
        this->apertureSize = 5;
        this->focalScreenSize = 4;
        this->focalLength = 1;
    }

    Ray Camera::pixelToRay(int pixelX, int pixelY, int width, int height) const{
        Vector3 z = target - origin;
        z.normalize();
        Vector3 x = z.vectorProduct(this->up);
        x.normalize();
        Vector3 y = z.vectorProduct(x); // y est déjà normalisé.
        Vector3 toReturn = z * this->focalLength + x *(pixelX - width/2)/width + y*(pixelY - height/2)/width;

        toReturn.normalize();
        return Ray(this->origin, toReturn);
    }

    Ray Camera::pixelToRayDefocus(int pixelX, int pixelY, int width, int height) const{
        Vector3 z = target - this->origin;
        z.normalize();
        Vector3 x = z.vectorProduct(this->up);
        x.normalize();
        Vector3 y = z.vectorProduct(x); // y est déjà normalisé.
        float centeredX = float(pixelX - width/2)/(height/2);
        float centeredY = float(pixelY - height/2)/(height/2);

        Vector3 rayOrigin = this->origin;
        float angle = (float(rand())/float((RAND_MAX)) * PI * 2);
        float length = float(rand())/float(RAND_MAX);
        length = (1-length*length)*apertureSize;
        rayOrigin = rayOrigin + x*sinf(angle)*length + y*cosf(angle)*length;
        
        Vector3 pixelTarget = target;
        pixelTarget = pixelTarget + x*centeredX*this->focalScreenSize
         + y*centeredY*this->focalScreenSize;
        //std::cout << (pixelTarget-target).length() << std::endl;
        Vector3 direction = pixelTarget - rayOrigin;
        direction.normalize();
        // std::cout<< (rayOrigin-this->origin).length()/apertureSize<<std::endl;
        //std::cout<< centeredX<<std::endl;
        // std::cout<< (pixelTarget-target).length()/this->focalScreenSize<<std::endl;
        return Ray(rayOrigin, direction);
    }

}
