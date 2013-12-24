#include "vector.hpp"
#include "rgb.hpp"
#include "ray.hpp"
#include "SceneObjs.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "SceneReader.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <istream>

typedef std::shared_ptr<Plane> SPPlane;
typedef std::shared_ptr<Sphere> SPSphere;
typedef std::shared_ptr<Light> SPLight;

int main(int argc, char **argv) {
    bool use_file = false;
    std::string flag;
    std::string filename;
    int imgSize = atoi(argv[1]);
    if (argc == 4) {
	flag = std::string(argv[2]);
	if (flag != "-f") {
	    std::cout << "Usage: " << argv[0] << " [-f filename]" << std::endl;
	    return 1;
	}
	filename = std::string(argv[3]);
	use_file = true;
    }
    Scene scene;
    Camera cam(Vector3D(-1.5, 1, 3), Vector3D(-0.3, 0.5, 0), Vector3D(0, 1, 0));
    SceneReader reader;
    if (use_file) {
	std::ifstream f(filename.c_str());
	reader.readScene(f, cam, scene);
    }
    else
	reader.readScene(std::cin, cam, scene);
    scene.render(cam, imgSize, std::cout);
    return 0;
}
