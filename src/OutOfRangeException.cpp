#include "../include/OutOfRangeException.h"


const char* OutOfRangeException::what() {
    return "Index is out of range of array of coordinates";
}
