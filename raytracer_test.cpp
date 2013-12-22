#include "vector.hpp"
#include "rgb.hpp"
#include <gtest/gtest.h>
#include <cmath>

using namespace testing;

TEST(TestVector, NoArgConstructor) {
    Vector3D no_arg_vec;
    EXPECT_FLOAT_EQ(no_arg_vec[0], 0);
    EXPECT_FLOAT_EQ(no_arg_vec[1], 0);
    EXPECT_FLOAT_EQ(no_arg_vec[2], 0);
}
TEST(TestVector, ThreeArgConstructor) {
    Vector3D three_arg_vec(1.1, 1.2, 1.3);
    EXPECT_FLOAT_EQ(three_arg_vec[0], 1.1);
    EXPECT_FLOAT_EQ(three_arg_vec[1], 1.2);
    EXPECT_FLOAT_EQ(three_arg_vec[2], 1.3);
}

TEST(TestVector, PlusEquals) {
    Vector3D u(1, 2, 3);
    Vector3D v(3, 4, 5);
    u += v;
    EXPECT_FLOAT_EQ(u[0], 4);
    EXPECT_FLOAT_EQ(u[1], 6);
    EXPECT_FLOAT_EQ(u[2], 8);  
} 

TEST(TestVector, MinusEquals) {
    Vector3D u(1, 2, 3);
    Vector3D v(3, 4, 5);
    u -= v;
    EXPECT_FLOAT_EQ(u[0], -2);
    EXPECT_FLOAT_EQ(u[1], -2);
    EXPECT_FLOAT_EQ(u[2], -2); 
}

TEST(TestVector, Plus) {
    Vector3D u(1, 2, 3);
    Vector3D v(3, 4, 5);
    Vector3D t;
    t = u + v;
    EXPECT_FLOAT_EQ(t[0], 4);
    EXPECT_FLOAT_EQ(t[1], 6);
    EXPECT_FLOAT_EQ(t[2], 8); 
}

TEST(TestVector, Minus) {
    Vector3D u(1, 2, 3);
    Vector3D v(3, 4, 5);
    Vector3D t;
    t = u - v;
    EXPECT_FLOAT_EQ(t[0], -2);
    EXPECT_FLOAT_EQ(t[1], -2);
    EXPECT_FLOAT_EQ(t[2], -2); 
}

TEST(TestVector, TimesEquals) {
    Vector3D u(1, 3, 5);
    u *= 3.0;
    EXPECT_FLOAT_EQ(u[0], 3);
    EXPECT_FLOAT_EQ(u[1], 9);
    EXPECT_FLOAT_EQ(u[2], 15);
}

TEST(TestVector, DivideEquals) {
    Vector3D u(3, 9, 15);
    u /= 3.0;
    EXPECT_FLOAT_EQ(u[0], 1);
    EXPECT_FLOAT_EQ(u[1], 3);
    EXPECT_FLOAT_EQ(u[2], 5);
}

TEST(TestVector, RightMultiply) {
    Vector3D u;
    Vector3D v(1, 3, 5);
    u = v * 3.0;
    EXPECT_FLOAT_EQ(u[0], 3);
    EXPECT_FLOAT_EQ(u[1], 9);
    EXPECT_FLOAT_EQ(u[2], 15);
}

TEST(TestVector, LeftMultiply) {
    Vector3D u;
    Vector3D v(1, 3, 5);
    u = 3.0 * v;
    EXPECT_FLOAT_EQ(u[0], 3);
    EXPECT_FLOAT_EQ(u[1], 9);
    EXPECT_FLOAT_EQ(u[2], 15);
}

TEST(TestVector, ScalarDivide) {
    Vector3D v(3, 9, 15);
    Vector3D u;
    u = v / 3.0;
    EXPECT_FLOAT_EQ(u[0], 1);
    EXPECT_FLOAT_EQ(u[1], 3);
    EXPECT_FLOAT_EQ(u[2], 5);
}

TEST(TestVector, UnaryMinus) {
    Vector3D v(1, 2, 3);
    Vector3D u = -v;
    EXPECT_FLOAT_EQ(u[0], -1);
    EXPECT_FLOAT_EQ(u[1], -2);
    EXPECT_FLOAT_EQ(u[2], -3);
}

TEST(TestVector, DotProduct) {
    Vector3D t(1, 2, 3);
    Vector3D v(100, 200, 300);
    float u = t * v;
    EXPECT_FLOAT_EQ(u, 1400);
}

