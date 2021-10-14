#include "sales.h"
//a simple factorial function that calculates the factorial of a number recursively
int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return (n * factorial(n - 1));
}
