#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

// return answer to does_solution_exist? yes = 1, no = 0
int procedure5(City* cities, int** matrix, int n, int w, int t) {
    int dist, first, second, first_stays, second_stays, min_stays;
    for (int i = n-1; i >= 1; i--) {
        for (int j = t+1; j > 0; j--) {
            dist = 0;
            for (int k = i+1; k <= n; k++) {
                dist += cities[k].distance;
                if (dist <= w) {
                    first = matrix[j][i];
                    second = matrix[j-1][k] + cities[k].cost;
                    if (first == second) {
                        first_stays = cities[i].stays;
                        second_stays = cities[k].stays + 1;
                        if (first_stays == second_stays) {
                            cities[i].unique = 0;
                            matrix[j][i] = second;
                            cities[i].stays = second_stays;
                            cities[i].next_city = k;
                        } else {
                            min_stays = min(first_stays, second_stays);
                            // if min_stays = first_stays, don't update anything
                            if (min_stays == second_stays) {
                                cities[i].unique = 1;
                                matrix[j][i] = second;
                                cities[i].stays = second_stays;
                                cities[i].next_city = k;
                            }
                        }
                    } else {
                        matrix[j][i] = max(first, second);
                        // if matrix[j][i] == first, don't update anything
                        if (matrix[j][i] == second) {
                            cities[i].unique = 1;
                            cities[i].stays = cities[k].stays + 1;
                            cities[i].next_city = k;
                        }
                    }
                    //if ((cities[i].stays - 1) > t) return 0;
                    //if ((cities[i].stays - 1) > t) 
                    //    cout << "cities[" << i << "].stays - 1 > " << t << "\n";
                } else
                    break;
            }
        }
    }
    return 1;
}
