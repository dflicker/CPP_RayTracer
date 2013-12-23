#include "vector.hpp"
#include "rgb.hpp"
#include "ray.hpp"
#include "SceneObjs.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "light.hpp"
#include <iostream>

int main(int argc, char **argv) {
    Scene scene;
    Plane *p1 = new Plane(0, Vector3D(0, 1, 0), RGB(0.5, 0, 0.5));
    scene.addObject(p1);
    Sphere *s1 = new Sphere(Vector3D(-1.2, 1, 0), 0.5, RGB(1, 0, 0));
    Sphere *s2 = new Sphere(Vector3D(0, 0.5, 0), 0.5, RGB(0, 1, 0));
    Sphere *s3 = new Sphere(Vector3D(1.2, 0.5, 0), 0.5, RGB(0, 0, 1));
    scene.addObject(s1);
    scene.addObject(s2);
    scene.addObject(s3);
    Light *l1 = new Light(Vector3D(-10, 10, 5), RGB(0.8, 0.8, 0.8));
    Light *l2 = new Light(Vector3D(5, 3, 5), RGB(0.3, 0.3, 0.3));
    scene.addLight(l1);
    scene.addLight(l2);
    Camera cam(Vector3D(-1.5, 1, 3), Vector3D(-0.3, 0.5, 0), Vector3D(0, 1, 0));
    scene.render(cam, 600, std::cout);
    return 0;
}
