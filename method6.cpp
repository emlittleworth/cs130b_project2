#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

int procedure6(City* cities, int n, int w, int i) {
    if (i == n)
        return 0;
    long int cost = INF;
    int dist = 0;
    int current = 0;
    int newcost = 0;
    for (int j = i+1; j <= n; j++) {
        dist += cities[j].distance;
        if (dist <= w) {
            current = cost;
            newcost = procedure6(cities, n, w, j) + cities[j].cost;
            cost = min(current, newcost);
            // if cost == current, don't update stays
            if (cost == newcost)
                cities[i].stays = cities[j].stays + 1;
        } else
            break;
    }
    return cost;
}

Path* dp6(City* cities, int n, int w) {
    Path* solution = new Path;
    int cost;
    int stays;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    cost = procedure6(cities, n, w, 1);
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    cout << "\n";

    return solution;
}
