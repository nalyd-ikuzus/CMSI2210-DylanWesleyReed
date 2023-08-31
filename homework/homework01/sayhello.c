#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]){

   // Asks users for their input that totals of 50 characters.
   char input[50];
   printf("What's you name?");
   scanf("%s", input);



   printf( "\n\tHello, %s! It's nice to meet you? How's life treating you?\n", input );
   exit(0);
}


