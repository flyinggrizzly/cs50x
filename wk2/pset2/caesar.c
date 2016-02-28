/******************************************************************************
 * Caesar Cipher
 * 
 * (C) 2016 Sean DMR//Flying Grizzly
 * 
 * Submitted to CS50X as part of PSet 2
 *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

// prototypes
int ValidateInput(int argc, string argv[]);

// main
int main(int argc, string argv[]) {
    
    // pass inputs through to validator function
    
    

}

// validates and returns a key. If error, returns -1.
int ValidateInput(int argc, string argv[]) {
    
    // ensure we receive some value k with which to encrypt
    if (argc != 2) {
        return -1;
    }
    else {
        // ensure string at argv[1] is length 1, contains digit
        if (strlen(argv[1]) != 1) {
            return -1;
        }
        else {
            
            string s = argv[1];
          
            if (isdigit(s[0])) {
            
                int k = atoi(s[0]);
                if (k > 0) {
                    return k;
                }
                else {
                    return -1;
                }
            }
            else {
                return -1;
            }
        }
    }
}

/* TODO

1. validate input
    1.1 argc == 2
    1.2 argv[1] == counting number
2. convert argv[1] to int
    NB: this actually needs to happen to validate that it is a counting number
3. 


*/