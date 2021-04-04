#pragma once
#include <exception>
#include <sstream>

class OutOfRangeException : public std::exception {
public:
    virtual const char* what();
};
