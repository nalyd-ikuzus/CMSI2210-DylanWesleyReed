/*
    Program converts the an unsigned base-10 number
    to its 32-bit binary value equivalent.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 11
#define MAX_OUTPUT_LENGTH 33
#define MAX_DEC10_RANGE 4294967295

int main(int argc, char *argv[])
{
    char input[] = argv[1];
    if (argc != 3)
    {
        puts("Exactly two command line arguments needed");
        return 1;
    }
    else if (!isValidInput(input))
    {
        puts("Input must only contain digit characters.");
        puts("Do not use \".\" or \"-\" characters");
        return 2;
    }

    int dec10 = atoi(input);

    if (dec10 >= MAX_DEC10_RANGE)
    {
        puts("Number is too high! Input a number smaller than %d", MAX_DEC10_RANGE);
        return 3;
    }

    char binaryNum[MAX_OUTPUT_LENGTH];
    unsignedDecimalToBinary(dec10, binaryNum);
    printf(binaryNum);
    return 0;
}

int isValidInput(char input[])
{

    /*
        Checks if the input contains only integers.

        Parameters:
            The user's input.
        Return:
            int:
                1 if the input contains only digits.
                0 if the input contains at least
                one charater that is not an integer. This
                includes "-" or "." .
    */
    for (int i = 0; i < MAX_INPUT_LENGTH - 1; i++)
    {
        if (!isdigit(input[i]))
        {
            return 0;
        }
    }
    return 1;
}

void unsignedDecimalToBinary(int num, char *binaryNum[])
{
    /*
        Converts unisigned decimal to binary numbers as a string.
        Parameters:
            num:
                The unigned decimal representation of a number.
            char[]:
                The biniary represenation of the given number.
    */

    // Converting using Top-Down Division Approach.
    int index = 0;

    while (num != 0)
    {
        if (num % 2 == 1)
        {
            binaryNum[index] = '1';
        }
        else
        {
            binaryNum[index] = '0';
        }

        num /= 2;
        index++;
    }

    // 1110 0000 0000 0000 0000 0000 0000 0000

    // Shifts the binary number to the right based on the index number.
    int gapDistance = MAX_OUTPUT_LENGTH - index - 1;
    if (gapDistance == 0)
    {
        return;
    }
    while (index > 0)
    {
        index--;
        binaryNum[index + gapDistance] = binaryNum[index];
        binaryNum[index] = '0';
    }
}
