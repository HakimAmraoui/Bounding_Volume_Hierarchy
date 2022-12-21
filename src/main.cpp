#include "scene.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "point_light.hpp"
#include "chrono.hpp"

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



    // Scene
    Scene s;
    s.image.width = 1920;
    s.image.height = 1080;

    // Camera
    s.camera.origin = Vector3(0,-3,.7);
    s.camera.target = Vector3(0,5,.3);

    // Lights
    unique_ptr<Point_light> whiteLight = make_unique<Point_light>(Vector3(3,4,3));
    unique_ptr<Point_light> redLight = make_unique<Point_light>(Vector3(-3,2,.5
    ));
    redLight->color = Vector3(.5,0.5,0.0);


    // Floor
    unique_ptr<Plane> floor = make_unique<Plane>(Vector3(0,0,-.7));
    floor->material.metallic = true;
    floor->material.color = Vector3(0.9);
    // cout<<floor->material.color<<endl;


    // Spheres
    unique_ptr<Sphere> sphere1 = make_unique<Sphere>(Vector3(0,15,1));
    unique_ptr<Sphere> sphere2 = make_unique<Sphere>(Vector3(4,15,1));
    unique_ptr<Sphere> sphere3 = make_unique<Sphere>(Vector3(-4,15,1));
    unique_ptr<Sphere> sphere4 = make_unique<Sphere>(Vector3(0,15,4));
    unique_ptr<Sphere> sphere5 = make_unique<Sphere>(Vector3(4,15,4));
    unique_ptr<Sphere> sphere6 = make_unique<Sphere>(Vector3(-4,15,4));

    sphere1->radius = 1.5;
    sphere1->material.color = Vector3(.7,1.0,.7);

    sphere2->radius = 1.5;
    sphere2->material.color = Vector3(1.,0.3,0.3);

    sphere3->radius = 1.5;
    sphere3->material.metallic = true;
    sphere3->material.color = Vector3(.9,.9,.9);

    sphere4->radius = 1.5;
    sphere4->material.metallic = true;
    sphere4->material.color = Vector3(.7,1.0,.7);

    sphere5->radius = 1.5;
    sphere5->material.metallic = true;
    sphere5->material.color = Vector3(1.,0.3,0.3);

    sphere6->radius = 1.5;
    sphere6->material.metallic = true;
    sphere6->material.color = Vector3(.9,.9,.9);






    s.solids.push_back(std::move(sphere1));
    s.solids.push_back(std::move(sphere2));
    s.solids.push_back(std::move(sphere3));
    s.solids.push_back(std::move(sphere4));
    s.solids.push_back(std::move(sphere5));
    s.solids.push_back(std::move(sphere6));
    s.solids.push_back(std::move(floor));
    s.lights.push_back(std::move(whiteLight));
    s.lights.push_back(std::move(redLight));



    // Rendering
    Chrono chrono;
    chrono.start();
    s.renderImage();
    // s.renderImageDefocus(500);
    s.image.saveImage("test.png");
    chrono.stop();
    cout << "Time to render image: " << chrono.elapsedTime() << endl;


    return 0;
}
