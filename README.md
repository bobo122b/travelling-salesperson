# travelling-salesperson
A travelling salesperson simple algorithm that goes through all the possible probabilities.

the array handling functions can be used in future projects as ready functions, i guess i will try to refactor them in another time and provide more functions and add them to their own repository.

this algorithm of finding the order starts with an order from 0 to total cities, but then in the nextOrder() function it changes this order array to provide all the possible orders, by this way we can access the elements in the cities array by any possible combination of indices

ex: for an order array of 3 elements it will provide orders as:

    0  1  2
    
    0  2  1
    
    1  0  2
    
    1  2  0
    
    2  0  1
    
    2  1  0
    
those are the 6 possible orders, when the algorithm finds that the order array is totally reversed, it returns NULL.

if you try to add more than 11 cities, please be sure that your processor can handle it first, cause starting from 12 the number of possibilities start getting crazy, and as far as I know, starting from 13 your computer will just start overflowing on the factorial output, I guess you know how big is the number at which your computer overflow. 
