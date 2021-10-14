//This one to get the next order in the permutations
#include "sales.h"

//I actually found this algorithm on the internet, it's also implemented in "the coding train"s video on the salesman problem
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
        if (order[i] < order[i + 1])        //get the largest index that arr[i] < arr[i+1]
            largestI = i;

    if (largestI == -1)                     //exit if there's no indices like that again
    {
        printf("FINISHED\n");
        return NULL;
    }

    for (j = 0; j < len; j++)
        if (order[largestI] < order[j])      //get the largest index that arr[largestI] < arr[j] 
            largestJ = j;

    swap(order, largestI, largestJ);        //swap arr[i] and arr[j]
    //reverse arr[largestI+1....n]
    int* endArray = splice(order, largestI + 1, totalCities, &outlen);  //cut the order array and save the cut in a variable 
    reverse(endArray, outlen);  //reverse endArray
    order = concat(order, totalCities-outlen, endArray, outlen);    //concatenate the reversed piece of order with the rest
    free(endArray);
    return order;
}
