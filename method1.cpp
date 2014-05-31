#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

// return answer to unique? yes = 1, no = 0
void procedure1(City* cities, int n, int w, int i) {
    int dist, cost_i, cost_j, stays_i, stays_j, min_stays;
    for (int i = n-1; i >= 1; i--) {
        dist = 0;
        for (int j = i+1; j <= n; j++) {
            dist += cities[j].distance;
            if (dist <= w) {
                cost_i = cities[i].M;
                cost_j = cities[j].M + cities[j].cost;
                // if cost_i == cost_j, the path is not unique
                // choose the path with the LEAST number
                // of overnight stays
                if (cost_i == cost_j) {
                    cities[i].unique = 0;
                    stays_i = cities[i].stays;
                    stays_j = cities[j].stays + 1;
                    min_stays = min(stays_i, stays_j);
                    // if min_stays = stays_i, don't update anything
                    if (min_stays == stays_j) {
                        cities[i].M = cost_j;
                        cities[i].stays = stays_j;
                        cities[i].next_city = j;
                    }
                } else {
                    cities[i].M = min(cost_i, cost_j);
                    // if cities[i].M == cost_i, don't update stays
                    if (cities[i].M == cost_j) {
                        cities[i].stays = cities[j].stays + 1;
                        cities[i].next_city = j;
                    }
                }
            } else
                break;
        }
    }
}

Path* dp1(City* cities, int n, int w, int output_fmt) {
    Path* solution = new Path;
    int unique;
    int cost;
    int stays;

    // define M[n] = 0
    cities[n].M = 0;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    procedure1(cities, n, w, 1);
    unique = path_unique(cities, n);
    cost = cities[1].M;
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    if (unique)
        cout << "unique" << "\n";
    else
        cout << "not unique" << "\n";

    // print complete path if output_fmt == 2
    if (output_fmt == 2)
        print_path(cities, n);

    cout << "\n";

    return solution;
}
