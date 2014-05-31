#include "city.h"
#include "method1.h"
#include "method2.h"
#include "method6.h"
#include "method7.h"
#include "method8.h"
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

Path* dp12(City* cities, int n, int w, int output_fmt, int method) {
    Path* solution = new Path;
    int unique;
    int cost;
    int stays;

    if (method == 1)
        procedure1(cities, n, w, 1);
    else
        procedure2(cities, n, w, 1);

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    unique = path_unique(cities, n);
    cost = cities[1].M;
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    if (unique)
        cout << "unique" << "\n";
    else
        cout << "not unique" << "\n";

    // print complete path if output_fmt == 2
    if (output_fmt == 2)
        print_path(cities, n);

    cout << "\n";

    return solution;
}

Path* dp67(City* cities, int n, int w, int method) {
    Path* solution = new Path;
    int cost;
    int stays;

    if (method == 6)
        cost = procedure6(cities, n, w, 1);
    else
        cost = procedure7(cities, n, w, 1);
    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    cout << "\n";

    return solution;
}

Path* dp8(City* cities, int n, int w) {
    Path* solution = new Path;
    int cost;
    int stays;

    // note: stays = stays - 1 since we are
    // not counting city n as an overnight stay
    procedure8(cities, n, w, 1);
    cost = cities[1].M;
    stays = cities[1].stays - 1;

    solution->cost = cost;
    solution->stays = stays;

    //print_city_array(cities, n+1);
    cout << cost << "\n";
    cout << stays << "\n";
    cout << "\n";

    return solution;
}
