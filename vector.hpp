#ifndef __VECTOR_HPP_
#define __VECTOR_HPP_

#include <ostream>
#include <istream>
#include <cassert>
#include <cmath>
#include <ios>

class Vector3D {
private:
    // {x, y, z}
    float vals[3];

public:
    Vector3D();
    Vector3D(float x, float y, float z);
    float operator[](int i) const;
    float & operator[](int i);
    Vector3D& operator+=(const Vector3D &v);
    Vector3D& operator-=(const Vector3D &v);

    const Vector3D operator+(const Vector3D &v) const;
    const Vector3D operator-(const Vector3D &v) const;

    Vector3D& operator*=(const float scalar);
	
    Vector3D& operator/=(const float scalar);
	
    const Vector3D operator*(const float scalar) const;
    const Vector3D operator/(const float scalar) const;
	
    const Vector3D operator-() const;

    const float operator*(const Vector3D &vec) const;

    const float dot(const Vector3D &vec) const;
	
    const Vector3D cross(const Vector3D &vec) const;
    const float magSquared() const;
	
    const float mag() const;

    void normalize();

    friend std::ostream& operator<<(std::ostream &out, Vector3D &vec);
    friend std::istream& operator>>(std::istream &in, Vector3D &vec);
    friend const Vector3D operator*(const float scalar, const Vector3D &vec);
    const Vector3D projectOnto(const Vector3D &vec) const;
};

#endif // __VECTOR_HPP_
