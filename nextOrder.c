//This one to get the next order in the permutations
#include "sales.h"

//get largest i that arr[i] < arr[i + 1]
//get largest j that arr[largestI] < arr[j]
//swap arr[largestI] and arr[largestJ]
//reverse starting from arr[largestI+1] to end
int* nextOrder(int* order, int len)
{
    int outlen;
    int largestI = -1, largestJ = -1;
    int i, j;
    for (i = 0; i < len - 1; i++)
        if (order[i] < order[i + 1])
            largestI = i;

    if (largestI == -1)
    {
        printf("FINISHED\n");
        return NULL;
    }

    for (j = 0; j < len; j++)
        if (order[largestI] < order[j])
            largestJ = j;

    swap(order, largestI, largestJ);
    int* endArray = splice(order, largestI + 1, totalCities, &outlen);
    reverse(endArray, outlen);
    order = concat(order, totalCities-outlen, endArray, outlen);
    free(endArray);
    return order;
}