#include "sales.h"

// returns the distance between two points on a 2D plan
double dist(city* c1, city* c2)
{
    int xdiff = (c1->x) - (c2->x); //x1 - x2
    int ydiff = (c1->y) - (c2->y); //y1 - y2
    
    // sqrt(xdiff squared + ydiff squared)
    double distance = sqrt((xdiff * xdiff) + (ydiff * ydiff));
    return distance;
}

double calcDistance(city* cities, int* order, int ordlen)
{
    double d, sum = 0;
    int i;
    city cityA, cityB;
    for (i = 0; i < ordlen - 1; i++)
    {
        cityA = cities[order[i]];
        cityB = cities[order[i+1]];
        d = dist(&cityA, &cityB);
        sum += d;
    }
    return sum;
}