#ifndef __LIGHT_HPP_
#define __LIGHT_HPP_

#include "vector.hpp"
#include "rgb.hpp"
#include <istream>

class Light {
private:
    Vector3D pos;
    RGB color;
public:
    Light(const Vector3D& position, const RGB& color) : pos(position), color(color) { }
    const Vector3D& getPosition() const {return pos;}
    const RGB& getColor() const {return color;}
    friend std::istream& operator>>(std::istream& in, Light& l);
};

std::istream& operator>>(std::istream& in, Light& l) {
    Vector3D p;
    RGB col;
    in >> p >> col;
    l.pos = p;
    l.color = col;
    return in;
}

#endif // __LIGHT_HPP_
