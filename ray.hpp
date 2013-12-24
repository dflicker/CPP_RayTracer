#ifndef __RAY_HPP_
#define __RAY_HPP_

#include "vector.hpp"
#include <cassert>

class Ray {
private:
    Vector3D origin;
    Vector3D direction;

public:
    Ray(const Vector3D &orig, const Vector3D &dir, bool normalize = true) : 
	origin(orig), direction(dir) {if (normalize) direction.normalize();}
    const Vector3D getOrigin() const {return origin;}
    const Vector3D getDirection() const {return direction;}
    const Vector3D getPointAtT(float t) const {
	assert(t >= 0);
	return origin + direction * t;
    }
    const Ray reflect(const Vector3D &pos, const Vector3D &normal, float delta = 0.00001) const {
	Vector3D Dpar = (-direction).projectOnto(normal);
	Vector3D Dr = direction + 2 * Dpar;
	return Ray(pos + Dr * delta, Dr);
    }
};


#endif // __RAY_HPP_
