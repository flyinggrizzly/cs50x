#include <cs50.h>
#include <stdio.h>

// helper functions
int ValidateInput(int input);
void HebrewSlaves(int height);

int main(void){
    
    //prompt user for height
    printf("Height: ");
    int uInput = GetInt();
    
    // validate 0 < uInput <= 23
    int validInput = ValidateInput(uInput);
    // if(validInput == 0) {
    //     return 0;
    // }
    
    // the pyramids in the Old Testament were built by...
    HebrewSlaves(validInput);
    
    return 0;
}

// validate 0 < input <= 23
int ValidateInput(int input){
 
    if (input > 0 && input <= 23) {
        return input;
    }
    else if (input == 0){
        return 0;
    }
    else {
        main();
    }
    
    return -1;
}


// builds a half pyramid of height 'height'
void HebrewSlaves(int height){
    
    // determine number of chars across the pyramid is
    int pyrWidth = height + 1;
    
    // iterate each level of the pyramid (from top to bottom)
    for (int i = 0; i < height; i++){
        
        // number of spaces as a f'n of level
        for (int j = pyrWidth - 2; j - i > 0; j--){
            printf(" ");
        }
        
        // number of sharps as a f'n of level
        for (int k = i + 1; k > 0; k--){
            printf("#");
        }
        
        // print 1 constant sharps
        printf("#\n");
    }
}