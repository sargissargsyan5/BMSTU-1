#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct School {
    string city;
    int number;
    string specialization;
    int students;
};

void print_school(ostream &out, vector<School> & school)
{
    for (auto & pos : school)
        out << pos.city << ". " << pos.number << ". "
            << pos.specialization << ", " << pos.students
            << " учеников" << endl;
}

int main(int argc, const char* argv[]) {
    system("chcp 65001 > nul");
    if (argc != 4) {
        cerr << "Error: Use four parameters";
        return 5;
    }

    const string mode(argv[1]);
    const string open_mode(argv[2]);
    const string file_name(argv[3]);

    int n;
    vector<School> school;

    if (mode == "write") {
        cout << "Режим записи" << endl;

        cout << "n = ";
        cin >> n;

        school.resize(n);

        for (int i = 0; i < n; i++) {
            cout << "School N = " << i + 1 << endl;

            cout << "City: ";
            cin.ignore();
            getline(cin, school[i].city);

            cout << "Number: ";
            cin >> school[i].number;

            cout << "Specialization: ";
            cin.ignore();
            getline(cin, school[i].specialization);

            cout << "Students: ";
            cin >> school[i].students;
        }

        if (open_mode == "text") {
            cout << "Текстовый режим" << endl;

            ofstream fout(file_name);

            fout << n << endl;

            for (auto &pos : school) {
                fout << pos.city << endl;
                fout << pos.number << endl;
                fout << pos.specialization << endl;
                fout << pos.students << endl;
            }

            fout.close();
        }
        else if (open_mode == "binary") {
            cout << "Двоичный режим" << endl;

            ofstream foutb(file_name, ios::binary);

            foutb.write((char*)&n, sizeof(n));

            for (auto &pos : school) {
                foutb << pos.city << ends;
                foutb.write((char*)&pos.number, sizeof(pos.number));

                foutb << pos.specialization << ends;
                foutb.write((char*)&pos.students, sizeof(pos.students));
            }

            foutb.close();
        }
        else {
            cout << "Неизвестный режим файла" << endl;
        }
    }

    else if (mode == "read") {
        cout << "Режим чтения" << endl;

        if (open_mode == "text") {
            cout << "Текстовый режим" << endl;

            ifstream fin(file_name);

            fin >> n;
            fin.ignore();

            school.resize(n);

            for (auto &pos : school) {
                getline(fin, pos.city);

                fin >> pos.number;
                fin.ignore();

                getline(fin, pos.specialization);

                fin >> pos.students;
                fin.ignore();
            }

            fin.close();

            print_school(cout, school);
        }

        else if (open_mode == "binary") {
            cout << "Двоичный режим" << endl;

            ifstream finb(file_name, ios::binary);

            finb.read((char*)&n, sizeof(n));

            school.resize(n);

            for (auto &pos : school) {
                getline(finb, pos.city, '\0');

                finb.read((char*)&pos.number, sizeof(pos.number));

                getline(finb, pos.specialization, '\0');

                finb.read((char*)&pos.students, sizeof(pos.students));
            }

            finb.close();

            print_school(cout, school);
        }

        else {
            cout << "Неизвестный режим файла" << endl;
        }
    }

    else {
        cout << "Неизвестный режим работы" << endl;
    }

    return 0;
}
