#include "light.hpp"

Light::Light(const Vector3D& position, const RGB& color) : pos(position), color(color) { }

const Vector3D& Light::getPosition() const {
    return pos;
}
const RGB& Light::getColor() const {
    return color;
}

std::istream& operator>>(std::istream& in, Light& l) {
    Vector3D p;
    RGB col;
    in >> p >> col;
    l.pos = p;
    l.color = col;
    return in;
}
