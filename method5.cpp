#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

void procedure5(City* cities, MatrixItem** matrix, int n, int w, int t) {
    int dist, first, second, first_stays, second_stays, min_stays;
    for (int i = n-1; i >= 1; i--) {
        for (int j = t+1; j > 0; j--) {
            dist = 0;
            for (int k = i+1; k <= n; k++) {
                dist += cities[k].distance;
                if (dist <= w /*&& (matrix[j-1][k].stays + 1 < j - 1)*/){
                    first = matrix[j][i].M;
                    second = matrix[j-1][k].M + cities[k].cost;
                    if (first == second) {
                        if (k == n) {
                            matrix[j][i].M = second;
                            matrix[j][i].stays = matrix[j-1][k].stays + 1;
                            matrix[j][i].next_city = k;
                        } else {
                            first_stays = matrix[j][i].stays;
                            second_stays = matrix[j-1][k].stays + 1;
                            if (first_stays == second_stays) {
                                matrix[j][i].unique = 0;
                                matrix[j][i].M = second;
                                matrix[j][i].stays = second_stays;
                                matrix[j][i].next_city = k;
                            } else {
                                min_stays = min(first_stays, second_stays);
                                // if min_stays = first_stays, don't update anything
                                if (min_stays == second_stays) {
                                    matrix[j][i].unique = 1;
                                    matrix[j][i].M = second;
                                    matrix[j][i].stays = second_stays;
                                    matrix[j][i].next_city = k;
                                }
                            }
                        }
                    } else {
                        matrix[j][i].M = max(first, second);
                        // if matrix[j][i].M == first, don't update anything
                        if (matrix[j][i].M == second) {
                            matrix[j][i].unique = 1;
                            matrix[j][i].stays = matrix[j-1][k].stays + 1;
                            matrix[j][i].next_city = k;
                        }
                    }
                } else
                    break;
            }
        }
    }
}
