#include "vector.hpp"
#include "rgb.hpp"
#include "ray.hpp"
#include "SceneObjs.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "light.hpp"
#include <iostream>
#include <memory>

typedef std::shared_ptr<Plane> SPPlane;
typedef std::shared_ptr<Sphere> SPSphere;
typedef std::shared_ptr<Light> SPLight;

int main(int argc, char **argv) {
    Scene scene;
    SPPlane p1 = SPPlane(new Plane(0, Vector3D(0, 1, 0), RGB(0.5, 0, 0.5)));
    scene.addObject(p1);
    SPSphere s1 = SPSphere(new Sphere(Vector3D(-1.2, 1, 0), 0.5, RGB(1, 0, 0)));
    SPSphere s2 = SPSphere(new Sphere(Vector3D(0, 0.5, 0), 0.5, RGB(0, 1, 0)));
    SPSphere s3 = SPSphere(new Sphere(Vector3D(1.2, 0.5, 0), 0.5, RGB(0, 0, 1)));
    scene.addObject(s1);
    scene.addObject(s2);
    scene.addObject(s3);
    SPLight l1 = SPLight(new Light(Vector3D(-10, 10, 5), RGB(0.8, 0.8, 0.8)));
    SPLight l2 = SPLight(new Light(Vector3D(5, 3, 5), RGB(0.3, 0.3, 0.3)));
    scene.addLight(l1);
    scene.addLight(l2);
    Camera cam(Vector3D(-1.5, 1, 3), Vector3D(-0.3, 0.5, 0), Vector3D(0, 1, 0));
    scene.render(cam, 600, std::cout);
    return 0;
}
