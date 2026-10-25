#include <iostream>

using namespace std;

class Vector {
private:
    bool* n;
    int k;

public:
    Vector();
    Vector(const bool arr[], int size);
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    bool& operator[](int i);
    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
    friend Vector operator^(const bool arr[], const Vector& v);
    Vector(int size);
};
