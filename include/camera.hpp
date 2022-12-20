#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H
#include <cmath>
#include "vector3.hpp"
#include "ray.hpp"
namespace Raytracing{
    class Camera{
        public:
            Vector3 origin;
            Vector3 target;
            Vector3 up;
            float apertureSize;
            float focalScreenSize;



            // float alpha;
            // float beta;
            // float zMin;
            float focalLength;

            Camera(Vector3 center = Vector3(), Vector3 target = Vector3(0,1,0));

            Ray pixelToRay(int pixelX, int pixelY, int width, int height) const;
            Ray pixelToRayDefocus(int pixelX, int pixelY, int width, int height) const;
    };
}

#endif
