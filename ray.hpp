#ifndef __RAY_HPP_
#define __RAY_HPP_

#include "vector.hpp"
#include <cassert>

class Ray {
private:
    Vector3D origin;
    Vector3D direction;

public:
    Ray(const Vector3D &orig, const Vector3D &dir, bool normalize = true);
    const Vector3D getOrigin() const;
    const Vector3D getDirection() const;
    const Vector3D getPointAtT(float t) const;
    const Ray reflect(const Vector3D &pos, const Vector3D &normal, 
		      float delta = 0.00001) const;
};


#endif // __RAY_HPP_
