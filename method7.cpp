#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

int procedure7(City* cities, int n, int w, int i) {
    if (cities[i].M != INF)
        return cities[i].M;
    int dist = 0;
    int current = 0;
    int newcost = 0;
    for (int j = i+1; j <= n; j++) {
        dist += cities[j].distance;
        if (dist <= w) {
            current = cities[i].M;
            newcost = procedure7(cities, n, w, j) + cities[j].cost;
            cities[i].M = min(current, newcost);
            // if cities[i].M == current, don't update stays
            if (cities[i].M == newcost)
                cities[i].stays = cities[j].stays + 1;
        } else
            break;
    }
    return cities[i].M;
}

Path* dp7(City* cities, int n, int w) {
    Path* solution = new Path;
    int cost;
    int stays;

    // define M[n] = 0
    cities[n].M = 0;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    cost = procedure7(cities, n, w, 1);
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    cout << "\n";

    return solution;
}
