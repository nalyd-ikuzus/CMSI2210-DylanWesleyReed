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
#define MAX_DEC10_RANGE 4294967295u

int isValidInput(char[]);
short isGreaterThan(unsigned int, char[]);
void unsignedDecimalToBinary(unsigned int, char[]);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        puts("\nTo execute this file: dec2bin.exe [int]");
        return 1;
    }

    char input[MAX_INPUT_LENGTH];
    strcpy(input, argv[1]);

    if (argc != 2)
    {
        puts("\nExactly one command line arguments needed");
        return 2;
    }
    else if (isValidInput(input) == 0)
    {
        puts("\nInput must only contain digit characters.");
        puts("Do not use \".\" or \"-\" characters");
        return 3;
    }

    unsigned int dec10 = atol(input);

    if (isGreaterThan(MAX_DEC10_RANGE, input) == 0)
    {
        puts(("\nNumber is too high! Input a number smaller than 4294967295"));
        return 4;
    }

    char binaryNum[MAX_OUTPUT_LENGTH];
    unsignedDecimalToBinary(dec10, binaryNum);
    printf(binaryNum);
    return 0;
}

int isValidInput(char *input)
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
    for (int i = 0; i < MAX_INPUT_LENGTH - 1 && input[i] != '\0'; i++)
    {
        if (!isdigit(input[i]))
        {
            return 0;
        }
    }
    return 1;
}

short isGreaterThan(unsigned int num, char *input)
{
    /*
        Checks if the num is greater than the string representation of a number.
        Parameters:
            num:
                The unsigned decimal representation of a number.
            input:
                The user's number in string representation.
        Returns:
            1 if the num > input
            0 otherwise.

    */

    int size = 0;
    while (input[size] != '\0')
    {
        size++;
    }
    size++;

    if (size > MAX_INPUT_LENGTH)
    {
        return 0;
    }
    else if (size < MAX_INPUT_LENGTH)
    {
        return 1;
    }

    short boolVal = 1;
    for (int i = MAX_INPUT_LENGTH - 2; i >= 0; i--)
    {
        if (num % 10 < input[i] - 48)
        {
            boolVal = 0;
        }
        else if (num % 10 > input[i] - 48)
        {
            boolVal = 1;
        }
        num /= 10;
    }

    return boolVal;
}

void unsignedDecimalToBinary(unsigned num, char *binaryNum)
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

    for (int i = 0; i < MAX_OUTPUT_LENGTH - 1; i++)
    {
        binaryNum[i] = '0';
    }

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
        index = index + 1;
    }

    // Reverses the binary number.
    for (int i = 0; i < (MAX_OUTPUT_LENGTH - 1) / 2; i++)
    {
        binaryNum[i] ^= binaryNum[MAX_OUTPUT_LENGTH - 2 - i];
        binaryNum[MAX_OUTPUT_LENGTH - 2 - i] ^= binaryNum[i];
        binaryNum[i] ^= binaryNum[MAX_OUTPUT_LENGTH - 2 - i];
    }

    binaryNum[MAX_OUTPUT_LENGTH - 1] = '\0';
}
