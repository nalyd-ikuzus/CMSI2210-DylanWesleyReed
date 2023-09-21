/**
    * \file    goFish.c
    * \brief   Report Generator Server (RGS) version
    *           function source code
    * \author  Original author ~ Dylan Suzuk 
    * \date    Original date   ~ 20-Sep-2023
    * \version 1.0   Initial release
    * Project:
    * \par
    * Classwork 03
    
    * Description:
    * \par
    * This program asks the user for up to 25 integers, stores them in an array,
    * sums them, averages them, finds the number of sevens, and prints a string
    * containing all entries.
    *
    */

   /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    *  INCLUDE FILES (All other include-type stuff is in these files)
    * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 25
#define SPECIAL_VALUE -9999


int main( int argc, char * argv[] ) {

   char input[10];
   char storage[MAX_ENTRIES][10];
   int sumOfEntries = 0;
   int numOfEntries = 0;
   int numOfSevens = 0;
   double average;
   char longString[MAX_ENTRIES * 10] = "\0";

   printf( "   hello, world!\n" );
   for( int i =0; i < MAX_ENTRIES; i++ ) {
      printf( "\n  enter an integer:" );
      fgets(input, 10, stdin);
      printf( "\n     got: %s", input );
      if( atoi( input ) == SPECIAL_VALUE ){
        break;
      }
      strcpy( storage[i], input);
      printf("%s", input);
   }

   for( int i = 0; i < MAX_ENTRIES; i++){
    printf("%d", atoi (storage[i]));
    sumOfEntries += atoi( storage[i] );
    if(atoi( storage[i] ) != 0 ){
        numOfEntries += 1;
        storage[i][strcspn(storage[i], "\n")] = 0;
        strcat( longString, storage[i] );
    }
    if(atoi( storage[i] ) == 7 ){
        numOfSevens += 1;
    }
   }
   average = (double)(sumOfEntries/numOfEntries);
   printf("\n    sum of entries: %d \n", sumOfEntries);
   printf("\n    average of entries: %f \n", average);
   printf("\nGIMME ALL YOUR SEVENS\n    number of sevens: %d \n", numOfSevens);
   printf("\n    long string of entries: %s \n\n", longString);

}