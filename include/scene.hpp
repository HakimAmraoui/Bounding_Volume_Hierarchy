#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H
#include "light.hpp"
#include "camera.hpp"
#include "solid.hpp"
#include "image.hpp"
#include "ray.hpp"
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
namespace Raytracing{
    struct RayHit{
        float distanceFromOrigin;
        int solidHitIndex;
    };

    class Scene{
        public:
            Image image;

            Camera camera;
            Vector3 skyColor = Vector3(.7,.7,.8);
            vector<std::unique_ptr<Solid>> solids;// ce type bizarre est là parce que
            // si je mettais juste `Solid` y'aurait pas de polymorphisme
            // si je mettais un pointeur, il faudrait gérer la mémoire soit même et ce serait relou.

            vector<std::unique_ptr<Light>> lights;// ce type bizarre est là pour
            // les mêmes raisons que solids.
            

            Scene(Camera camera = Camera());
            void renderImage();
            void renderImageDefocus(int samplePerPixel);
            
            
        private:
            /* Returns the ray hit distance from ray origin & the solid it hit.
            */
            RayHit castRay(Ray const &ray);
            Vector3 computeColor(Ray const &ray, int bounceCounter);
    };
}

#endif
