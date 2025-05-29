#include <fstream>
#include <iostream>
#include "matrix_utils.h"

using namespace std;

void get_matrix(string filename, int matrix[M][N], int &rows, int &cols) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }
    fin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fin >> matrix[i][j];
        }
    }
    fin.close();
}

void show_matrix(string filename, const int matrix[M][N], int rows, int cols) {
    ofstream fout(filename, ios::app);
    fout << "\nМатриця:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fout << matrix[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
}

void process_matrix_task(string filename) {
    int matrix[M][N], rows, cols;
    get_matrix(filename, matrix, rows, cols);

    int result = 0;
    for (int j = 0; j < cols; j++) {
        int pos = 0, neg = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > 0) pos++;
            else if (matrix[i][j] < 0) neg++;
        }
        if (pos == neg && pos != 0) {
            result = j + 1; // останній підходящий стовпець (нумерація з 1)
        }
    }

    ofstream fout(filename, ios::app);
    fout << "\nРезультат: ";
    fout << (result == 0 ? "0" : to_string(result)) << endl;
    fout.close();
}
