#ifndef __RGB_HPP_
#define __RGB_HPP_

#include <ostream>
#include <cassert>

class RGB {
private:
    float red;
    float green;
    float blue;
    
public:
    RGB() : red(0), green(0), blue(0) { }
    RGB(float red, float green, float blue) : red(red), green(green), blue(blue) { }
    const float getRed() const {return red;}
    const float getGreen() const {return green;}
    const float getBlue() const {return blue;}
    void setRed(const float new_red) {red = new_red;}
    void setGreen(const float new_green) {green = new_green;}
    void setBlue(const float new_blue) {blue = new_blue;}
    void clamp(float min, float max) {
	red = (red < min) ? min : red;
	red = (red > max) ? max : red;
	green = (green < min) ? min : green;
	green = (green > max) ? max : green;
	blue = (blue < min) ? min : blue;
	blue = (blue > max) ? max : blue;
    }
    RGB& operator+=(const RGB &color) {
	red += color.getRed();
	green += color.getGreen();
	blue += color.getBlue();
	return *this;
    }
    RGB& operator-=(const RGB &color) {
	red -= color.getRed();
	green -= color.getGreen();
	blue -= color.getBlue();
	return *this;
    }
    RGB& operator*=(const RGB &color) {
	red *= color.getRed();
	green *= color.getGreen();
	blue *= color.getBlue();
	return *this;
    }
    const RGB operator+(const RGB &color) const {
	RGB res(*this);
	res += color;
	return res;
    }
    const RGB operator-(const RGB &color) const {
	RGB res(*this);
	res -= color;
	return res;
    }
    const RGB operator*(const RGB &color) const {
	RGB res(*this);
	res *= color;
	return res;
    }
    RGB& operator*=(const float scalar) {
	red *= scalar;
	green *= scalar;
	blue *= scalar;
	return *this;
    }
    RGB& operator/=(const float scalar) {
	red /= scalar;
	green /= scalar;
	blue /= scalar;
	return *this;
    }
    const RGB operator*(const float scalar) const {
	RGB res(*this);
	res *= scalar;
	return res;
    }
    const RGB operator/(const float scalar) const {
	RGB res(*this);
	res /= scalar;
	return res;
    }
    friend std::ostream& operator<<(::std::ostream &out, RGB &color);
    friend const RGB operator*(const float scalar, const RGB &color);
};

std::ostream& operator<<(::std::ostream &out, RGB &color) {
    out << "(" << color.red << ", " << color.green << ", " << color.blue << ")";
    return out;
}

const RGB operator*(const float scalar, const RGB &color) {return color * scalar;}

#endif // __RGB_HPP_
