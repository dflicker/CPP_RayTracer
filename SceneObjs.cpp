#include "SceneObjs.hpp"

SceneObject::SceneObject() : surface_color(0.5, 0.5, 0.5) { }
SceneObject::SceneObject(RGB surf_color, float reflect) 
  : surface_color(surf_color), reflectivity(reflect) { }
const RGB SceneObject::getSurfaceColor() const {
    return surface_color;
}
const float SceneObject::getReflectivity() const {
    return reflectivity;
}
void SceneObject::setSurfaceColor(const RGB new_color) {
    surface_color = new_color;
}
const RGB SceneObject::pointColor(const Vector3D &surface_point) const {
    return surface_color;
}
SceneObject::~SceneObject() { }

Plane::Plane(float dist, const Vector3D& surf_norm, const RGB& surf_color, float reflect) : 
    SceneObject(surf_color, reflect), distance(dist), surface_normal(surf_norm) { }
float Plane::getDistance() const {
    return distance;
}
const Vector3D Plane::getSurfaceNormal() const {
    return surface_normal;
}
float Plane::intersection(const Ray &r) const {
    float DdotN = r.getDirection() * surface_normal;
    if (DdotN == 0) {
	return NO_INTERSECTION;
    } else {
	float t = -(r.getOrigin() * surface_normal + distance) / DdotN;
	t = t >= 0 ? t : NO_INTERSECTION;
	return t;
    }
}
Vector3D Plane::surfaceNormal(const Vector3D& point) const {
    return surface_normal;
}

std::istream& operator>>(std::istream &in, Plane &pl) {
    Vector3D surf_norm;
    float dist;
    RGB col;
    float reflect;
    in >> surf_norm >> dist >> col >> reflect;
    pl.distance = dist;
    pl.surface_normal = surf_norm;
    pl.surface_color = col;
    pl.reflectivity = reflect;
    return in;
}


int Sphere::getIntersection(const Ray &r, float &t1, float &t2) const {
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
Sphere::Sphere(const Vector3D& center, float r, const RGB& color, 
	       float reflect) : 
    SceneObject(color, reflect), center(center), radius(r) {
    assert(radius >= 0);
}
const Vector3D Sphere::getCenter() const {
    return center;
}
float Sphere::getRadius() const {
    return radius;
}
float Sphere::intersection(const Ray &r) const {
    float t1, t2;
    getIntersection(r, t1, t2);
    return t1;
}
Vector3D Sphere::surfaceNormal(const Vector3D& point) const {
    Vector3D res = point - center;
    res.normalize();
    return res;
}

std::istream& operator>>(std::istream &in, Sphere &s) {
    Vector3D center;
    float r;
    RGB col;
    float reflect;
    in >> center >> r >> col >> reflect;
    s.center = center;
    s.radius = r;
    s.surface_color = col;
    s.reflectivity = reflect;
    return in;
}

Cylinder::Cylinder(const Vector3D& center, const Vector3D& orient, 
	 float r, float h, const RGB& color, float reflect) : 
    SceneObject(color, reflect), pos(center), orientation(orient), radius(r), height(h) {
    assert(radius >= 0);
    orientation.normalize();
}
float Cylinder::intersection(const Ray &r) const {
    Vector3D Cpar = pos.projectOnto(orientation);
    Vector3D Cperp = pos - Cpar;
    Vector3D Ppar = r.getOrigin().projectOnto(orientation);
    Vector3D Pperp = r.getOrigin() - Ppar;
    
    assert(r.getDirection().magSquared() - 1 < .1 || r.getDirection().magSquared() - 1 > -.1);
    Vector3D Dpar = r.getDirection().projectOnto(orientation);
    Vector3D Dperp = r.getDirection() - Dpar;
    
    Ray sphere_ray(Pperp, Dperp, false);
    Sphere equiv_sphere(Cperp, radius);
    float t1;
    float t2;
    int num_points = equiv_sphere.getIntersection(sphere_ray, t1, t2);
    if (num_points > 0) {
	Vector3D test_vec = Ppar + Dpar * t1 - Cpar;
	if (test_vec.mag() < height / 2)
	    return t1;
    }
    if (num_points > 1) {
	assert(t2 != NO_INTERSECTION);
	Vector3D test_vec = Ppar + Dpar * t2 - Cpar;
	if (test_vec.mag() < height / 2)
	    return t2;
    }
    return NO_INTERSECTION;
}
Vector3D Cylinder::surfaceNormal(const Vector3D& point) const {
    Vector3D V = point - pos;
    Vector3D Vperp = V - V.projectOnto(orientation);
    Vperp.normalize();
    assert(Vperp.magSquared() - 1 < .1 || Vperp.magSquared() - 1 > -.1);
    return Vperp;
}

std::istream& operator>>(std::istream &in, Cylinder &c) {
    Vector3D center;
    Vector3D orient;
    float r;
    float h;
    RGB col;
    float reflect;
    in >> center >> orient >> r >> h >> col >> reflect;
    c.pos = center;
    c.orientation = orient;
    c.orientation.normalize();
    c.radius = r;
    c.height = h;
    c.surface_color = col;
    c.reflectivity = reflect;
    return in;
}
