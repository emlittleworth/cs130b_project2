#include "city.h"
#include "other_func.h"
#include "method5.h"
#include <iostream>
using namespace std;

void procedure3(City* cities, MatrixItem** matrix, int n, int w, int t) {
    int dist, first, second, first_stays, second_stays, min_stays;
    for (int i = n-1; i >= 1; i--) {
        for (int j = t+1; j > 0; j--) {
            dist = 0;
            for (int k = i+1; k <= n; k++) {
                dist += cities[k].distance;
                if (dist <= w) {
                    first = matrix[j][i].M;
                    second = matrix[j-1][k].M + cities[k].cost;
                    if (first == second) {
                        first_stays = matrix[j][i].stays;
                        second_stays = matrix[j-1][k].stays + 1;
                        if (first_stays == second_stays) {
                            matrix[j][i].unique = 0;
                            matrix[j][i].M = second;
                            matrix[j][i].stays = second_stays;
                            matrix[j][i].next_city = k;
                        } else {
                            min_stays = min(first_stays, second_stays);
                            // if min_stays = first_stays, don't update anything
                            if (min_stays == second_stays) {
                                matrix[j][i].unique = 1;
                                matrix[j][i].M = second;
                                matrix[j][i].stays = second_stays;
                                matrix[j][i].next_city = k;
                            }
                        }
                    } else {
                        matrix[j][i].M = min(first, second);
                        // if matrix[j][i].M == first, don't update anything
                        if (matrix[j][i].M == second) {
                            matrix[j][i].unique = 1;
                            matrix[j][i].stays = matrix[j-1][k].stays + 1;
                            matrix[j][i].next_city = k;
                        }
                    }
                } else
                    break;
            }
        }
    }
}

Path* dp35(City* cities, int n, int w, int output_fmt, int t, int method) {
    Path* solution = new Path;
    int cost, stays, unique;
    int does_solution_exist = 1;
    int i, j;
    int min_cost = INF;
    int max_cost = 0;

    MatrixItem** matrix = new MatrixItem*[t+2];
    for (i = 0; i <= t+1; i++) {
        matrix[i] = new MatrixItem[n+1];
    }

    // set up matrix with initial conditions
    for (j = 0; j <= t+1; j++) {
        matrix[j][n].M = 0;
        matrix[j][n].stays = 0;
        matrix[j][n].next_city = 0;
        matrix[j][n].unique = 1;
    }
    if (method == 3) {
        for (i = 1; i < n; i++) {
            for (j = 0; j <= t+1; j++) {
                matrix[j][i].M = INF;
                matrix[j][i].stays = 0;
                matrix[j][i].next_city = 0;
                matrix[j][i].unique = 1;
            }
        }
        procedure3(cities, matrix, n, w, t);
        //print_matrix_M(matrix, t+2, n+1);
        //print_matrix_s(matrix, t+2, n+1);
        //print_matrix_n(matrix, t+2, n+1);
        //print_matrix_u(matrix, t+2, n+1);

        for (j = 0; j <= t+1; j++) {
            if (matrix[j][1].M != INF) {
                if (matrix[j][1].M < min_cost) {
                    min_cost = matrix[j][1].M;
                    cost = min_cost;
                }
            }
        }
        if (min_cost == INF || (matrix[t+1][1].stays-1) > t)
            does_solution_exist = 0;
    } else {
        //run procedure 5
        for (i = 1; i < n; i++) {
            for (j = 0; j <= t+1; j++) {
                matrix[j][i].M = 0;
                matrix[j][i].stays = 0;
                matrix[j][i].next_city = 0;
                matrix[j][i].unique = 1;
            }
        }
        procedure5(cities, matrix, n, w, t);
        //print_matrix_M(matrix, t+2, n+1);
        //print_matrix_s(matrix, t+2, n+1);
        //print_matrix_n(matrix, t+2, n+1);
        //print_matrix_u(matrix, t+2, n+1);

        for (j = 0; j <= t+1; j++) {
            if (matrix[j][1].M != 0) {
                if (matrix[j][1].M > max_cost) {
                    max_cost = matrix[j][1].M;
                }
            }
        }
        if (max_cost == 0 || (matrix[t+1][1].stays-1) > t)
            does_solution_exist = 0;
        cost = matrix[t][1].M;
    }

    if (does_solution_exist) {
        // note: stays = stays - 1 since we are
        // not counting city n as an overnight stay
        stays = matrix[t+1][1].stays - 1;
        unique = path_unique(matrix, t+1, n);
        
        solution->cost = cost;
        solution->stays = stays;

        cout << cost << "\n";
        cout << stays << "\n";
        if (unique)
            cout << "unique\n";
        else
            cout << "not unique\n";

        // print complete path if output_fmt == 2
        if (output_fmt == 2)
            print_path(matrix, t, n);
    } else {
        cout << "no solution\n";
        solution->cost = 0;
        solution->stays = 0;
    }
    cout << "\n";

    for (i = 0; i <= t+1; i++)
        delete[] matrix[i];
    delete[] matrix;

    return solution;
}


