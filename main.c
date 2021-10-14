#include "sales.h"

int main()
{
    srand(time(NULL));
    city cities[totalCities];
    int i;
    int totalPermutations;
    int outlen;
    int* order = (int*)calloc(totalCities, sizeof(int));
    double recordDistance;
    int* bestEver;
    for (i = 0; i < totalCities; i++)
    {
        cities[i].x = rand() % width;
        cities[i].y = rand() % height;
        order[i] = i;
    }
    double d = calcDistance(cities, order, totalCities);
    recordDistance = d;
    bestEver = slice(order, totalCities);
    totalPermutations = factorial(totalCities);
    printf("%d\n", totalPermutations);
    printf("best so far %lf\n", recordDistance);

    while(order)
    {
        order = nextOrder(order, totalCities);
        d = calcDistance(cities, order, totalCities);
        if (d < recordDistance)
        {
            recordDistance = d;
            bestEver = slice(order, totalCities);
            printf("best so far %lf\n", recordDistance);
        }
    }

    free(order);
    free(bestEver);
    return 0;
}