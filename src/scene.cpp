#include "scene.hpp"
#include "omp.h"
#define epsilon .005
#define bounceLimit 10
namespace Raytracing{
    Scene::Scene(Camera c){
        this->camera = c;
        this->lights = vector<std::unique_ptr<Light>>(0); 
        this->solids = vector<std::unique_ptr<Solid>>(0);
    }
    

    RayHit Scene::castRay(Ray const &ray){
        RayHit toRet;
        
        toRet.solidHitIndex = -1;
        toRet.distanceFromOrigin = 1./0.;
        for (int solidIdx = 0; solidIdx < solids.size(); solidIdx += 1){
            float distance = solids[solidIdx]->intersect(ray);
            if (toRet.distanceFromOrigin > distance && 0 < distance){
                toRet.distanceFromOrigin = distance;
                toRet.solidHitIndex = solidIdx;
            }
        }
        return toRet;
    }
    Vector3 Scene::computeColor(Ray const &ray, int bounceCounter){
        RayHit rh = this->castRay(ray);
        if (rh.solidHitIndex < 0){
            return skyColor;
        }
        Vector3 intersection = ray.direction * rh.distanceFromOrigin + ray.origin;
        Vector3 col = solids[rh.solidHitIndex]->get_color_at(intersection);
        Vector3 surfaceNormal = solids[rh.solidHitIndex]->normal(intersection);
        Vector3 illumination = Vector3(0.0,0.0,0.0);
        if (solids[rh.solidHitIndex]->material.metallic && bounceCounter < bounceLimit){
            Vector3 direction;
            direction = ray.direction.reflected_along(solids[rh.solidHitIndex]->normal(intersection));;
            Ray reflectedRay(intersection + direction * epsilon, direction);
            return col.dimensionWiseProduct(computeColor(reflectedRay, bounceCounter + 1));
        }else{
            for (int lightIdx = 0; lightIdx < this->lights.size(); lightIdx += 1){

                Ray toCast = Ray(intersection + surfaceNormal*epsilon,
                    lights[lightIdx]->get_direction(intersection + surfaceNormal));
                RayHit lightRayHit = this->castRay(toCast);
                // printf("light bounce hit :%i at %f with offset ", lightRayHit.solidHitIndex, lightRayHit.distanceFromOrigin);
                // std::cout<<surfaceNormal<<" & direction "<<toCast.direction<<
                // " @ position" << toCast.origin<<std::endl;
                if (lightRayHit.distanceFromOrigin > lights[lightIdx]->get_minimum_dist(intersection) || 
                    lightRayHit.solidHitIndex < 0 ){
                    illumination = illumination + lights[lightIdx]->get_color() * 
                    clamp( toCast.direction.dotProduct(surfaceNormal),
                    0.f,1.f);
                }
            }
        }
        return col.dimensionWiseProduct(illumination);
    }
    void Scene::renderImage(){
#pragma omp parallel for
        for (int y = 0; y < image.height; y+= 1){
            for (int x = 0; x < image.width; x += 1){
                this->image.setPixel(y, x,
                    this->computeColor(
                        camera.pixelToRay(x,y,image.width, image.height), 3 
                ));
            }
        }
    }
    void Scene::renderImageDefocus(int samplePerPixel){
#pragma omp parallel for
        for (int y = 0; y < image.height; y+= 1){
            for (int x = 0; x < image.width; x += 1){
                Vector3 pixelCol = Vector3(0);
                for (int s = 0; s < samplePerPixel; s += 1){
                    // cout<<computeColor(
                    //     camera.pixelToRayDefocus(x,y,image.width, image.height), 3 
                    // )<<endl;
                    pixelCol = pixelCol +  this->computeColor(
                        camera.pixelToRayDefocus(x,y,image.width, image.height), 3 
                    );
                }
                this->image.setPixel(y, x, pixelCol/samplePerPixel);
            }
        }
    }
}

