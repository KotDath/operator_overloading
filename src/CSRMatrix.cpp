#include "CSRMatrix.h"

CSRMatrix::CSRMatrix(double* values_, int valuesSize, int* indices_, int indicesSize, int* rowPointer_, int rowPointerSize) :
valuesSize(valuesSize), indicesSize(indicesSize), rowPointerSize(rowPointerSize)  {
    values = new double[valuesSize];
    indices = new int[indicesSize];
    rowPointer = new int[rowPointerSize];
    memcpy(values, values_, sizeof(double) * valuesSize);
    memcpy(indices, indices_, sizeof(int) * indicesSize);
    memcpy(rowPointer, rowPointer_, sizeof(int) * rowPointerSize);
}

CSRMatrix::CSRMatrix() : values(nullptr), indices(nullptr), rowPointer(nullptr), valuesSize(0), indicesSize(0), rowPointerSize(0) {}

CSRMatrix::~CSRMatrix() {
    delete[] values;
    delete[] indices;
    delete[] rowPointer;
}

CSRMatrix CSRMatrix::operator*(double lambda) const{
    CSRMatrix result(*this);
    for (int i = 0; i < valuesSize; ++i) {
        result.values[i] *= lambda;
    }
    return result;
}

CSRMatrix operator*(double lambda, const CSRMatrix& mat) {
    CSRMatrix result(mat);
    for (int i = 0; i < mat.valuesSize; ++i) {
        result.values[i] *= lambda;
    }
    return result;
}

Vector CSRMatrix::operator*(const Vector& value) const {
    int size = value.GetDimentionCount();
    if (rowPointerSize - 1 != size) {
        throw IncompatibleDimException();
    } else {
        Vector result(size);
        for (int row = 0; row < size; ++row) {
            for (int i = rowPointer[row]; i < rowPointer[row + 1]; ++i) {
                result[row] += values[i] * value[indices[i]];
            }
        }

        return result;
    }

}

Vector operator*(const Vector& vec, const CSRMatrix& mat) {
    int sizeMatrix = mat.GetShape().first;
    int sizeVector = vec.GetDimentionCount();
    Vector result(sizeMatrix);
    if (sizeMatrix != sizeVector) {
        throw IncompatibleDimException();
    } else {
        for (int row = 0; row < sizeMatrix; ++row) {
            for (int i = mat.rowPointer[row]; i < mat.rowPointer[row + 1]; ++i) {
                result[mat.indices[i]] += mat.values[i] * vec[row];
            }
        }

        return result;
    }
}


int CSRMatrix::GetCountOfNoneZeroElem() const {
    return valuesSize;
}

std::pair<int, int> CSRMatrix::GetShape() const {
    std::pair<int, int> result;
    int size = rowPointerSize - 1;
    result.first = size;
    result.second = size;
    return result;
}

std::ostream& operator<<(std::ostream& out, const CSRMatrix& mat) {
    out << "Source arrays:" << std::endl;
    int size = mat.GetShape().first;
    CSRMatrix::PrintArray(out, mat.values, mat.valuesSize);
    CSRMatrix::PrintArray(out, mat.indices, mat.indicesSize);
    CSRMatrix::PrintArray(out, mat.rowPointer, mat.rowPointerSize);
    out << "Matrix " << size << 'x' << size << ':' << std::endl;
    CSRMatrix::PrintMatrix(out, mat);
    return out;
}

std::istream& operator>>(std::istream& in, CSRMatrix& mat) {

    in >> mat.valuesSize >> mat.indicesSize >> mat.rowPointerSize;
    mat.values = CSRMatrix::ReadArray(in, mat.values, mat.valuesSize);
    mat.indices = CSRMatrix::ReadArray(in, mat.indices, mat.indicesSize);
    mat.rowPointer = CSRMatrix::ReadArray(in, mat.rowPointer, mat.rowPointerSize);

    return in;
}

template<typename T>
void CSRMatrix::PrintArray(std::ostream& out, T* arr, int size) {
    out << '[';
    for (int i = 0; i < size; ++i) {
        out << arr[i];
        if (i != size - 1) {
            out << ", ";
        }
    }
    out << "] with size: " << size << std::endl;
}

template<typename T>
T* CSRMatrix::ReadArray(std::istream& in, T* arr, int size) {
    delete[] arr;
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
        in >> arr[i];
    }

    return arr;
}

void CSRMatrix::PrintMatrix(std::ostream& out, const CSRMatrix& mat) {
    int size = mat.GetShape().first;
    for (int row = 0; row < size; ++row) {
        int start = mat.rowPointer[row];
        if (start == mat.rowPointer[row + 1]) {
            for (int i = 0; i < size; ++i) {
                out << 0 << ' ';
            }
        } else {
            for (int i = 0; i < mat.indices[start]; ++i) {
                out << 0 << ' ';
            }
            out << mat.values[start] << ' ';
            for (int i = mat.rowPointer[row]; i < mat.rowPointer[row + 1] - 1; ++i) {
                for (int j = mat.indices[i]; j < mat.indices[i + 1] - 1; ++j) {
                    out << 0 << ' ';
                }

                out << mat.values[i + 1] << ' ';
            }

            for (int i = mat.indices[mat.rowPointer[row + 1] - 1] + 1; i < size; ++i) {
                out << 0 << ' ';
            }
        }
        out << std::endl;
    }
}

CSRMatrix::CSRMatrix(const CSRMatrix& mat) : valuesSize(mat.valuesSize), indicesSize(mat.indicesSize), rowPointerSize(mat.rowPointerSize) {
    values = new double[valuesSize];
    indices = new int[indicesSize];
    rowPointer = new int[rowPointerSize];
    memcpy(values, mat.values, sizeof(double) * valuesSize);
    memcpy(indices, mat.indices, sizeof(int) * indicesSize);
    memcpy(rowPointer, mat.rowPointer, sizeof(int) * rowPointerSize);
}

CSRMatrix& CSRMatrix::operator=(const CSRMatrix& mat) {
    if (this != &mat) {
        ResizeIfDifferentSize(values, mat.values, valuesSize, mat.valuesSize);
        ResizeIfDifferentSize(indices, mat.indices, indicesSize, mat.indicesSize);
        ResizeIfDifferentSize(rowPointer, mat.rowPointer, rowPointerSize, mat.rowPointerSize);
        memcpy(values, mat.values, sizeof(double) * valuesSize);
        memcpy(indices, mat.indices, sizeof(int) * indicesSize);
        memcpy(rowPointer, mat.rowPointer, sizeof(int) * rowPointerSize);
    }

    return *this;
}

template<typename T>
void CSRMatrix::ResizeIfDifferentSize(T*& arr, T* newArr, int& size, int newSize) {
    if (size != newSize) {
        delete[] arr;
        arr = new T[newSize];
        size = newSize;
    }
}