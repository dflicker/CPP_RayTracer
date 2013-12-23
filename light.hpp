#ifndef __LIGHT_HPP_
#define __LIGHT_HPP_

#include "vector.hpp"
#include "rgb.hpp"

class Light {
private:
    Vector3D pos;
    RGB color;
public:
    Light(const Vector3D& position, const RGB& color) : pos(position), color(color) { }
    const Vector3D& getPosition() const {return pos;}
    const RGB& getColor() const {return color;}
};

#endif // __LIGHT_HPP_
