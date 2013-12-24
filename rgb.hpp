#ifndef __RGB_HPP_
#define __RGB_HPP_

#include <ostream>
#include <cassert>
#include <istream>
#include <ios>
class RGB {
private:
    float red;
    float green;
    float blue;
    
public:
    RGB();
    RGB(float red, float green, float blue);
    const float getRed() const;
    const float getGreen() const;
    const float getBlue() const;
    void setRed(const float new_red);
    void setGreen(const float new_green);
    void setBlue(const float new_blue);
    void clamp(float min, float max);
    RGB& operator+=(const RGB &color);
    RGB& operator-=(const RGB &color);
    RGB& operator*=(const RGB &color);
    const RGB operator+(const RGB &color) const;
    const RGB operator-(const RGB &color) const;
    const RGB operator*(const RGB &color) const;
    RGB& operator*=(const float scalar);
    RGB& operator/=(const float scalar);
    const RGB operator*(const float scalar) const;
    const RGB operator/(const float scalar) const;
    friend std::ostream& operator<<(::std::ostream &out, RGB &color);
    friend std::istream& operator>>(std::istream &in, RGB &vec);
    friend const RGB operator*(const float scalar, const RGB &color);
};

#endif // __RGB_HPP_
