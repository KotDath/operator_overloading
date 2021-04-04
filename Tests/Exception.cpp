#include "gtest/gtest.h"
#include "../include/Vector.h"
#include "../include/OutOfRangeException.h"
#include "../include/IncompatibleDimException.h"


TEST(OutOfRangeExceptionTest, SimpleVector) {
    Vector a(4);
    a[0] = 3, a[1] = 2, a[2] = -11, a[3] = 0;
    try {
        double b = a[-1] * 3;
    } catch (OutOfRangeException& e) {
        ASSERT_STREQ("Index is out of range of array of coordinates", e.what());
    }
}

TEST(IncompatibleDimException, VectorBinary) {
    Vector a(3), b(3), c(4);
    a[0] = 1, a[1] = 1.5, a[2] = -12.7;
    b[0] = -1.1, b[1] = 3.33, b[2] = -1;
    c[0] = -12.5, c[1] = 0, c[2] = 0, c[3] = 13;
    try {
        double d = (a + b) * c;
    } catch (IncompatibleDimException& e) {
        ASSERT_STREQ("Incompatible size of Vectors or Matrix and Vectors", e.what());
    }

    try {
        Vector d = (a + b) + c;
    } catch (IncompatibleDimException& e) {
        ASSERT_STREQ("Incompatible size of Vectors or Matrix and Vectors", e.what());
    }

    try {
        Vector d = a + b - c;
    } catch (IncompatibleDimException& e) {
        ASSERT_STREQ("Incompatible size of Vectors or Matrix and Vectors", e.what());
    }
}

TEST(IncompatibleDimException, MatrixMultiply) {
    double a[] = {1, 2, 3, 4, 1, 11};
    int b[] = {0, 1, 3, 2, 1, 3};
    int c[] = {0, 3, 4, 6, 6};
    CSRMatrix mat(a, 6, b, 6, c, 5);
    Vector vec(4);
    vec[0] = 1, vec[1] = 2, vec[2] = 3, vec[3] = 4;
    Vector result(4);
    result[0] = 17, result[1] = 12, result[2] = 46;
    ASSERT_EQ(mat * vec, result);
}

