//вариант 21
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    system("chcp 65001 > nul");
    double x;
    cout << "Введите x:" << endl;
    cin >> x;
    const double pi = acos(-1.0);
    double E[] = { 1e-2, 1e-4, 1e-6, 1e-8 };
    cout << setprecision(10) << fixed;
    double d;

    for (int i = 0; i < 4; i++) {
        double k = E[i];
        cout << "Точность = " << k << endl;

        int n = 1;
        double p = 1;
        double p1 = p;
        d = k + 1;

        while (d > k) { //цикл while
            p1 = p;
            p = p * (1 - (4 * x * x) / ((2.0 * n - 1) * (2.0 * n - 1) * pi * pi));
            d = abs(p - p1);
            n++;
        }

        cout << "while: cos(x) = " << p << endl;
        cout << "Количество итераций = " << n - 1 << endl;

        n = 1;
        p = 1;
        p1 = p;
        d = k + 1;

        do { // цикл do while
            p1 = p;
            p = p * (1 - (4 * x * x) / ((2.0 * n - 1) * (2.0 * n - 1) * pi * pi));
            d = abs(p - p1);
            n++;
        } while (d > k);

        cout << "do while: cos(x) = " << p << endl;
        cout << "Количество итераций = " << n - 1 << endl;

        n = 1;
        p = 1;
        p1 = p;
        d = k + 1;

        for (; d > k; n++) { //цикл for
            p1 = p;
            p = p * (1 - (4 * x * x) / ((2.0 * n - 1) * (2.0 * n - 1) * pi * pi));
            d = abs(p - p1);
        }

        cout << "for: cos(x) = " << p << endl;
        cout << "Количество итераций = " << n - 1 << endl;
    }
}
