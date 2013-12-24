#ifndef __CAMERA_HPP_
#define __CAMERA_HPP_

#include <math.h>
#include <cassert>
#include <istream>
#include "vector.hpp"
#include "ray.hpp"

class Camera {
private:
    Vector3D loc;
    Vector3D dir;
    float fov; // in radians
    Vector3D camera_up;
    Vector3D camera_right;
    float dist;
public:
    // field of view is in degrees in constructor
    Camera(const Vector3D& pos, const Vector3D& look_at, 
	   const Vector3D& up, float field_of_view = 60);
    Ray getRayForPixel(int x, int y, int imgSize) const;
    friend std::istream& operator>>(std::istream& in, Camera& cam);
};

#endif // __CAMERA_HPP_
