// #include "scene.hpp"
// #include "plane.hpp"

#include <cstdio>

#include "../include/chrono.hpp"
#include "../include/camera.hpp"
#include "../include/material/flatColorMaterial.hpp"
#include "../include/image.hpp"
#include "../include/light/point_light.hpp"
#include "../include/light/light.hpp"
#include "../include/sphere.hpp"


#define AIR_INDEX 1.f
#define WATER_INDEX 1.3f
#define GLASS_INDEX 1.5f
#define DIAMOND_INDEX 1.7f


using namespace Raytracing;

    int main(){

        // IMAGE
        const int width = 960;
        const int height = 540;
        ImageJPG image(width, height);

        // CAMERA
		Camera camera(width, height, 1.f);

        // LIGHTS
        Light ambientLight(Vec3f(1.0, 1.0, 1.0), Vec3f(-.5f, 1.5f, 1.f));
		PointLight pointLight(Vec3f(1.0, 1.0, 1.0), Vec3f(.0f, .4f, 0.3f),
							  0.7f);
		PointLight pointLight2(Vec3f(1.0, 1.0, 1.0), Vec3f(-.8f, 5.f, 7.9f),
							   0.002f);
		PointLight pointLight3(Vec3f(1.0, 1.0, 1.0), Vec3f(.8f, 5.f, 7.9f),
							   0.002f);

        std::vector<Light *> lights;
		lights.push_back(&pointLight);

        // ALBEDO COLOR FOR OBJECTS
		FlatColorMaterial sphereColor(Vec3f(1.0, 0.0, 0.0));





        return 0;
}
