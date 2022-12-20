#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "image.hpp"

namespace Raytracing{
    Image::Image(int width, int height){
        this->width = width;
        this->height = height;

        this->pixels = (Vector3 **) malloc(height *sizeof(Vector3*));
        for (int y = 0; y < height; y += 1){
            this->pixels[y] = (Vector3 *) malloc(width * sizeof(Vector3));
        }
    }

    Image::~Image(){
        free(pixels[0]);
        free(pixels);
    }
    void Image::setPixel(int y, int x, Vector3 color){
        this->pixels[y][x] = color;
    }
    void Image::saveImage(std::string filename){
        uint8_t* data = (uint8_t *) malloc(sizeof(uint8_t) * this->width * this->height*3);
        for (int y = 0; y < this->height; y += 1){
            for (int x  = 0; x < this->width; x += 1){
                data[3*(y*width + x)]   = 0xff * std::clamp(pixels[y][x].x, 0.f, 1.f);
                data[3*(y*width + x)+1] = 0xff * std::clamp(pixels[y][x].y, 0.f, 1.f);
                data[3*(y*width + x)+2] = 0xff * std::clamp(pixels[y][x].z, 0.f, 1.f);

            }
        }
        stbi_write_png(filename.c_str(), this->width, this->height, 3, data, width*3);
        free(data);
    }
}