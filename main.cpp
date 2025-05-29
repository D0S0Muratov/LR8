#include <iostream>
#include <string>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

int main() {
    string filename;
    int choice;

    cout << "Оберіть завдання (1 - масив, 2 - матриця, 3 - сортування): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Введіть ім'я вхідного файлу масиву: ";
        cin >> filename;
        process_array_task(filename);
    } else if (choice == 2) {
        cout << "Введіть ім'я вхідного файлу матриці: ";
        cin >> filename;
        process_matrix_task(filename);
    } else if (choice == 3) {
        cout << "Введіть ім'я вхідного файлу для сортування: ";
        cin >> filename;
        process_sorting_task(filename);
    } else {
        cout << "Невірний вибір." << endl;
    }

    return 0;
}
