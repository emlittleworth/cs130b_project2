#include "city.h"
#include "other_func.h"
#include "method5.h"
#include <iostream>
using namespace std;

// return answer to does_solution_exist? yes = 1, no = 0
int procedure3(City* cities, int** matrix, int n, int w, int t) {
    int dist, first, second, first_stays, second_stays, min_stays;
    for (int i = n-1; i >= 1; i--) {
        for (int j = t+1; j > 0; j--) {
            dist = 0;
            for (int k = i+1; k <= n; k++) {
                dist += cities[k].distance;
                if (dist <= w) {
                    first = matrix[j][i];
                    second = matrix[j-1][k] + cities[k].cost;
                    if (first == second) {
                        first_stays = cities[i].stays;
                        second_stays = cities[k].stays + 1;
                        if (first_stays == second_stays) {
                            cities[i].unique = 0;
                            matrix[j][i] = second;
                            cities[i].stays = second_stays;
                            cities[i].next_city = k;
                        } else {
                            min_stays = min(first_stays, second_stays);
                            // if min_stays = first_stays, don't update anything
                            if (min_stays == second_stays) {
                                cities[i].unique = 1;
                                matrix[j][i] = second;
                                cities[i].stays = second_stays;
                                cities[i].next_city = k;
                            }
                        }
                    } else {
                        matrix[j][i] = min(first, second);
                        // if matrix[j][i] == first, don't update anything
                        if (matrix[j][i] == second) {
                            cities[i].unique = 1;
                            cities[i].stays = cities[k].stays + 1;
                            cities[i].next_city = k;
                        }
                    }
                    //if ((cities[i].stays - 1) > t) return 0;
                    //if ((cities[i].stays - 1) > t) 
                    //    cout << "cities[" << i << "].stays - 1 > " << t << "\n";
                } else
                    break;
            }
        }
    }
    return 1;
}

Path* dp35(City* cities, int n, int w, int output_fmt, int t, int method) {
    Path* solution = new Path;
    int unique;
    int cost;
    int stays;
    int does_solution_exist;

    int** matrix = new int*[t+2];
    for (int i = 0; i < t+2; i++)
        matrix[i] = new int[n+1];

    // satisfy initial conditions
    // (a)
    for (int j = 1; j <= t+1; j++)
        matrix[j][n] = 0;
    // (b)
    matrix[0][n] = 0;

    if (method == 3) {
        // (c)
        for (int i = 1; i < n; i++)
            for (int j = 1; j < t+1; j++)
                matrix[j][i] = INF;
        does_solution_exist = procedure3(cities, matrix, n, w, t); // return value isn't correct
    } else {
        // (c)
        for (int i = 1; i < n; i++)
            for (int j = 1; j < t+1; j++)
                matrix[j][i] = 0;
        does_solution_exist = procedure5(cities, matrix, n, w, t); // return value isn't correct
    }
    
    if ((cities[1].stays - 1) > t)
        does_solution_exist = 0;

    if (does_solution_exist) {
        // note: stays = stays - 1 since we are
        // not counting city n as an overnight stay
        unique = path_unique(cities, n);
        cost = matrix[t][1];
        stays = cities[1].stays - 1;

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
            print_path(cities, n);
    } else {
        cout << "no solution\n";
        solution->cost = 0;
        solution->stays = 0;
    }
    print_matrix(matrix, t+2, n+1);
    print_city_array(cities, n+1);

    cout << "\n";

    return solution;
}


