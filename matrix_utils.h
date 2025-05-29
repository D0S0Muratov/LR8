#pragma once
#include <string>
using namespace std;

const int M = 20;

void get_matrix(string filename, int matrix[M][N], int &rows, int &cols);
void show_matrix(string filename, const int matrix[M][N], int rows, int cols);
void process_matrix_task(string filename);
