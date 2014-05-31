#ifndef CITY_H
#define CITY_H

struct City {
    int distance;
    int cost;
    long int M;
    int stays;
};

struct Path {
    int cost;
    int stays;
};

void print_city_matrix(City**, int, int);

void print_city_array(City*, int);

#endif
