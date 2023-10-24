#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define INSTRUCTIONS "This program will time how long you can hold your breath. Take a deep breath, then press the 'Enter' key. When you absolutely have to exhale, press the Enter key again. The duration will be displayed in minutes and seconds."

int main(int argc, char * argv[]){
    time_t currtime;
    time_t start, end;
    double diff;
    int secondsDiff;
    int minutesDiff;
    printf(INSTRUCTIONS);

    char input[32];
    fgets(input, sizeof(input), stdin);

    if(input[0] == '\n'){
        time(&start);
        printf("\n\nStarting timer now\n\n");

        char input2[32];
        fgets(input2, sizeof(input2), stdin);

        if(input[0] == '\n'){
            time(&end);
            diff = difftime(end, start);
            minutesDiff = (int)diff / 60;
            secondsDiff = ((int)diff)%60;
            printf("Congratulations!  You held your breath for %d minutes and %d seconds\n\n", minutesDiff, secondsDiff);
        }


    }

}