// Emily Littleworth
// CS 130B Project 2
#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;


int main() {
    int method, output_fmt, n, w, t, m;
    int i, j, d_i, c_i, new_n;
    int total_cost = 0;
    int total_stays = 0;

    cin >> method;
    cin >> output_fmt;
    cin >> n;
    cin >> w;
    cin >> t;
    cin >> m;

    // create a two-d array of city objects
    // note: city arrays are of size n+1
    // to accomodate the city[0] which DNE 
    new_n = n + 1; // extend n for correct indexing
    City** city_matrix = new City*[m];
    for (int i = 0; i < m; i++) {
        city_matrix[i] = new City[new_n];
    }

    // insert values in two-d array
    // the zero entries are empty since city[0] DNE
    for (i = 0; i < m; i++) {
        city_matrix[i][0].distance = -1;
        city_matrix[i][0].cost = -1;
        city_matrix[i][0].M = -1;
        city_matrix[i][0].stays = -1;
        city_matrix[i][0].next_city = -1;
        city_matrix[i][0].unique = -1;
    }
    for (i = 0; i < m; i++) {
        for (j = 1; j < new_n; j++) {
            cin >> d_i;
            cin >> c_i;
            city_matrix[i][j].distance = d_i;
            city_matrix[i][j].cost = c_i;
            city_matrix[i][j].M = INF;
            city_matrix[i][j].stays = INF;
            city_matrix[i][j].next_city = 0;
            city_matrix[i][j].unique = 1;
        }
    }

    // note: cities[n]. M = cities[n].stays = 0
    for (i = 0; i < m; i++) {
        city_matrix[i][n].M = 0;
        city_matrix[i][n].stays = 0;
    }

    // print two-d array
    //print_city_matrix(city_matrix, m, new_n);

    // for each m instances, run method
    for (i = 0; i < m; i++) {
        Path* p;
        switch (method) {
            case 1:
                p = dp12(city_matrix[i], n, w, output_fmt, method);
                break;
            case 2:
                p = dp12(city_matrix[i], n, w, output_fmt, method);
                break;
            case 3:
                p = dp345(city_matrix[i], n, w, output_fmt, method, t);
                break;
            case 4:
                p = dp345(city_matrix[i], n, w, output_fmt, method, t);
                break;
            case 5:
                break;
            case 6:
                p = dp67(city_matrix[i], n, w, method);
                break;
            case 7:
                p = dp67(city_matrix[i], n, w, method);
                break;
            case 8:
                p = dp8(city_matrix[i], n, w);
                break;
        }
        total_cost += p->cost;
        total_stays += p->stays;
        delete p;
    }
    cout << total_cost << "\n";
    cout << total_stays << "\n";

    return 1;
}
