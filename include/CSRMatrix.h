#pragma once
#include <cstring>
#include "Vector.h"
#include "IncompatibleDimException.h"

class Vector;

class CSRMatrix {
public:
    CSRMatrix(double* values, int valuesSize, int* indices, int indicesSize, int* rowPointer, int rowPointerSize);
    CSRMatrix(const CSRMatrix& mat);
    CSRMatrix();
    CSRMatrix operator*(double lambda) const;
    friend CSRMatrix operator*(double lambda, const CSRMatrix& mat);
    friend Vector operator*(const Vector& vec, const CSRMatrix& mat);
    Vector operator*(const Vector& value) const;
    int GetCountOfNoneZeroElem() const;
    std::pair<int, int> GetShape() const;

    //!!! operator= ?

    friend std::ostream& operator<<(std::ostream& out, const CSRMatrix& mat);
    friend std::istream& operator>>(std::istream& in, CSRMatrix& mat);
    friend void PrintMatrix(std::ostream& out, const CSRMatrix& mat);

    ~CSRMatrix();
private:
    double* values;
    int valuesSize;
    int* indices;
    int indicesSize;
    int* rowPointer;
    int rowPointerSize;
};

CSRMatrix operator*(double lambda, const CSRMatrix& mat);
Vector operator*(const Vector& vec, const CSRMatrix& mat);

std::ostream& operator<<(std::ostream& out, const CSRMatrix& mat);
std::istream& operator>>(std::istream& in, CSRMatrix& mat);

template<typename T>
void PrintArray(std::ostream& out, T* arr, int size);

template<typename T>
T* ReadArray(std::istream& in, T* arr, int size);

void PrintMatrix(std::ostream& out, const CSRMatrix& mat);