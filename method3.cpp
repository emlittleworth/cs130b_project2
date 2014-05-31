#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

// return answer to solution? yes = 1, no = 0
int procedure3(City* cities, int n, int w, int t, int i) {
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
                    stays_i = cities[i].stays;
                    stays_j = cities[j].stays + 1;
                    if (stays_i == stays_j) {
                        //if ((stays_i - 1) > t) return 0;
                        cities[i].unique = 0;
                        cities[i].M = cost_j;
                        cities[i].stays = stays_j;
                        cities[i].next_city = j;
                    } else {
                        min_stays = min(stays_i, stays_j);
                        // if min_stays = stays_i, don't update anything
                        if (min_stays == stays_j) {
                            //if ((min_stays - 1) > t) return 0;
                            cities[i].unique = 1;
                            cities[i].M = cost_j;
                            cities[i].stays = stays_j;
                            cities[i].next_city = j;
                        }
                    }
                } else {
                    cities[i].M = min(cost_i, cost_j);
                    // if cities[i].M == cost_i, don't update stays
                    if (cities[i].M == cost_j) {
                        //if ((cities[j].stays + 1 - 1) > t) return 0;
                        cities[i].unique = 1;
                        cities[i].stays = cities[j].stays + 1;
                        cities[i].next_city = j;
                    }
                } 
            } else
                break;
        }
        if ((cities[i].stays - 1) > t) return 0;
    }
    return 1;
}
