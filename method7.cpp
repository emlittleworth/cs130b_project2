#include "city.h"
#include "other_func.h"
#include <iostream>
using namespace std;

int procedure7(City* &cities, int n, int w, int* &M, int i) {
    if (M[i] != 1000000000)
        return M[i];
    int dist = 0;
    for (int j = i+1; j <= n; j++) {
        dist += cities[j].distance;
        if (dist <= w)
            M[i] = min(M[i], procedure7(cities, n, w, M, j) + cities[j].cost);
        else
            break;
    }
    return M[i];
}

int num_stays7(City* &cities, int n, int* &M) {
    int sum = 0;
    int i = 1;
    while (i != n) {
        for (int j = i+1; j <= n; j++) {
            if (M[i] == M[j] + cities[j].cost) {
                sum++;
                i = j;
                break;
            }
        }
    }
    // subtract two since we are not counting p1 nor pn
    return sum - 2;
}

Path* dp7(City* &cities, int n, int w) {
    Path* solution = new Path;
    int* M = new int[n+1];
    int cost;
    int stays;

    for (int i = 0; i < n; i++) {
        M[i] = 1000000000;
    }
    M[n] = 0;

    cost = procedure7(cities, n, w, M, 1);
    stays = num_stays7(cities, n, M);

    for (int i = 0; i < n+1; i++) {
        cout << "M[" << i << "]: " << M[i] << ", ";
    }
    cout << "\n";
    
    solution->cost = cost;
    solution->num_stays = stays;
    
    delete[] M;
    return solution;
}
