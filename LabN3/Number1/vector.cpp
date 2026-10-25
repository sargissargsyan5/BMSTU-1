#include "vector.h"

Vector::Vector() {
    n = nullptr;
    k = 0;
}

Vector::Vector(const bool arr[], int size) {
    k = size;
    n = new bool[k];

    for (int i = 0; i < k; i++) {
        n[i] = arr[i];
    }
}

Vector::Vector(const Vector& other) {
    k = other.k;
    n = new bool[k];

    for (int i = 0; i < k; i++) {
        n[i] = other.n[i];
    }
}
Vector::Vector(Vector &&other) {
    k = other.k;
    n = other.n;
    other.n = nullptr;
    other.k = 0;
}

Vector::~Vector() {
    delete[] n;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] n;
    k = other.k;
    if (k>0) {
        n = new bool[k];
    } else {
        n = nullptr;
    }
    for (int i = 0; i < k; i++) {
        n[i] = other.n[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    if (this == &other) {
        return *this;
    }
    delete[] n;
    n = other.n;
    k = other.k;
    other.k = 0;
    other.n = nullptr;

    return *this;
}

bool& Vector::operator[](int i) {
    return n[i];
}

ostream& operator<<(ostream& out, const Vector& v) {
    for (int i = 0; i < v.k; i++) {
        out << v.n[i];
    }
    return out;
}

istream& operator>>(istream& in, Vector& v) {
    int size;
    in >> size;

    delete[] v.n;
    v.k = size;
    v.n = (size > 0) ? new bool[size] : nullptr;

    for (int i = 0; i < v.k; i++) {
        in >> v.n[i];
    }
    return in;
}

Vector operator^(const bool arr[], const Vector& v) {
    Vector res(v.k);
    for (int i = 0; i < v.k; i++) {
        res.n[i] = arr[i] ^ v.n[i];
    }
    return res;
}

Vector::Vector(int size) {
    k = size;
    n = (size > 0) ? new bool[size] : nullptr;
}
