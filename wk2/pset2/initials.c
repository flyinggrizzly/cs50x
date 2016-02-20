#include <cs50.h>
#include <stdio.h>
#include <string.h>

// prototypes
string FindInitials(string name);
int CountInitials(string name);

int main (void) {
    
    string name = GetString();
    
    if (name != NULL) {
        
        string initials = FindInitials(name);
        
        printf( "%s\n", initials );
        
        return 0;
    }
    else {
        main();
    }
}

// concatenates capitalized first letters of words from an input string
string FindInitials(string name) {
    
    // determine how many initials will exist to size an array
    int numInitials = CountNames(name);
    
    // first char is the letter of the first name
    if (name[0] != ' ') {
        
    }
    
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
     }
     else {
         // look for spaces followed by chars to identify each name
            // don't bother checking last char, because there isn't an i + 1
         for (int i = 0, length = strlen(name), i < length - 1, i++) {
             if (isspace(name[i]) && isalpha(name[i+1])) {
                 count++;
             }
         }
     }
     
     return count;
 }