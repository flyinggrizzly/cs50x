/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // linear search, because we haven't implemented sort yet
    for (int i = 0; i < n; i++) {
        if (values[i] == value) {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // sort using selection sort
    
    // initialize an int to index to smallest found value; begins at i as it is the only value seen
    
    for (int i = 0; i < n; i++) {
        int smallest = i;
    
        for (int j = i + 1; j < n; j++) {
        
            // if the current value is smaller than the last smallest, update smallest
            if (values[i] < values[smallest]) {
                smallest = i;
            }
        } 
    }
    
    return;
}