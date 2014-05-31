#include "city.h"
#include <iostream>
using namespace std;

void print_city_matrix(City** city_ptr, int m, int n) {
    int dist, cost, M, stays;
    cout << "City array input:\n";
    for (int i = 0; i < m; i++) {
        cout << "m = " << i << "\n";
        for (int j = 0; j < n; j++) {
            dist = city_ptr[i][j].distance;
            cost = city_ptr[i][j].cost;
            M = city_ptr[i][j].M;
            stays = city_ptr[i][j].stays;
            cout << "city-" << j << ": ";
            cout << "(d = " << dist << ", c = " << cost << ") ";
            cout << ", M = " << M << ", s = " << stays << ") ";
            cout << "\n";
        }
        cout << "\n";
    }
}

void print_city_array(City* city_ptr, int n) {
    int dist, cost, M, stays;
    cout << "City array:\n";
    for (int i = 0; i < n; i++) {
        dist = city_ptr[i].distance;
        cost = city_ptr[i].cost;
        M = city_ptr[i].M;
        stays = city_ptr[i].stays;
        cout << "city-" << i << ": ";
        cout << "(d = " << dist << ", c = " << cost << ") ";
        cout << ", M = " << M << ", s = " << stays << ") ";
        cout << "\n";
    }
    cout << "\n";
}
