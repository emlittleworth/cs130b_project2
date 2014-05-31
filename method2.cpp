#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

void procedure2(City* cities, int n, int w, int i) {
    int dist, cost_i, cost_j, stays_i, stays_j, min_cost;
    for (int i = n-1; i >= 1; i--) {
        dist = 0;
        for (int j = i+1; j <= n; j++) {
            dist += cities[j].distance;
            if (dist <= w) {
                // rather than considering cost first, let's consider
                // number of stays first
                stays_i = cities[i].stays;
                stays_j = cities[j].stays + 1;
                // if stays_i == stays_j, the path is not unique
                // choose the path with the LEAST cost
                if (stays_i == stays_j) {
                    cost_i = cities[i].M;
                    cost_j = cities[j].M + cities[j].cost;
                    if (cost_i == cost_j) {
                        cities[i].unique = 0;
                        cities[i].M = cost_j;
                        cities[i].stays = stays_j;
                        cities[i].next_city = j;
                    } else {
                        min_cost = min(cost_i, cost_j);
                        // if min_cost == cost_i, don't update anything
                        if (min_cost == cost_j) {
                            cities[i].unique = 1;
                            cities[i].M = cost_j;
                            cities[i].stays = stays_j;
                            cities[i].next_city = j;
                        }
                    }
                } else {
                    cities[i].stays = min(stays_i, stays_j);
                    // if cities[i].stays == stays_i, don't update cost
                    if (cities[i].stays == stays_j) {
                        cities[i].unique = 1;
                        cities[i].M = cities[j].M + cities[j].cost;
                        cities[i].next_city = j;
                    }
                }
            } else
                break;
        }
    }
}
