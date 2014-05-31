#include "city.h"
#include <iostream>
using namespace std;

int min(int i, int j) {
    if (i < j)
        return i;
    else if (i > j)
        return j;
    else
        return i;
}

void print_path(City* cities, int n) {
    int i = 1;
    while(cities[i].next_city != n) {
        cout << cities[i].next_city << "\n";
        i = cities[i].next_city;
    }
}

int path_unique(City* cities, int n) {
    int i = 1;
    while(cities[i].next_city != n) {
        if (cities[i].unique == 0)
            return 0;
        i = cities[i].next_city;
    }
    return 1;
}
