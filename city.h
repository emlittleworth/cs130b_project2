#ifndef CITY_H
#define CITY_H

struct City {
    int distance;
    int cost;
};

struct Path {
    int cost;
    int num_stays;
};

void print_2d_city_array(City**, int, int);

#endif
