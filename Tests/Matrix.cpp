#include "gtest/gtest.h"
#include "Vector.h"
#include "OutOfRangeException.h"

TEST(MatrixTest, GetNonZero) {
    double a[] = {1, 2, 3, 4, 1, 11};
    int b[] = {0, 1, 3, 2, 1, 3};
    int c[] = {0, 3, 4, 6, 6};
    CSRMatrix mat(a, 6, b, 6, c, 5);
    ASSERT_EQ(mat.GetCountOfNoneZeroElem(), 6);
}

TEST(MatrixTest, Shape) {
    double a[] = {1, 2, 3, 4, 1, 11};
    int b[] = {0, 1, 3, 2, 1, 3};
    int c[] = {0, 3, 4, 6, 6};
    CSRMatrix mat(a, 6, b, 6, c, 5);
    ASSERT_EQ(mat.GetShape().first, 4);
}