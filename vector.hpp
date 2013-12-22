#ifndef __VECTOR_HPP_
#define __VECTOR_HPP_

#include <ostream>
#include <cassert>
#include <cmath>

class Vector3D {
private:
    // {x, y, z}
    float vals[3];

public:
    Vector3D() : vals{0, 0, 0} { }
    Vector3D(float x, float y, float z) : vals{x, y, z} { }
    float operator[](int i) const {
	assert(i >= 0);
	assert(i < 3);
	return vals[i];
    }
    float & operator[](int i) {
	assert(i >= 0);
	assert(i < 3);
	return vals[i];
    }
    Vector3D& operator+=(const Vector3D &v) {
	vals[0] += v[0];
	vals[1] += v[1];
	vals[2] += v[2];
	return *this;
    }
    Vector3D& operator-=(const Vector3D &v) {
	vals[0] -= v[0];
	vals[1] -= v[1];
	vals[2] -= v[2];
	return *this;
    }
    const Vector3D operator+(const Vector3D &v) const {
	Vector3D res(*this);
	res += v;
	return res;
    }
    const Vector3D operator-(const Vector3D &v) const {
	Vector3D res(*this);
	res -= v;
	return res;
    }

    Vector3D& operator*=(const float scalar) {
	vals[0] *= scalar;
	vals[1] *= scalar;
	vals[2] *= scalar;
	return *this;
    }
    Vector3D& operator/=(const float scalar) {
	assert(scalar != 0);
	vals[0] /= scalar;
	vals[1] /= scalar;
	vals[2] /= scalar;
	return *this;
    }
    const Vector3D operator*(const float scalar) const {
	Vector3D res(*this);
	res *= scalar;
	return res;
    }
    const Vector3D operator/(const float scalar) const {
	Vector3D res(*this);
	res /= scalar;
	return res;
    }
	
    const Vector3D operator-() const {
	return -1 * (*this);
    }

    const float operator*(const Vector3D &vec) const {
	return this->dot(vec);
    }

    const float dot(const Vector3D &vec) const {
	return vals[0] * vec[0] + vals[1] * vec[1] + vals[2] * vec[2];
    }
    const Vector3D cross(const Vector3D &vec) const {
	Vector3D v;
	v[0] = vals[1] * vec[2] - vals[2] * vec[1];
	v[1] = vals[2] * vec[0] - vals[0] * vec[2];
	v[2] = vals[0] * vec[1] - vals[1] * vec[0];
	return v;
    }
    const float magSquared() const {
	return (*this) * (*this);
    }
    const float mag() const {
	return sqrtf(this->magSquared());
    }
    void normalize() {
	*this /= this->mag();
    }
    friend std::ostream& operator<<(std::ostream &out, Vector3D &vec);
    friend const Vector3D operator*(const float scalar, const Vector3D &vec);
};

std::ostream& operator<<(std::ostream &out, Vector3D &vec) {
    out << "(" << vec.vals[0] << ", " << vec.vals[1] << ", " << vec.vals[2] << ")";
    return out;
}

const Vector3D operator*(const float scalar, const Vector3D &vec) {return vec * scalar;}

#endif // __VECTOR_HPP_
