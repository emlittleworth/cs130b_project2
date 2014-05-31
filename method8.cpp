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
