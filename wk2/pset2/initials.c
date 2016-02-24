#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// prototypes
void FindInitials(string name, int numInitials);
int CountNames(string name);

int main (void) {
    
    string name = GetString();
    
    if (name != NULL) {
        
        int numNames = CountNames(name);
        
        FindInitials(name, numNames);
        
        return 0;
    }
    else {
        main();
    }
}

/* Given a number of names, and string containing all of those names,
 * this function searches for white space followed by an alpha.
 * It takes this alpha, capitalizes it, and stores it in an array.
 * Once it has filled the array, it prints the capitalized initials
 * to the terminal.
 */
void FindInitials(string name, int numInitials) {
    
    // build an array in which to store the initials
    char initials[numInitials];
    int whichInit = 0;
    
    // sanity check
    if (name != NULL) {
        
        for (int i = 0, l = strlen(name); i <= l; i++) {
            
            // special case for first char in name
            if (i == 0) {
                
                // if first char is an alpha, grab it
                if (isalpha(name[i])) {
                    initials[whichInit] = toupper(name[i]);
                    whichInit++;
                }
                // if the first char is a space, check the following. If that is alpha, grab that
                else if (isspace(name[i])) {
                    if (isalpha(name[i + 1])) {
                        initials[whichInit] = toupper(name[i + 1]);
                        whichInit++;
                    }
                }
            }
            
            // normal procedure searches for a space followed by an alpha on all indexes > 0
            else if (i > 0 && isspace(name[i])) {
                
                // check if the char following a space is alpha
                if (isalpha(name[i + 1])) {
                    initials[whichInit] = toupper(name[i + 1]);
                    whichInit++;
                }
            }
        }
    }
    
    // print initials to terminal
    for (int i = 0; i < numInitials; i++) {
        printf("%c", initials[i]);
    }
    // print newline
    printf("\n");

    
}



/* Determines how many initials will exist for a given string name, by 
 * counting spaces trailed by a char (with exception made for the first)
 * char in the string, which may be the first name.
 */
 int CountNames(string name) {
     
     // start keeping count of names...
     int count = 0;
     
     // first char could be the first letter of the first name (unless there is an unintentional space, which will be caught by the normal operation of the function)
     if (isalpha(name[0])) {
         count++;
         
        // look for spaces followed by chars to identify each name
            // don't bother checking last char, because there isn't an i + 1
         for (int i = 0, length = strlen(name); i < length - 1; i++) {
             if (isspace(name[i]) && isalpha(name[i+1])) {
                 count++;
             }
         }
         
     }
     else {
         // do the same, but first char is a space
         for (int i = 0, length = strlen(name); i < length - 1; i++) {
             if (isspace(name[i]) && isalpha(name[i+1])) {
                 count++;
             }
         }
     }
     
     return count;
 }