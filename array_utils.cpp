#include <fstream>
#include <iostream>
#include <map>
#include "array_utils.h"

using namespace std;

void get_mas(string filename, int mas[], int &n) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> mas[i];
    }
    fin.close();
}

void show_mas(string filename, const int mas[], int n) {
    ofstream fout(filename);
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << mas[i] << " ";
    }
    fout << endl;
    fout.close();
}

void process_array_task(string filename) {
    int mas[N], n;
    get_mas(filename, mas, n);

    map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[mas[i]]++;
    }

    int new_n = 0;
    for (int i = 0; i < n; i++) {
        if (count[mas[i]] >= 3) {
            mas[new_n++] = mas[i];
        }
    }

    cout << "Новий розмір масиву: " << new_n << endl;
    for (int i = 0; i < new_n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;

    show_mas("array_out_98.txt", mas, new_n);
}

void process_sorting_task(string filename) {
    double mas[7];
    ifstream fin(filename);
    if (!fin) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }
    for (int i = 0; i < 7; i++) {
        fin >> mas[i];
    }
    fin.close();

    // Сортування бульбашкою за спаданням
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i; j++) {
            if (mas[j] < mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
            }
        }
    }

    ofstream fout("sorted_out.txt");
    fout << "Відсортований масив: ";
    for (int i = 0; i < 7; i++) {
        fout << mas[i] << " ";
    }
    fout << endl;
    fout.close();
}
