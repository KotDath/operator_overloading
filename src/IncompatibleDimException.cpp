#include "../include/IncompatibleDimException.h"

const char* IncompatibleDimException::what() {
    return "Incompatible size of Vectors or Matrix and Vectors";
}
