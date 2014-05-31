#include "city.h"
#include "other_func.h"
#include <iostream>
#define INF 1000000000
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
            // if cost == current, don't update days
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

    cost = procedure6(cities, n, w, 1);
    stays = cities[1].stays;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    solution->cost = cost;
    solution->stays = stays - 1;

    //print_city_array(cities, n+1);

    return solution;
}
