#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

void procedure8(City* cities, int n, int w, int i) {
    int dist, cost_i, cost_j;
    for (int i = n-1; i >= 1; i--) {
        dist = 0;
        for (int j = i+1; j <= n; j++) {
            dist += cities[j].distance;
            if (dist <= w) {
                cost_i = cities[i].M;
                cost_j = cities[j].M + cities[j].cost;
                cities[i].M = min(cost_i, cost_j);
                // if cities[i].M == cost_i, don't update stays
                if (cities[i].M == cost_j)
                    cities[i].stays = cities[j].stays + 1;
            } else
                break;
        }
    }
}

Path* dp8(City* cities, int n, int w) {
    Path* solution = new Path;
    int cost;
    int stays;

    // define M[n] = 0
    cities[n].M = 0;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    procedure8(cities, n, w, 1);
    cost = cities[1].M;
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    cout << "\n";

    return solution;
}
