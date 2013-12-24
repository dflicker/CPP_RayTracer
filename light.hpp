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
    Light(const Vector3D& position, const RGB& color);
    const Vector3D& getPosition() const;
    const RGB& getColor() const;
    friend std::istream& operator>>(std::istream& in, Light& l);
};

#endif // __LIGHT_HPP_
