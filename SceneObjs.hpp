#ifndef __SCENEOBJS_HPP_
#define __SCENEOBJS_HPP_
#include "rgb.hpp"
#include "ray.hpp"
#include "vector.hpp"
#include <cmath>
#include <istream>

const static float NO_INTERSECTION = -1;

class SceneObject {
protected:
    RGB surface_color;
    float reflectivity;
    
public:
    SceneObject();
    SceneObject(RGB surf_color, float reflect = 0);
    const RGB getSurfaceColor() const;
    const float getReflectivity() const;
    void setSurfaceColor(const RGB new_color);
    virtual float intersection(const Ray &r) const = 0;
    virtual Vector3D surfaceNormal(const Vector3D& point) const = 0;
    const RGB pointColor(const Vector3D &surface_point) const;
    virtual ~SceneObject();
};

class Plane : public SceneObject {
private:
    float distance;
    Vector3D surface_normal;
public:
    Plane(float dist, const Vector3D& surf_norm, const RGB& surf_color = RGB(1, 1, 1), float reflect = 0);
    float getDistance() const;
    const Vector3D getSurfaceNormal() const;
    float intersection(const Ray &r) const;
    Vector3D surfaceNormal(const Vector3D& point) const;
    friend std::istream& operator>>(std::istream &in, Plane &pl);
};

class Sphere : public SceneObject {
private:
    Vector3D center;
    float radius;
public:
    int getIntersection(const Ray &r, float &t1, float &t2) const;
    Sphere(const Vector3D& center, float r, 
	   const RGB& color = RGB(1, 1, 1), float reflect = 0);
    const Vector3D getCenter() const;
    float getRadius() const;
    float intersection(const Ray &r) const;
    Vector3D surfaceNormal(const Vector3D& point) const;
    friend std::istream& operator>>(std::istream &in, Sphere &s);
};

class Cylinder : public SceneObject {
private:
    Vector3D pos;
    Vector3D orientation;
    float radius;
    float height;
public:
    Cylinder(const Vector3D& center, const Vector3D& orient, float r, float h, const RGB& color = RGB(1, 1, 1), float reflect = 0);
    float intersection(const Ray &r) const;
    Vector3D surfaceNormal(const Vector3D& point) const;

    friend std::istream& operator>>(std::istream &in, Cylinder &c);
};

#endif // __SCENEOBJS_HPP_
