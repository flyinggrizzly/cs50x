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

// declare binary search function
bool binarySearch(int value, int values[], int low, int high);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int high = n - 1;
    return binarySearch(value, values, 0, high);
    
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


/**
 * performs binary search for a value, in an array values of size n
 */
bool binarySearch(int value, int values[], int low, int high)  {

    // make sure have an array of size > 1
    if (low > high)
        return false;
    
    else if (low < high) {
        
        //find the midpoint of the array
        int mid = (low + high) / 2;
        
        //check value at midpoint
        if (values[mid] == value) 
            return true;
            
        // go left...    
        else if (values[mid] > value)
            binarySearch(value, values, 0, mid - 1);
        
        // ...or go right
        else if (values[mid] < value)
            binarySearch(value, values, mid + 1, high);
        
        // if we're here, something went seriously wrong
        else
            return false;
    }

    return false;

}