#include "other_func.h"
#include "city.h"
#include <iostream>
using namespace std;

int min(int i, int j) {
    if (i < j)
        return i;
    else if (i > j)
        return j;
    else
        return i;
}

int max(int i, int j) {
    if (i > j)
        return i;
    else if (i < j)
        return j;
    else
        return i;
}

void print_path(City* cities, int n) {
    int i = 1;
    while(cities[i].next_city != n) {
        cout << cities[i].next_city << "\n";
        i = cities[i].next_city;
    }
}

void print_path(MatrixItem** matrix, int j, int n) {
    int index = 1;
    while(matrix[j][index].next_city != n && matrix[j][index].next_city != 0) {
        cout << matrix[j][index].next_city << "\n";
        index = matrix[j][index].next_city;
    }
}

void print_matrix_M(MatrixItem** matrix, int j, int i) {
    cout << "Matrix M values:\n";
    for (int m = 0; m < j; m++) {
        cout << m << " - [";
        for (int n = 0; n < i; n++) {
            if (matrix[m][n].M == INF) {
                //cout << "(M:I,s:" << matrix[m][n].stays;
                //cout << ",nc:" << matrix[m][n].next_city << ",u?:" << matrix[m][n].unique << ")";
                cout << "I ";
            } else {
                //cout << "(M:" << matrix[m][n].M << ",s:" << matrix[m][n].stays;
                //cout << ",nc:" << matrix[m][n].next_city << ",u?:" << matrix[m][n].unique << ")";
                cout << matrix[m][n].M << " ";
            }
        }
        cout << "]\n";
    }
}

void print_matrix_s(MatrixItem** matrix, int j, int i) {
    cout << "Matrix stays:\n";
    for (int m = 0; m < j; m++) {
        cout << m << " - [";
        for (int n = 0; n < i; n++) {
            cout << matrix[m][n].stays << " ";
        }
        cout << "]\n";
    }
}

void print_matrix_n(MatrixItem** matrix, int j, int i) {
    cout << "Matrix next cities:\n";
    for (int m = 0; m < j; m++) {
        cout << m << " - [";
        for (int n = 0; n < i; n++) {
            cout << matrix[m][n].next_city << " ";
        }
        cout << "]\n";
    }
}

void print_matrix_u(MatrixItem** matrix, int j, int i) {
    cout << "Matrix unique? values:\n";
    for (int m = 0; m < j; m++) {
        cout << m << " - [";
        for (int n = 0; n < i; n++) {
            cout << matrix[m][n].unique << " ";
        }
        cout << "]\n";
    }
}

int path_unique(City* cities, int n) {
    int i = 1;
    while(cities[i].next_city != n) {
        if (cities[i].unique == 0)
            return 0;
        i = cities[i].next_city;
    }
    return 1;
}

int path_unique(MatrixItem** matrix, int j, int n) {
    int index = 1;
    while(matrix[j][index].next_city != n) {
        if (matrix[j][index].unique == 0)
            return 0;
        index = matrix[j][index].next_city;
    }
    return 1;
}
