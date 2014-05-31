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
