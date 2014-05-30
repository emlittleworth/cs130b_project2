#include "city.h"
#include <iostream>
using namespace std;

void print_2d_city_array(City** city_ptr, int m, int n) {
    int dist, cost;
    cout << "City array input:\n";
    for (int i = 0; i < m; i++) {
        cout << "m = " << i << "\n";
        for (int j = 0; j < n; j++) {
            dist = city_ptr[i][j].distance;
            cost = city_ptr[i][j].cost;
            cout << "city-" << j << ": ";
            cout << "(d = " << dist << ", c = " << cost << ") ";
            cout << "\n";
        }
        cout << "\n";
    }
}

