#include "gtest/gtest.h"
#include "../include/Vector.h"

TEST(VectorUnary, UnaryMinus) {
    Vector a(3);
    a[0] = 1.12, a[1] = -0.1, a[2] = 13.7;
    Vector b(3);
    b[0] = -1.12, b[1] = 0.1, b[2] = -13.7;
    ASSERT_EQ(-a, b);
    ASSERT_EQ(+a, -b);
}

TEST(VectorUnary, CopyConstrucor) {
    Vector a(5);
    a[0] = 1.12, a[1] = -0.1, a[2] = 13.7, a[3] = 3.33, a[4] = -0;
    Vector b(a);
    Vector c = a;
    ASSERT_EQ(b, c);
}

TEST(VectorUnary, MagnitudeTest) {
    Vector a(3);
    a[0] = 1.12, a[1] = -0.1, a[2] = 13.7;
    ASSERT_EQ(round(a.Magnitude() * 1000) / 1000, 13.746);
}


TEST(VectorUnary, DimTest) {
    Vector a(5);
    a[3] = 2;
    ASSERT_EQ(a.GetDimentionCount(), 5);
    Vector b(3);
    ASSERT_EQ(b.GetDimentionCount(), 3);
}

TEST(PointerTest, Simple) {
    Vector a(3);
    a[0] = 1, a[1] = 2, a[2] = 3;
    double* pointer = a;
    ASSERT_EQ(*(pointer + 1), 2);
}

TEST(ConstTest, Simple) {
    const Vector a(3, 5);
    ASSERT_EQ(a[1], 5);
}