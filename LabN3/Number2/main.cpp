// вариант 21

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class k {
protected:
    double n;

public:
    k(double n) {
        this->n = n;
    }

    virtual double module() {
        return abs(n);
    }

    virtual void print() {
        cout << "Вещественное число: " << n << endl;
        cout << "Модуль числа: " << module() << endl;
    }

    virtual ~k() = default;
};

class t: public k {
protected:
    double m;

public:
    t(double n, double m) : k(n) {
        this->m = m;
    }

    double module() override {
        return sqrt(n * n + m * m);
    }

    void print() override {
        cout << "Комплексное число: " << n
             << " + " << m << "i" << endl;
        cout << "Модуль числа: " << module() << endl;
    }
};

int main() {
    k a(-5); // Объект вещественного числа
    t b(3, 4); // Объект комплексного числа

    // Вызов функций
    a.print();
    b.print();

    // Статический полиморфизм
    cout << "Статический полиморфизм:" << endl;
    cout << a.module() << endl;

    // Динамический полиморфизм
    cout << "Динамический полиморфизм:" << endl;
    k* ptr = &b;
    ptr->print();

    // Вектор указателей на объекты классов
    vector<k*> v;
    v.push_back(&a);
    v.push_back(&b);

    double sum = 0;

    cout << "Данные всех объектов:" << endl;

    for (k* p : v) {
        p->print();
        sum += p->module();
    }

    cout << "Сумма модулей: " << sum << endl;

    return 0;
}
