#include "scene.hpp"

struct closest_object : public std::unary_function<SPSceneObject, void> {
    float closest_time;
    SPSceneObject closest_obj;
    Ray r;
    closest_object(const Ray& ray) : closest_time(std::numeric_limits<float>::max()),
				     closest_obj(0),
				     r(ray) { }
    void operator()(SPSceneObject obj) {
	float t = obj->intersection(r);
	if (NO_INTERSECTION != t && t < closest_time) {
	    closest_time = t;
	    closest_obj = obj;
	}
    }
};

SPSceneObject Scene::findClosestObject(const Ray &r, float &tIntersect) const {
    closest_object result = std::for_each(objects.begin(), objects.end(),
					  closest_object(r));
    tIntersect = result.closest_time;
    return result.closest_obj;
}

Scene::Scene() : lights(0), objects(0) { }

Scene::~Scene() { }

void Scene::addObject(SPSceneObject obj) {
    assert(obj != 0);
    objects.push_back(obj);
}

void Scene::addLight(SPLight light) {
    assert(light != 0);
    lights.push_back(light);
}

const RGB Scene::traceRay(const Ray& r, int depth) const {
    float closest_time;
    SPSceneObject closest_obj = findClosestObject(r, closest_time);
    if (closest_time == std::numeric_limits<float>::max()) {
	assert(closest_obj == 0);
    }
    if (closest_obj == 0) {
	return RGB(0, 0, 0);
    }
    Vector3D location = r.getPointAtT(closest_time);
    RGB pixel_color(0, 0, 0);
    for (std::vector<SPLight>::const_iterator it = lights.begin(); 
	 it != lights.end(); 
	 ++it) {
	Vector3D L = (*it)->getPosition() - location;
	L.normalize();
	Vector3D N = closest_obj->surfaceNormal(location);
	pixel_color += (*it)->getColor() * closest_obj->pointColor(location) 
		* fmaxf(N * L, 0);
    }
    if (depth < MAX_REFLECT_DEPTH && closest_obj->getReflectivity() > 0) {
	Ray reflected_ray = r.reflect(location, closest_obj->surfaceNormal(location));
	RGB reflection_color = traceRay(reflected_ray, depth + 1);
	pixel_color += closest_obj->getReflectivity() * reflection_color;
    }
    return pixel_color;
}

void Scene::render(const Camera& cam, int imgSize, std::ostream& out) {
    out << "P3 " << imgSize << " " << imgSize << " 255" << std::endl;
    for (int y = 0; y < imgSize; y++) {
	for (int x = 0; x < imgSize; x++) {
	    Ray pixelRay = cam.getRayForPixel(x, y, imgSize);
	    RGB pixelColor = traceRay(pixelRay);
	    pixelColor *= 255;
	    pixelColor.clamp(0, 255);
	    out << (int) pixelColor.getRed() << " " << (int) pixelColor.getGreen() << 
		" " << (int) pixelColor.getBlue() << std::endl;
	}
    }
}
