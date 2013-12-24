#include "SceneReader.hpp"

SPSceneObject ReadPlane(std::istream &in) {
    SPPlane pl(new Plane(0, Vector3D(0, 1, 0), RGB(0.5, 0, 0.5)));
    in >> (*pl);
    return pl;
}
SPSceneObject ReadSphere(std::istream &in) {
    SPSphere s(new Sphere(Vector3D(-1.2, 1, 0), 0.5, RGB(1, 0, 0)));
    in >> (*s);
    return s;
}

SPSceneObject ReadCylinder(std::istream &in) {
    SPCylinder c(new Cylinder(Vector3D(-1.2, 1, 0), Vector3D(0, 1, 0), 1, 1));
    in >> (*c);
    return c;
}

SPLight ReadLight(std::istream &in) {
    SPLight l(new Light(Vector3D(5, 3, 5), RGB(0.3, 0.3, 0.3)));
    in >> (*l);
    return l;
}

SceneReader::SceneReader() {
    readFuncs["plane"] = ReadPlane;
    readFuncs["sphere"] = ReadSphere;
    readFuncs["cylinder"] = ReadCylinder;
}

bool SceneReader::readScene(std::istream &in, Camera& cam, Scene& scene) {
    std::string line;
    while (std::getline(in, line)){
	std::istringstream is(line);
	std::string type;
	is >> type;
	if (readFuncs.find(type) != readFuncs.end()) {
	    SPSceneObject newObj;
	    newObj = readFuncs[type](is);
	    scene.addObject(newObj);
	} else if (type == "light") {
	    SPLight newLight;
	    newLight = ReadLight(is);
	    scene.addLight(newLight);
	} else if (type == "camera") {
	    is >> cam;
	} else if (type == "" || type == "#" || type == "//") {
	    continue;
	} else {
	    return false;
	}
    }
    return true;
}

