#include "sales.h"

int main()
{
    srand(time(NULL));                                      //for random seed
    city cities[totalCities];
    int i;
    int totalPermutations;
    int* order = (int*)calloc(totalCities, sizeof(int));
    double recordDistance;
    int* bestEver;
    //filling the cities array with random numbers
    for (i = 0; i < totalCities; i++)
    {
        cities[i].x = rand() % width;
        cities[i].y = rand() % height;
        order[i] = i;
    }
    double d = calcDistance(cities, order, totalCities);    //calculating the total distance of the first order
    recordDistance = d;                                     //storing this distance
    bestEver = slice(order, totalCities);                   //storing the first order
    totalPermutations = factorial(totalCities);             //calculating the total permutations that the computer will go through
    printf("%d\n", totalPermutations);
    printf("best so far %lf\n", recordDistance);

    while(order)
    {
        order = nextOrder(order, totalCities);              //finding the next order of cities
        d = calcDistance(cities, order, totalCities);       //calculating the total distance with the new order
        if (d < recordDistance)
        {
            recordDistance = d;                             //resetting the record distance to a new distance if it is less than the previous
            bestEver = slice(order, totalCities);           //resetting the best ever order
            printf("best so far %lf\n", recordDistance);
        }
    }

    free(order);
    free(bestEver);
    return 0;
}
