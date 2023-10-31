#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char * argv[]){
    int count = 0;
    bool check = false;
    FILE* in = fopen( argv[1], "r" );
        if( !in ) {
            printf( "File %s does not exist\n", argv[1] );
            return 2;
        }
        while( 1 ) {
            int c = fgetc( in );
            printf("%c", c);
            if( c == ' ' || c == '\n'){
                if( !check ){
                    count += 1;
                }
                check = true;
            }
            else if( c == EOF ) {
                count += 1;
                break;
            }
            else{
                check = false;
            }
        }
        printf("There are %d words in the file\n\n", count);
        fclose( in );
        return 0;
}