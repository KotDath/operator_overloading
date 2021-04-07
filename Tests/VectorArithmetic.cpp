#include "gtest/gtest.h"
#include "Vector.h"

TEST(BinaryPlusTest, SimpleAB) {
    Vector a(3);
    a[0] = 1, a[1] = 2, a[2] = 3;
    Vector b(3);
    b[0] = -5, b[1] = 6, b[2] = 2;
    Vector c(3);
    c[0] = -4, c[1] = 8, c[2] = 5;
    ASSERT_EQ(a + b, c);
}

TEST(BinaryPlusTest, WithUnaryMinus) {
    Vector a(2);
    a[0] = 1, a[1] = 4;
    Vector b(2);
    a += -a;
    ASSERT_EQ(a, b);
}

TEST(MultiplyTest, SimpleMulti) {
    Vector b(3);
    b[0] = -5, b[1] = 6, b[2] = 2;
    Vector a(3);
    a[0] = 1, a[1] = 1, a[2] = -1;
    ASSERT_EQ(b * a, -1);
}

TEST(MultiplyTest, LambdaMultiply) {
    Vector a(3);
    a[0] = 1, a[1] = 2, a[2] = 3;
    Vector b(3);
    b[0] = -3, b[1] = -6, b[2] = -9;
    ASSERT_EQ(a * 3, 3 * a);
    ASSERT_EQ(a * -3, b);
}

TEST(MultiplyTest, WithMatrix) {
    double a[] = {8, 2, 5, 7, 1, 2, 9};
    int b[] =  {0, 2, 2, 2, 3, 4, 3};
    int c[] = {0, 2, 3, 3, 3, 6, 6, 7};
    CSRMatrix mat(a, 7, b, 7, c, 8);
    Vector vec(7);
    Vector result1(7);
    Vector result2(7);
    for (int i = 0; i < 7; ++i) {
        vec[i] = 1;
    }

    result1[0] = 8, result1[1] = 0, result1[2] = 14, result1[3] = 10, result1[4] = 2, result1[5] = 0, result1[6] = 0;
    result2[0] = 10, result2[1] = 5, result2[2] = 0, result2[3] = 0, result2[4] = 10, result2[5] = 0, result2[6] = 9;

    ASSERT_EQ(vec * mat, result1);
    ASSERT_EQ(mat * vec, result2);
}