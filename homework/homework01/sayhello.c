<<<<<<< HEAD
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


=======
/**
    * \file    sayhello.c
    * \brief   Report Generator Server (RGS) version
    *           function source code
    * \author  Original author ~ Dylan, Reed, Wesley
    * \date    Original date   ~ 30-August-2023
    * \version 1.0   Initial release
    * \version 1.1.0 Added user input
    *
    * Project:
    * \par
    * Homework 1
    *
    * Description:
    * \par
    * This file contains the solutions to homework 1, which asked us to
    * take the sayhello.c file from classtime and adapt it to include user
    * input
    *
    */

//Include files
#include <stdio.h>
#include <stdlib.h>

/**
    * \fn        main()
    * \brief     Function to ask for the user's name and say hello to them
    * \return    int
    * \exception None
    *
    * Description:
    * \par
    * Solution to homework 1, which asks for the user's name and says hello
    * to them.
    *
    *Side effects:
    * \par
    * Prints to the console
    *
    */
int main( int argc, char * argv[]){
    char input[25];
    printf("Hello friend, what is your name?\n");
    gets(input);
    printf("\n\nHello %s \n\n", input);
    return 0;
}
>>>>>>> a5516d7e59d900a59d55de1d7364f2f15e435b69
