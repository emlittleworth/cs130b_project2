// Emily Littleworth
// CS 130B Project 2
#include "city.h"
#include "method6.h"
#include "method7.h"
#include "method8.h"
#include <iostream>
#define INF 1000000000
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
    }
    for (i = 0; i < m; i++) {
        for (j = 1; j < new_n; j++) {
            cin >> d_i;
            cin >> c_i;
            city_matrix[i][j].distance = d_i;
            city_matrix[i][j].cost = c_i;
            city_matrix[i][j].M = INF;
            city_matrix[i][j].stays = 0;
        }
    }

    // DEBUG print two-d array
    //print_city_matrix(city_matrix, m, new_n);

    // for each m instances, run method
    for (i = 0; i < m; i++) {
        Path* p;
        switch (method) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                p = dp6(city_matrix[i], n, w);
                break;
            case 7:
                p = dp7(city_matrix[i], n, w);
                break;
            case 8:
                p = dp8(city_matrix[i], n, w);
                break;
        }
        cout << p->cost << "\n";
        cout << p->stays << "\n";
        total_cost += p->cost;
        total_stays += p->stays;
        delete p;
        cout << "\n";
    }
    cout << total_cost << "\n";
    cout << total_stays << "\n";

    return 1;
}
