#include "camera.hpp"

// field of view is in degrees in constructor
Camera::Camera(const Vector3D& pos, const Vector3D& look_at, 
	       const Vector3D& up, float field_of_view) :
    loc(pos), dir(look_at - pos) {
    dir.normalize();
    camera_right = dir.cross(up);
    camera_up = camera_right.cross(dir);
    fov = (field_of_view / 180) * M_PIl;
    dist = 0.5 / tanf(fov / 2);
}
Ray Camera::getRayForPixel(int x, int y, int imgSize) const {
    assert(x >= 0);
    assert(y >= 0);
    assert(x < imgSize);
    assert(y < imgSize);
    Vector3D pixelDir = dist * dir + (0.5 - (float) y / (float) (imgSize - 1)) *
	camera_up + ((float) x / (float) (imgSize - 1) - 0.5) * camera_right;
    Ray pixelRay(loc, pixelDir);
    return pixelRay;
}

std::istream& operator>>(std::istream& in, Camera& cam) {
    Vector3D p;
    Vector3D look;
    Vector3D u;
    in >> p >> look >> u;
    cam = Camera(p, look, u);
    return in;
}
