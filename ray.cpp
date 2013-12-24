#include "ray.hpp"

Ray::Ray(const Vector3D &orig, const Vector3D &dir, bool normalize) : 
    origin(orig), direction(dir) {
    if (normalize)
	direction.normalize();
}
const Vector3D Ray::getOrigin() const {
    return origin;
}
const Vector3D Ray::getDirection() const {
    return direction;
}
const Vector3D Ray::getPointAtT(float t) const {
    assert(t >= 0);
    return origin + direction * t;
}
const Ray Ray::reflect(const Vector3D &pos, const Vector3D &normal, 
		       float delta) const {
    Vector3D Dpar = (-direction).projectOnto(normal);
    Vector3D Dr = direction + 2 * Dpar;
    return Ray(pos + Dr * delta, Dr);
}
