/* This is an array handling file to cut arrays and separate them
   and reverse them.. can be useful in other apps idk*/
// contains slice, splice, concat, and reverse

#include "sales.h"

int* slice(const int* order, int len) //returns a copy of what's inside
{
    int* res = (int*)calloc(len, sizeof(int));
    int i;
    for (i = 0; i < len; i++)
        res[i] = order[i];
    return res;
}

void reverse(int* arr, int len)  //reverses an input array
{
    int i, j, temp;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// concatenates two arrays and returns the result
int* concat(const int* ord1, int n1, const int* ord2, int n2)
{
    int* res = (int*)calloc((n1 + n2), sizeof(int));
    int i;
    for (i = 0; i < n1; i++)
        res[i] = ord1[i];
    for (; i < (n1+n2); i++)
        res[i] = ord2[i-n1];
    return res;
}

//takes the array, copies it to the output from index to the end
//then cuts that piece of the array
int* splice(int* order, int index, int len, int* outlen)
{
    int i;
    *outlen = len - index;
    int* res = (int*)calloc(*outlen, sizeof(int));
    for (i = index; i < len; i++)
        res[i-index] = order[i];
    order[index] = 0;
    order = (int*) realloc(order, (index+1) * sizeof(int));
    return res;
}
