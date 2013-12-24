#ifndef __SCENE_HPP_
#define __SCENE_HPP_

#include "light.hpp"
#include "SceneObjs.hpp"
#include "camera.hpp"
#include "rgb.hpp"
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <ostream>
#include <iostream>
#include <memory>
#include <istream>
#include <sstream>

const static int MAX_REFLECT_DEPTH = 10;

typedef std::shared_ptr<SceneObject> SPSceneObject;
typedef std::shared_ptr<Light> SPLight;

class Scene {
private:
    std::vector<SPLight> lights;
    std::vector<SPSceneObject> objects;
    SPSceneObject findClosestObject(const Ray &r, float &tIntersect) const;
public:
    Scene();
    ~Scene();
    void addObject(SPSceneObject obj);
    void addLight(SPLight light);
    const RGB traceRay(const Ray& r, int depth = 0) const;
    void render(const Camera& cam, int imgSize, std::ostream& out);
};

#endif // __SCENE_HPP_
