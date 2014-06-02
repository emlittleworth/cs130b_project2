#ifndef CITY_H
#define CITY_H

struct City {
    int distance;
    int cost;
    long int M;
    int stays;
    int next_city;
    int unique;
};

struct Path {
    int cost;
    int stays;
};

struct MatrixItem {
    long int M;
    int stays;
    int next_city;
    int unique;
};

void print_city_matrix(City**, int, int);

void print_city_array(City*, int);

#endif
