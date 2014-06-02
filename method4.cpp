#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

void procedure4(City* cities, MatrixItem** matrix, int n, int w, int t) {
    int dist, first, second, first_cost, second_cost, min_cost;
    for (int i = n-1; i >= 1; i--) {
        for (int j = t+1; j > 0; j--) {
            dist = 0;
            for (int k = i+1; k <= n; k++) {
                dist += cities[k].distance;
                if (dist <= w) {
                    first = matrix[j][i].stays;
                    second = matrix[j-1][k].stays + 1;
                    if (first == second) {
                        first_cost = matrix[j][i].M;
                        second_cost = matrix[j-1][k].M + cities[k].cost;
                        if (first_cost == second_cost) {
                            matrix[j][i].unique = 0;
                            matrix[j][i].stays = second;
                            matrix[j][i].M = second_cost;
                            matrix[j][i].next_city = k;
                        } else {
                            min_cost = min(first_cost, second_cost);
                            // if min_cost = first_cost, don't update anything
                            if (min_cost == second_cost) {
                                matrix[j][i].unique = 1;
                                matrix[j][i].stays = second;
                                matrix[j][i].M = second_cost;
                                matrix[j][i].next_city = k;
                            }
                        }
                    } else {
                        matrix[j][i].stays = min(first, second);
                        // if matrix[j][i].stays == first, don't update anything
                        if (matrix[j][i].stays == second) {
                            matrix[j][i].unique = 1;
                            matrix[j][i].M = matrix[j-1][k].M + cities[k].cost;
                            matrix[j][i].next_city = k;
                        }
                    }
                } else
                    break;
            }
        }
    }
}

Path* dp4(City* cities, int n, int w, int output_fmt, int t) {
    Path* solution = new Path;
    int cost, stays, unique;
    int does_solution_exist = 1;
    int i, j;
    int min_cost = INF;

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

    for (i = 1; i < n; i++) {
        for (j = 0; j <= t+1; j++) {
            matrix[j][i].M = INF;
            matrix[j][i].stays = 0;
            matrix[j][i].next_city = 0;
            matrix[j][i].unique = 1;
        }
    }
    procedure4(cities, matrix, n, w, t);
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


