#include "gtest/gtest.h"
#include "../include/Vector.h"
#include "../include/OutOfRangeException.h"

TEST(ComplexTest, First) {
    Vector first(3), second(3), third(3), result(3);
    first[0] = 1, first[1] = -1, first[2] = 0;
    second[0] = 3, second[1] = 0.5, second[2] = 1.4;
    third[0] = 0, third[1] = 1, third[2] = 5;
    result = -2 * (-first + second) * third * (first * 5);
    Vector answer(3);
    answer[0] = -85, answer[1] = 85;
    ASSERT_EQ(result, answer);
}

TEST(ComplexTex, second) {
    Vector first(3), second(3), third(3), result(3);
    first[0] = 1, first[1] = -1, first[2] = 0;
    second[0] = 3, second[1] = 0.5, second[2] = 1.4;
    third[0] = 0, third[1] = 1, third[2] = 5;
    double a[] = {1, 2, 4, 2, 6};
    int b[] =  {0, 1, 1, 1, 2};
    int c[] = {0, 2, 3, 5};
    CSRMatrix mat(a, 5, b, 5, c, 4);
    result = mat * (third * mat) + 5 * (+second) -1 * (-first);
    Vector answer(3);
    answer[0] = 44, answer[1] = 57.5, answer[2] = 215;
    ASSERT_EQ(result, answer);
}