TEST(TestVector, CrossProduct) {
    Vector3D t(1, 2, 3);
    Vector3D v(4, 5, 6);
    Vector3D u = t.cross(v);
    EXPECT_FLOAT_EQ(u[0], -3);
    EXPECT_FLOAT_EQ(u[1], 6);
    EXPECT_FLOAT_EQ(u[2], -3);
}

TEST(TestVector, MagSquared) {
    Vector3D t(1, 2, 3);
    float u = t.magSquared();
    EXPECT_FLOAT_EQ(u, 14);
}

TEST(TestVector, Mag) {
    Vector3D t(1, 2, 3);
    float u = t.mag();
    EXPECT_FLOAT_EQ(u, sqrtf(14.0));
}

TEST(TestVector, Normalize) {
    Vector3D u(1, 2, 3);
    u.normalize();
    EXPECT_FLOAT_EQ(u[0], 0.26726124);
    EXPECT_FLOAT_EQ(u[1], 0.53452247);
    EXPECT_FLOAT_EQ(u[2], 0.80178368);
}

TEST(TestRGB, NoArgConstructor) {
    RGB u;
    EXPECT_FLOAT_EQ(u.getRed(), 0);
    EXPECT_FLOAT_EQ(u.getGreen(), 0);
    EXPECT_FLOAT_EQ(u.getBlue(), 0); 
}

TEST(TestRGB, ThreeArgConstructor) {
    RGB u(1, 2, 3);
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

TEST(TestRGB, Setters) {
    RGB u;
    u.setRed(1);
    u.setGreen(2);
    u.setBlue(3);
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

TEST(TestRGB, PlusEquals) {
    RGB u;
    RGB v(1, 2, 3);
    u += v;
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

TEST(TestRGB, MinusEquals) {
    RGB u;
    RGB v(1, 2, 3);
    u -= v;
    EXPECT_FLOAT_EQ(u.getRed(), -1);
    EXPECT_FLOAT_EQ(u.getGreen(), -2);
    EXPECT_FLOAT_EQ(u.getBlue(), -3); 
}

TEST(TestRGB, MultiplyEquals) {
    RGB u(1, 1, 1);
    RGB v(1, 2, 3);
    u *= v;
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

TEST(TestRGB, Plus) {
    RGB t(1, 1, 1);
    RGB v(1, 2, 3);
    RGB u = t + v;
    EXPECT_FLOAT_EQ(u.getRed(), 2);
    EXPECT_FLOAT_EQ(u.getGreen(), 3);
    EXPECT_FLOAT_EQ(u.getBlue(), 4); 
}

TEST(TestRGB, Minus) {
    RGB t(1, 1, 1);
    RGB v(1, 2, 3);
    RGB u = t - v;
    EXPECT_FLOAT_EQ(u.getRed(), 0);
    EXPECT_FLOAT_EQ(u.getGreen(), -1);
    EXPECT_FLOAT_EQ(u.getBlue(), -2); 
}

TEST(TestRGB, Multiply) {
    RGB t(1, 1, 1);
    RGB v(1, 2, 3);
    RGB u = t * v;
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

TEST(TestRGB, MultiplyEqualsScalar) {
    RGB u(1, 2, 3);
    u *= 2.0;
    EXPECT_FLOAT_EQ(u.getRed(), 2);
    EXPECT_FLOAT_EQ(u.getGreen(), 4);
    EXPECT_FLOAT_EQ(u.getBlue(), 6); 
}

TEST(TestRGB, DivideEqualsScalar) {
    RGB u(2, 4, 6);
    u /= 2.0;
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

TEST(TestRGB, MultiplyScalar) {
    RGB v(1, 2, 3);
    RGB u = v * 2.0;
    EXPECT_FLOAT_EQ(u.getRed(), 2);
    EXPECT_FLOAT_EQ(u.getGreen(), 4);
    EXPECT_FLOAT_EQ(u.getBlue(), 6); 
    u = 2.0 * v;
    EXPECT_FLOAT_EQ(u.getRed(), 2);
    EXPECT_FLOAT_EQ(u.getGreen(), 4);
    EXPECT_FLOAT_EQ(u.getBlue(), 6); 
}

TEST(TestRGB, DivideScalar) {
    RGB v(2, 4, 6);
    RGB u = v / 2.0;
    EXPECT_FLOAT_EQ(u.getRed(), 1);
    EXPECT_FLOAT_EQ(u.getGreen(), 2);
    EXPECT_FLOAT_EQ(u.getBlue(), 3); 
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
