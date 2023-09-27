#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
char NATO[26][15] = {"Alpha", "Bravo", "Charlie", "Delta", "Epsilon", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};

int main( int argc, char * argv[]){

    char * targetWord;
    if(argc > 1){
        targetWord = argv[1];
    }
    else{
        printf("No argument detected, please enter a word to convert:");
        scanf(targetWord);
        printf("%s", targetWord);
    }

    for(int i = 0; i < strlen(targetWord); i++){
        char curr = tolower( targetWord[i] );
        //printf("%c", curr);
        for(int j = 0; j < sizeof alphabet; j++){
            if(alphabet[j] == curr){
                printf("%i - %c : %s \n", j, curr, NATO[j]);
            }
        }
    }
    return 0;
}

