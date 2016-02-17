/**********
 * Greedy function that counts out minimum number of coins needed to achieve
 * required change.
 * 
 * Demonstrates functional decomposition, and use of modulo-math and division
 * to avoid repetitive subtraction in loops.
 * 
 * (C) 2016 Sean DMR
 **********/

#include <cs50.h>
#include <math.h>
#include <stdio.h>

// prototypes
float CheckChange(float request);
int CountChange(int cents);


int main(void) {
    
    // prompt user for change required
    printf("Hey foo, how much change do you need?\n");
    float change = GetFloat();
    
    // validate value of change
    change = CheckChange(change);
    
    // convert change to an int of cents
    int cents = roundf(change * 100);
    
    // start cutting chunks outta cents on a per-coin basis
    int numCoins = CountChange(cents);
    printf("%i\n", numCoins);
    
    return 0;
}



/*****************************
 * Helper functions 
 *****************************/

/***
 * checks requested change for positivity. Returns input if valid, recalls main if invalid
*/
float CheckChange(float request) {
    
    if (request < 0) {
        main();
        return -1;
    }
    else {
        return request;
    }
    
}

// returns int repping number of coins needed to give change
// avoiding loop method becaues that feels obvious. trying modulo...
int CountChange(int cents) {
    
    // init variable to 0 of number of coins to return
    int numCoins = 0;

    
    // while we owe more than pennies
    while (cents > 4) {
    
        // we'll need to know the biggest coin we can hand back on each pass...
        int coin;
        
        if (cents > 24) { 
            coin = 25; 
        }
        else if (cents > 9) {
            coin = 10;
        }
        else {
            coin = 5;
        }
        
        // what portion of the change needed can we not give with the current coin?
        int tooSmall = cents % coin;
        
        // how many of the current coin are we giving?
        numCoins = numCoins + ((cents - tooSmall)/coin);
        
        // what change do we still have to give?
        cents = tooSmall;
        
    }
    
    // if only pennies remain, give them out
    numCoins = numCoins + cents;
    
    return numCoins;
    
}
