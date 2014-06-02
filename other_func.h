#ifndef OTHER_FUNC_H
#define OTHER_FUNC_H
#include "city.h"
#define INF 1000000000

int min(int, int);

int max(int, int);

void print_path(City*, int);
void print_path(MatrixItem**, int, int);

void print_matrix_M(MatrixItem**, int, int);
void print_matrix_s(MatrixItem**, int, int);
void print_matrix_n(MatrixItem**, int, int);
void print_matrix_u(MatrixItem**, int, int);

int path_unique(City*, int);
int path_unique(MatrixItem**, int, int);

#endif
