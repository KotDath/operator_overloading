#pragma once
#include <iostream>
#include "CSRMatrix.h"
#include <cmath>

class CSRMatrix;

class Vector {
public:
    Vector(int size, double defaultValue);
    Vector(int size);
    Vector();
    Vector(const Vector& other);
    ~Vector();

    int GetDimentionCount() const;
    double Magnitude() const;
    Vector& operator=(const Vector& other);

    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);

    Vector operator-() const;
    const Vector& operator+() const;
    friend Vector operator+(const Vector& first, const Vector& second);
    friend Vector operator-(const Vector& first, const Vector& second);
    friend Vector operator*(const Vector& vec, double lambda);
    friend Vector operator*(double lambda, const Vector& vec);
    friend double operator*(const Vector& first, const Vector& second);
    friend bool operator==(const Vector& first, const Vector& second);

    double& operator[](int index);
    const double& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& out, const Vector& vec);
    friend std::istream& operator>>(std::istream& out, Vector& vec);

    operator double*();
private:
    int size;
    double* coordinates;
};

Vector operator+(const Vector& first, const Vector& second);
Vector operator-(const Vector& first, const Vector& second);

Vector operator*(const Vector& vec, double lambda);
Vector operator*(double lambda, const Vector& vec);
double operator*(const Vector& first, const Vector& second);

bool operator==(const Vector& first, const Vector& second);

std::ostream& operator<<(std::ostream& out, const Vector& vec);
std::istream& operator>>(std::istream& out, const Vector& vec);
