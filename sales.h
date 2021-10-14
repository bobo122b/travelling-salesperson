#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//total cities, the height and the width can be changed depending
//how large is your screen and how many cities you want.
#define totalCities 10                  //the total number of cities I'm using, you can change them but be careful with your processot, don't make it higher than 11
#define width 400                       //width of the map
#define height 600                      //height of the map

//the swapping function
#define swap(arr, i, j) \
        int temp = arr[i]; \
        arr[i] = arr[j]; \
        arr[j] = temp \

typedef struct city 
{
    int x;
    int y;
} city;

double calcDistance(city* cities, int* order, int ordlen);        //done
double dist(city* c1, city* c2);                                  //done
int factorial(int n);                                             //done
int* slice(const int* order, int len);                            //done
int* concat(const int* ord1, int n1, const int* ord2, int n2);    //done
int* splice(int* order, int index, int len, int* outlen);         //done
int* nextOrder(int* order, int len);                              //done
void reverse(int* arr, int len);                                  //done
