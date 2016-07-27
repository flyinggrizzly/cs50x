/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    int lower = 0;
    int upper = n - 1;
    
    while (lower <= upper) {
        
        int mid = (lower + upper) /2;
        
        if (values[mid] == value) {
            return true;
        }
        else if (values[mid] > value) {
            upper = mid - 1;
        }
        else if (values[mid] < value) {
            lower = mid + 1;
        }
    }
    
    return false;
    
    // linear search, kept for future reference
    /* for (int i = 0; i < n; i++) {
        if (values[i] == value) {
            return true;
        }
    }
    return false; */
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // sort using selection sort
    
    // initialize an int to index to smallest found value; begins at i as it is the only value seen. Any value at i or earlier is sorted.
    for (int i = 0; i < n; i++) {
        int smallest = i;
    
        // iterate over array to identify index of smallest value, beginning with the first unsorted element
        for (int j = i + 1; j < n; j++) {
        
            // if the current value is smaller than the last smallest, update smallest
            if (values[j] < values[smallest]) {
                smallest = j;
            }
        } 
        
        // quick little shell game to place smallest value into sorted location
        int temp = values[i];
        values[i] = values[smallest];
        values[smallest] = temp;
        
    }
    
    // test that the array has been properly sorted
    /* for (int i = 0; i < n; i++) {
        printf("Sorted array: %i  ", values[i]);
    } */
    
    return;
}

