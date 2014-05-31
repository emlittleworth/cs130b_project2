#include "city.h"
#include "other_func.h"
#include <iostream>
#define INF 1000000000
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
            // if cities[i].M == current, don't update days
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

    cost = procedure7(cities, n, w, 1);
    stays = cities[1].stays;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    solution->cost = cost;
    solution->stays = stays - 1;

    //print_city_array(cities, n+1);

    return solution;
}
