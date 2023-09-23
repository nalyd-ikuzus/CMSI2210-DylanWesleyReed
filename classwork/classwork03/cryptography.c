/**
 * Name: Wesley Ng, Dylan Suzuki, Reed Maniscalchi
 * Date: 9/13/2023
 * Purpose: Make Cryptography.... yah
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 5999

int main(int argc, char *argv[])
{
    // Asks users for their input that totals of 50 characters.
    char input[50];
    int index;
    int value;
    char MORSE[36][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                          "..", ".---", "-.-", ".-..", "--", "-.", "--", "-.", "---",
                          ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                          "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
                          "-....", "--...", "---..", "----.", "-----"};

    char LETTERS[27] = "abcdefghijklmnopqrstuvwxyz";

    if (argc == 1)
    {
        printf("Please try again and type more words mister.");
        exit(0);
    }

    value = atoi(arg[1]);

    printf("What's you name?");
    scanf("%s", input);

    printf("\n\tHello, %s! It's nice to meet you? How's life treating you?\n", input);
    exit(0);
}
