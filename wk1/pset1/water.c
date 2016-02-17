/**********
 * A function that demonstrates basic C math.
 * 
 * (C) 2016 Sean DMR.
 **********/

#include <cs50.h>
#include <stdio.h>

int main(void){
    
    // init variable as number of bottles of water per minute of shower
    // 1 minute = 12 bottles
    int bpm = 12;
    
    // prompt user for shower lenght, in minutes
    printf("How long do you shower, in minutes? (round up to nearest minute please)\n");
    int mins = GetInt();
    
    // output product of mins and bpm
    printf("You use the equivalent of %i bottles of water when you shower for %i minutes.\n", bpm*mins, mins);
    
}