#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findNumberOfDigits(int target);

int main(int argc, char * argv[]){
    if( argc < 2 ){
        printf("\n\n Sorry, you must enter a number for this program to work");
        exit(0);
    }
    else{
        int n = atoi(argv[1]);
        int d = findNumberOfDigits(n*n) + 1;
        printf("\n\n%i\n\n", d);

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                printf("%*d", d, i*j);
            }
            printf("\n");
        }
        return(0);
    }
}


int findNumberOfDigits(int target){
    int r = 0;
    while(1){
        target = target/10;
        r++;
        if(target == 0){
            return r;
        }
    }
}