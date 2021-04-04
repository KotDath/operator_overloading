#include <gtest/gtest.h>
#include "include/CSRMatrix.h"

int main() {
    testing::InitGoogleTest();
    std::cout << "Input Vector and i multiply it x5" << std::endl;
    Vector vec(5);
    std::cin >> vec;
    std::cout << vec * 5;
    CSRMatrix mat;
    std::cout << "Input Matrix and i multiply it x2" << std::endl;
    std::cin >> mat;
    std::cout << mat * 2;
    std::cout << "Matrix x Vector:" << std::endl;
    std::cout << mat * vec;
    std::cout << "Vector x Matrix:" << std::endl;
    std::cout << vec * mat;
    RUN_ALL_TESTS();
    getchar();
    getchar();
    return 0;
}
