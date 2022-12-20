#include "scene.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "point_light.hpp"
using namespace Raytracing;
int main(){

    // Scene s;
    // s.image.width = 1920;
    // s.image.height = 1080;
    // s.camera.origin = Vector3(0,-3,.7);
    // s.camera.target = Vector3(0,5,.3);
    // unique_ptr<Sphere> greenSphere = make_unique<Sphere>(Vector3(0,5,.5));
    // unique_ptr<Sphere> redSphere = make_unique<Sphere>(Vector3(-1.5,8.5,-.6));
    // unique_ptr<Sphere> mirrorSphere = make_unique<Sphere>(Vector3(-1.5,5,.3));
    // unique_ptr<Plane> floor = make_unique<Plane>(Vector3(0,0,-.7));
    // floor->material.metallic = true;
    // floor->material.color = Vector3(0.9);
    // cout<<floor->material.color<<endl;
    // greenSphere->radius = 1;
    // greenSphere->material.color = Vector3(.7,1.0,.7);
    // redSphere->radius = 3;
    // redSphere->material.color = Vector3(1.,0.3,0.3);
    // mirrorSphere->radius = .4;
    // mirrorSphere->material.metallic = true;
    // mirrorSphere->material.color = Vector3(.9,.9,.9);
    // unique_ptr<Point_light> whiteLight = make_unique<Point_light>(Vector3(3,4,3));
    // unique_ptr<Point_light> redLight = make_unique<Point_light>(Vector3(-3,2,.5
    // ));
    // redLight->color = Vector3(.5,0.5,0.0);

    // s.solids.push_back(std::move(greenSphere));
    // s.solids.push_back(std::move(redSphere));
    // s.solids.push_back(std::move(mirrorSphere));
    // s.solids.push_back(std::move(floor));
    // s.lights.push_back(std::move(whiteLight));
    // s.lights.push_back(std::move(redLight));
    // // s.renderImageDefocus(500);
    // s.renderImage();
    // s.image.saveImage("test.png");



    // Scene with aligned spheres

    Scene s;
    s.image.width = 1920;
    s.image.height = 1080;
    s.camera.origin = Vector3(0,-3,.7);
    s.camera.target = Vector3(0,5,.3);
    unique_ptr<Sphere> greenSphere = make_unique<Sphere>(Vector3(0,10,1));
    unique_ptr<Sphere> redSphere = make_unique<Sphere>(Vector3(4,10,1));
    unique_ptr<Sphere> mirrorSphere = make_unique<Sphere>(Vector3(-4,10,1));
    unique_ptr<Plane> floor = make_unique<Plane>(Vector3(0,0,-.7));
    floor->material.metallic = true;
    floor->material.color = Vector3(0.9);
    cout<<floor->material.color<<endl;
    greenSphere->radius = 1.5;
    greenSphere->material.color = Vector3(.7,1.0,.7);
    redSphere->radius = 1.5;
    redSphere->material.color = Vector3(1.,0.3,0.3);
    mirrorSphere->radius = 1.5;
    mirrorSphere->material.metallic = true;
    mirrorSphere->material.color = Vector3(.9,.9,.9);
    unique_ptr<Point_light> whiteLight = make_unique<Point_light>(Vector3(3,4,3));
    unique_ptr<Point_light> redLight = make_unique<Point_light>(Vector3(-3,2,.5
    ));
    redLight->color = Vector3(.5,0.5,0.0);

    s.solids.push_back(std::move(greenSphere));
    s.solids.push_back(std::move(redSphere));
    s.solids.push_back(std::move(mirrorSphere));
    s.solids.push_back(std::move(floor));
    s.lights.push_back(std::move(whiteLight));
    s.lights.push_back(std::move(redLight));
    // s.renderImageDefocus(500);
    s.renderImage();
    s.image.saveImage("test.png");


    return 0;
}
