cmake_minimum_required(VERSION 3.17)
project(TEST)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(VECTOR_FILES src/Vector.cpp include/Vector.h)
set(CSRMATRIX_FILES src/CSRMatrix.cpp include/CSRMatrix.h)
set(OUTOFRANGEEXCEPTION_FILES src/OutOfRangeException.cpp include/OutOfRangeException.h)
set(TESTS Tests/VectorArithmetic.cpp Tests/Exception.cpp Tests/VectorUnary.cpp Tests/Complex.cpp Tests/Matrix.cpp)
set(INCOMPATIBLEDIMEXCEPTION_FILES include/IncompatibleDimException.h src/IncompatibleDimException.cpp)

add_executable(TEST main.cpp ${VECTOR_FILES} ${CSRMATRIX_FILES} ${OUTOFRANGEEXCEPTION_FILES}
        ${TESTS} ${INCOMPATIBLEDIMEXCEPTION_FILES})

target_link_libraries(TEST gtest gtest_main)