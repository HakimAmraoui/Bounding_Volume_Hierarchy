#ifndef RAYTRACING_IMAGE_H
#define RAYTRACING_IMAGE_H
#include <string>
#include <algorithm> // clamp
#include "vector3.hpp"
#include "stb_image_write.h"
namespace Raytracing{
    class Image{
        public:
            int width;
            int height;
            
            Vector3 **pixels;

            Image(int width = 1920, int height = 1080);
            ~Image();

            void setPixel(int y, int x, Vector3 color);
            void saveImage(std::string filename);
            
            Image(const Image& i) = delete;
            Image& operator=(const Image& i) = delete;

    };
}
#endif