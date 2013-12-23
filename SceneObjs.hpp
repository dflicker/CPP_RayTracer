#ifndef __SCENEOBJS_HPP_
#define __SCENEOBJS_HPP_
#include "rgb.hpp"
#include <cmath>

const static float NO_INTERSECTION = -1;

class SceneObject {
private:
    RGB surface_color;
    
public:
    SceneObject() : surface_color(0.5, 0.5, 0.5) { }
    SceneObject(RGB surf_color) : surface_color(surf_color) { }
    const RGB getSurfaceColor() const {return surface_color;}
    void setSurfaceColor(const RGB new_color) {surface_color = new_color;}
    virtual float intersection(const Ray &r) const = 0;
    virtual Vector3D surfaceNormal(const Vector3D& point) const = 0;
    const RGB pointColor(const Vector3D &surface_point) const {return surface_color;}
    virtual ~SceneObject() { }
};

class Plane : public SceneObject {
private:
    float distance;
    Vector3D surface_normal;
public:
    Plane(float dist, const Vector3D& surf_norm, const RGB& surf_color) : 
	SceneObject(surf_color), distance(dist), surface_normal(surf_norm) { }
    float getDistance() const {return distance;}
    const Vector3D getSurfaceNormal() const {return surface_normal;}
    float intersection(const Ray &r) const {
	float DdotN = r.getDirection() * surface_normal;
	if (DdotN == 0) {
	    return NO_INTERSECTION;
	} else {
	    float t = -(r.getOrigin() * surface_normal + distance) / DdotN;
	    t = t >= 0 ? t : NO_INTERSECTION;
	    return t;
	}
    }
    Vector3D surfaceNormal(const Vector3D& point) const {return surface_normal;}
};

class Sphere : public SceneObject {
private:
    Vector3D center;
    float radius;
    int getIntersection(const Ray &r, float &t1, float &t2) const {
	int num_intersects = 0;
	float a = r.getDirection() * r.getDirection();
	float b = 2 * (r.getOrigin() * r.getDirection() - r.getDirection() * center);
	float c = r.getOrigin() * r.getOrigin() + center * center - 
	    2 * (r.getOrigin() * center) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
	    t1 = NO_INTERSECTION;
	    t2 = NO_INTERSECTION;
	    return 0;
	}
	t2 = (-b + sqrtf(discriminant)) / (2 * a);
	t1 = (discriminant > 0) ? (-b - sqrtf(discriminant)) / (2 * a) : NO_INTERSECTION;
	t1 = (t1 >= 0) ? t1 : NO_INTERSECTION;
	if (t1 >= 0) num_intersects++;
	t2 = (t2 >= 0) ? t2 : NO_INTERSECTION;
	if (t2 >= 0) num_intersects++;
	return num_intersects;
    }
	
	    
public:
    Sphere(const Vector3D& center, float r, const RGB& color) : 
	SceneObject(color), center(center), radius(r) {assert(radius >= 0);}
    const Vector3D getCenter() const {return center;}
    float getRadius() const {return radius;}
    float intersection(const Ray &r) const {
	float t1, t2;
	getIntersection(r, t1, t2);
	return t1;
    }
    Vector3D surfaceNormal(const Vector3D& point) const {
	Vector3D res = point - center;
	res.normalize();
	return res;
    }
};

#endif // __SCENEOBJS_HPP_
