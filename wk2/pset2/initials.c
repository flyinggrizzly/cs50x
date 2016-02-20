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
    
    // i tracks initials array index, j iterates through the string name
    for (int i = 0, j = 0; i < numInitials; j++) {
        
        // first char is the letter of the first name
        if (name[j] != ' ') {
            initials[i] = toupper(name[j]);
            i++;
            
            // identify spaces followed by alpha
            if (isspace(name[j]) && isalpha(name[j + 1])) {
                initials[i] = toupper(name[j + 1]);
                i++;
            }
            
        }
        else {
            
            // do same, but first char is a space
            if (isspace(name[j]) && isalpha(name[j + 1])) {
                initials[i] = toupper(name[j + 1]);
                i++;
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