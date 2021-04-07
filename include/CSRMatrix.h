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

    CSRMatrix& operator=(const CSRMatrix& mat);
    friend std::ostream& operator<<(std::ostream& out, const CSRMatrix& mat);
    friend std::istream& operator>>(std::istream& in, CSRMatrix& mat);

    ~CSRMatrix();
private:
    template<typename T>
    static void PrintArray(std::ostream& out, T* arr, int size);

    template<typename T>
    static T* ReadArray(std::istream& in, T* arr, int size);

    static void PrintMatrix(std::ostream& out, const CSRMatrix& mat);

    template<typename T>
    static void ResizeIfDifferentSize(T*& arr, T* newArr, int& size, int newSize);
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

