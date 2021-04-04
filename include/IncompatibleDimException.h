#pragma once
#include <exception>

class IncompatibleDimException : public std::exception{
public:
    virtual const char* what();
};
