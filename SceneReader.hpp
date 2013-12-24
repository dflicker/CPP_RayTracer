#ifndef __SCENEREADER_HPP_
#define __SCENEREADER_HPP_

#include <istream>
#include "rgb.hpp"
#include "vector.hpp"
#include "SceneObjs.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "scene.hpp"
#include <string>
#include <sstream>
#include <map>

typedef std::shared_ptr<SceneObject> SPSceneObject;
typedef std::shared_ptr<Plane> SPPlane;
typedef std::shared_ptr<Sphere> SPSphere;
typedef std::shared_ptr<Cylinder> SPCylinder;
typedef std::shared_ptr<Light> SPLight;
typedef std::shared_ptr<Camera> SPCamera;
// Define a type for functions that take an input-stream, and construct a
// SceneObject from them.  (Don't forget the * even though it isn't strictly
// required by the C++ syntax for function pointers!  If you leave it out,
// the g++ STL implementation gets very crabby.)
typedef SPSceneObject (*SceneObjectReader)(std::istream &in);

class SceneReader {
private:
    std::map<std::string, SceneObjectReader> readFuncs;
public:
    SceneReader();
    bool readScene(std::istream &in, Camera& cam, Scene& scene);
};


#endif // _SCENEREADER_HPP_
