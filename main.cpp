// Emily Littleworth
// CS 130B Project 2
#include "city.h"
#include "method6.h"
#include "method7.h"
#include <iostream>
using namespace std;


int main() {
    int method, output_fmt, n, w, t, m;
    int i, j, d_i, c_i;
    int total_cost = 0;
    int total_stays = 0;

    cin >> method;
    cin >> output_fmt;
    cin >> n;
    cin >> w;
    cin >> t;
    cin >> m;

    // create a two-d array of city objects
    // REMEMBER: CITY ARRAYS ARE OF SIZE
    // N + 1 TO ACCOMODATE THE NON-EXISTANT CITY[0]
    n += 1;
    City** city_ptr = new City*[m];
    for (int i = 0; i < m; i++) {
        city_ptr[i] = new City[n];
    }

    // insert values in two-d array
    // the zero entries are empty (city[0] DNE)
    for (i = 0; i < m; i++) {
        city_ptr[i][0].distance = 0;
        city_ptr[i][0].cost = 0;
    }
    for (i = 0; i < m; i++) {
        for (j = 1; j < n; j++) {
            cin >> d_i;
            cin >> c_i;
            city_ptr[i][j].distance = d_i;
            city_ptr[i][j].cost = c_i;
        }
    }

    // DEBUG print two-d array
    //print_2d_city_array(city_ptr, m, n);

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
                p = dp6(city_ptr[i], n, w);
                cout << p->cost << "\n";
                total_cost += p->cost;
                //total_stays?
                delete p;
                break;
            case 7:
                p = dp7(city_ptr[i], n, w);
                cout << p->cost << "\n";
                cout << p->num_stays << "\n";
                total_cost += p->cost;
                total_stays += p->num_stays;
                delete p;
                break;
            case 8:
                break;
        }
    }
    cout << total_cost << "\n";
    cout << total_stays << "\n";

    return 1;
}
