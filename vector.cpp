#include "vector.hpp"

Vector3D::Vector3D() : vals{0, 0, 0} { }

Vector3D::Vector3D(float x, float y, float z) : vals{x, y, z} { }

float Vector3D::operator[](int i) const {
    assert(i >= 0);
    assert(i < 3);
    return vals[i];
}

float& Vector3D::operator[](int i) {
    assert(i >= 0);
    assert(i < 3);
    return vals[i];
}

Vector3D& Vector3D::operator+=(const Vector3D &v) {
    vals[0] += v[0];
    vals[1] += v[1];
    vals[2] += v[2];
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D &v) {
    vals[0] -= v[0];
    vals[1] -= v[1];
    vals[2] -= v[2];
    return *this;
}

const Vector3D Vector3D::operator+(const Vector3D &v) const {
    Vector3D res(*this);
    res += v;
    return res;
}

const Vector3D Vector3D::operator-(const Vector3D &v) const {
    Vector3D res(*this);
    res -= v;
    return res;
}

Vector3D& Vector3D::operator*=(const float scalar) {
    vals[0] *= scalar;
    vals[1] *= scalar;
    vals[2] *= scalar;
    return *this;
}

Vector3D& Vector3D::operator/=(const float scalar) {
    assert(scalar != 0);
    vals[0] /= scalar;
    vals[1] /= scalar;
    vals[2] /= scalar;
    return *this;
}

const Vector3D Vector3D::operator*(const float scalar) const {
    Vector3D res(*this);
    res *= scalar;
    return res;
}

const Vector3D Vector3D::operator/(const float scalar) const {
    Vector3D res(*this);
    res /= scalar;
    return res;
}

const Vector3D Vector3D::operator-() const {
	return -1 * (*this);
}

const float Vector3D::operator*(const Vector3D &vec) const {
    return this->dot(vec);
}

const float Vector3D::dot(const Vector3D &vec) const {
    return vals[0] * vec[0] + vals[1] * vec[1] + vals[2] * vec[2];
}

const Vector3D Vector3D::cross(const Vector3D &vec) const {
    Vector3D v;
    v[0] = vals[1] * vec[2] - vals[2] * vec[1];
    v[1] = vals[2] * vec[0] - vals[0] * vec[2];
    v[2] = vals[0] * vec[1] - vals[1] * vec[0];
    return v;
}

const float Vector3D::magSquared() const {
    return (*this) * (*this);
}

const float Vector3D::mag() const {
    return sqrtf(this->magSquared());
}

void Vector3D::normalize() {
    *this /= this->mag();
}

const Vector3D Vector3D::projectOnto(const Vector3D &vec) const {
    return vec * (((*this) * vec) / (vec * vec));
}

std::ostream& operator<<(std::ostream &out, Vector3D &vec) {
    out << "(" << vec.vals[0] << ", " << vec.vals[1] << ", " << vec.vals[2] << ")";
    return out;
}

std::istream& operator>>(std::istream &in, Vector3D &vec) {
    char ch = 0;
    float val = 0;
    if (!in)
	return in;
    in >> ch;
    if (ch != '(') {
	in.clear(std::ios_base::failbit);
	return in;
    }
    for (int i = 0; i < 3; i++) {
	in >> val >> ch;
	if (ch == ',')
	    vec[i] = val;
    }
    if (ch != ')') {
	in.clear(std::ios_base::failbit);
	return in;
    }
    vec[2] = val;
    return in;
}
	

const Vector3D operator*(const float scalar, const Vector3D &vec) {
    return vec * scalar;
}
