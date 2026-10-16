//вариант 21
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    string nameItem; //название предмета
    double weight; //вес в кг
};

struct Passenger {
    string namePassenger; //ФИО пассажира
    vector<Item> items; //список предметов багажа
    int count = 1; //количество предметов
};

int main() {
    system("chcp 65001 > nul");
    int n;
    cout << "Введите количество пассажиров: ";
    cin >> n;
    cin.ignore();

    vector<Passenger> passengers(n);
    int k = 0;

    for (int i = 0; i < n; i++) {
        string check;
        cout << "Введите ФИО пассажира: " << endl;
        getline(cin, passengers[i].namePassenger);
        cout << "Введите количество предметов в багаже: " << endl;
        getline(cin, check);
        passengers[i].count = check != "" ? stoi(check) : 1;
        passengers[i].items.resize(passengers[i].count);
        for (int j = 0; j < passengers[i].count; j++) {
            cout << "Введите название предмета багажа: " << endl;
            getline(cin, passengers[i].items[j].nameItem);
            cout << "Введите вес предмета багажа: " << endl;
            cin >> passengers[i].items[j].weight;
            cin.ignore();
        }
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << passengers[i].namePassenger << endl;
        cout << passengers[i].count << endl;
        double sum = 0;
        for (int j = 0; j < passengers[i].count; j++) {
            cout << passengers[i].items[j].nameItem << endl;
            cout << passengers[i].items[j].weight << endl;
            sum += passengers[i].items[j].weight;
        }
        if (sum > 30) k++;
    }

    cout << "Количество пассажиров, общий вес багажа которых превышает 30 кг: " << k << endl;
    return 0;
}