#include "../include/Vector.h"

Vector::Vector(int size, double defaultValue) : size(size) {
    coordinates = new double[size];
    for (int i = 0; i < size; ++i) {
        coordinates[i] = defaultValue;
    }
}

Vector::~Vector() {
    delete[] coordinates;
}

Vector::Vector(const Vector& other) {
    size = other.size;
    coordinates = new double[size];
    for (int i = 0; i < size; ++i) {
        coordinates[i] = other[i];
    }

}

Vector::Vector(int size) : size(size) {
    coordinates = new double[size];
    for (int i = 0; i < size; ++i) {
        coordinates[i] = 0;
    }
}

Vector::Vector() {
    size = 0;
    coordinates = new double[0]; //!!! По умолчанию должен быть nullptr. И лучше через список инициализации (:)
}

int Vector::GetDimentionCount() const {
    return size;
}

double Vector::Magnitude() const {
    double result = 0;
    for (int i = 0; i < size; ++i) {
        result += coordinates[i] * coordinates[i];
    }

    return sqrt(result);
}

double& Vector::operator[](int index) {
    return coordinates[index];
}

const double& Vector::operator[](int index) const {
    return coordinates[index];
}

Vector operator+(const Vector& first, const Vector& second) {
    Vector result = first;
    return result += second;
}

Vector operator-(const Vector& first, const Vector& second) {
    Vector result = first;
    return result -= second;
}


const Vector& Vector::operator+() const {
    return *this;
}

Vector Vector::operator-() const {
    Vector copy(size);
    for (int i = 0; i < size; ++i) {
        copy[i] = -coordinates[i];
    }

    return copy;
}


Vector operator*(const Vector& vec, double lambda) {
    Vector scaledFirst(vec.size);
    for (int i = 0; i < vec.size; ++i) {
        scaledFirst[i] = vec[i] * lambda;
    }

    return scaledFirst;
}

Vector operator*(double lambda, const Vector& vec) {
    return vec * lambda;
}

double operator*(const Vector& first, const Vector& second) {
    if (first.size != second.size) {
        throw IncompatibleDimException();
    } else {
        double result = 0;
        for(int i = 0; i < first.size; ++i) {
            result += first[i] * second[i];
        }

        return result;
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    } else {
        size = other.size;
        
        //!!! Выделять память стоит только, если размеры не совпадают
        
        delete[] coordinates;
        coordinates = new double[size];
        
        
        for (int i = 0; i < size; ++i) {
            coordinates[i] = other[i];
        }

        return *this;
    }
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
    out << "Vector " << vec.size << " (";
    for (int i = 0; i < vec.size; ++i) {
        out << vec[i];
        if (i != vec.size - 1) {
            out << ", ";
        }
    }
    out << ")";
    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Vector& vec) {
    in >> vec.size;
    delete[] vec.coordinates;
    vec.coordinates = new double[vec.size];
    for (int i = 0; i < vec.size; ++i) {
        in >> vec[i];
    }
    return in;
}

Vector& Vector::operator+=(const Vector& other) {
    if (size != other.size) {
        throw IncompatibleDimException();
    } else {
        for (int i = 0; i < other.size; ++i) {
            coordinates[i] += other[i];
        }
    }

    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    if (size != other.size) {
        throw IncompatibleDimException();
    } else {
        for (int i = 0; i < other.size; ++i) {
            coordinates[i] -= other[i];
        }
    }

    return *this;
}

bool operator==(const Vector& first, const Vector& second) {
    if (first.size != second.size) {
        return false;
    }

    for (int i = 0; i < first.size; ++i) {
        if (first[i] != second[i]) {         //!!! double на != сравнивать сомнительно -> через std::fabs() < epsilon
            return false;
        }
    }

    return true;
}

Vector::operator double *() {
    return coordinates;
}

