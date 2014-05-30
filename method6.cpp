#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

int procedure6(City* &cities, int n, int w, int i) {
    if (i == n)
        return 0;
    long int cost = 1000000000;
    int dist = 0;
    int first = 0;
    int second = 0;
    for (int j = i+1; j <= n; j++) {
        dist += cities[j].distance;
        if (dist <= w) {
            first = cost;
            second = procedure6(cities, n, w, j) + cities[j].cost;
            cost = min(first, second);
        } else
            break;
    }
    return cost;
}

Path* dp6(City* &cities, int n, int w) {
    Path* solution = new Path;
    int cost;
    int stays;

    cost = procedure6(cities, n, w, 1);
    
    solution->cost = cost;

    return solution;
}

