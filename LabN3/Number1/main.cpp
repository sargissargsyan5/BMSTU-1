// вариант 21

#include <utility>
#include "vector.h"
#include <fstream>

using namespace std;

int main() {

    ifstream input("input.txt"); // Работа с файлами
    ofstream output("output.txt");

    if (!input || !output) { // Проверка открытия файлов
        return 1;
    }

    int size;
    input >> size;

    bool* arr = new bool[size];

    for (int i = 0; i < size; i++) {
        input >> arr[i];
    }

    Vector a(arr, size); // Конструктор из обычного массива

    Vector b(std::move(a));   // Конструктор перемещения

    Vector copy(b); // Конструктор копирования

    copy[0] = false;

    output << "b: " << b << endl;
    output << "copy: " << copy << endl;

    Vector c = arr ^ b;   // Проверка оператора ^

    Vector d;
    d = b;

    d[0] = false;

    output << "b: " << b << endl;
    output << "d: " << d << endl;

    Vector e;
    e = std::move(d);

    output << "e: " << e << endl;
    output << "d: " << d << endl;

    output << "c: " << c << endl;

    delete[] arr;

    return 0;
}
