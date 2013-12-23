#ifndef __SCENE_HPP_
#define __SCENE_HPP_

#include "light.hpp"
#include "SceneObjs.hpp"
#include <vector>
#include <algorithm>

struct DeleteFromVector {
    template <class T>
    void operator() (T *ptr) const {
	delete ptr;
    }
};

class Scene {
private:
    std::vector<Light *> lights;
    std::vector<SceneObject *> objects;
public:
    Scene() : lights(1), objects(1) { }
    void addObject(SceneObject *obj) {
	assert(obj != 0);
	objects.push_back(obj);
    }
    void addLight(Light *light) {
	assert(light != 0);
	lights.push_back(light);
    }
    ~Scene() {
	std::for_each(lights.begin(), lights.end(), DeleteFromVector());
	std::for_each(objects.begin(), objects.end(), DeleteFromVector());
    }
};

#endif // __SCENE_HPP_
