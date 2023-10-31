/*
    Program converts the an unsigned base-10 number
    to its hexidecimal value equivalent.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 21
#define MAX_OUTPUT_LENGTH_32 11
#define MAX_OUTPUT_LENGTH_64 19
#define MAX_DEC10_RANGE_32 4294967295llu
#define MAX_DEC10_RANGE_64 18446744073709551615llu

short isValidBitInput(char[]);
short isValidDec10Input(char[]);
long long int strToUnsignedLongLongIntDecimal(char[]);
short isGreaterThan(unsigned long long int, char[]);
void unsignedDecimalToHex(unsigned long long int, short, char[], int);

// Argument: .\dec2hex [Unsigned Integer: 0 to MAX_DEC10_RANGE] [32 or 64]
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        puts("\nTo execute this file: dec2hex.exe [Unsigned Integer: 0 to MAX_DEC10_RANGE] [32 or 64]");
        return 1;
    }

    char input[MAX_INPUT_LENGTH];
    strcpy(input, argv[1]);
    short bits;
    unsigned long long int dec10;

    if (argc != 3)
    {
        puts("\nExactly two command line arguments needed.");
        puts("\nTo execute this file: dec2hex.exe [Unsigned Integer: 0 to 4294967295 or 0 to 18446744073709551615] [32 or 64]");
        return 2;
    }
    else if (isValidBitInput(argv[2]) == 0)
    {
        puts("\nSecond argument must be either 32 or 64.");
        return 3;
    }

    bits = atoi(argv[2]);

    if (isValidDec10Input(input) == 0)
    {
        puts("\nFirst argument must only contain digit characters.");
        puts("Do not use \".\" or \"-\" characters.");
        return 4;
    }

    dec10 = strToUnsignedLongLongIntDecimal(input);

    if (isGreaterThan(MAX_DEC10_RANGE_64, input) == 0 || dec10 > MAX_DEC10_RANGE_32 && bits == 32)
    {
        if (bits == 32)
        {
            puts("\nNumber is too high! Input a number smaller than 4294967296.");
        }
        else
        {
            puts("\nNumber is too high! Input a number smaller than 18446744073709551616.");
        }
        return 5;
    }

    if (bits == 32)
    {
        char hexNum[MAX_OUTPUT_LENGTH_32];
        unsignedDecimalToHex(dec10, bits, hexNum, MAX_OUTPUT_LENGTH_32);
        printf(hexNum);
    }
    else
    {
        char hexNum[MAX_OUTPUT_LENGTH_64];
        unsignedDecimalToHex(dec10, bits, hexNum, MAX_OUTPUT_LENGTH_64);
        printf(hexNum);
    }
    return 0;
}

short isValidBitInput(char *input)
{
    /*
        Checks if the input is either "32" or "64".

        Parameters:
            The user's input.
        Return:
            short:
                1 if the input contains either f the 2 numbers.
                0 otherwise.
    */

    if (input[0] == '3' && input[1] == '2' || input[0] == '6' && input[1] == '4')
    {
        return 1;
    }
    return 0;
}

short isValidDec10Input(char *input)
{
    /*
        Checks if the input contains only integers.

        Parameters:
            The user's input.
        Return:
            short:
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

long long int strToUnsignedLongLongIntDecimal(char *input)
{
    /*
        Turns the input to an Unsigned Long Long Decimal.

        Parameters:
            The user's input.
        Return:
            long long int:
                The unsigned long long int
    */
    unsigned long long int num = 0;
    int index = 0;
    while (isdigit(input[index]))
    {
        num *= 10;
        num += ((int)input[index]) - 48;
        index++;
    }
    return num;
}

short isGreaterThan(unsigned long long int num, char *input)
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

void unsignedDecimalToHex(unsigned long long int num, short bits, char *hexNum, int outputSize)
{
    /*
        Converts unisigned decimal to hexidecimal numbers as a string.
        Parameters:
            num:
                The unigned decimal representation of a number.
            bits:
                The amount of bits that needs to be returned.
            char[]:
                The biniary represenation of the given number.
    */

    for (int i = 0; i < outputSize - 1; i++)
    {
        hexNum[i] = '0';
    }

    // Converting using Top-Down Division Approach.
    int index = 0;
    char hexChar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (num != 0)
    {
        // printf("%c", hexChar[num % 16]);
        hexNum[index] = hexChar[num % 16];

        num /= 16;
        index = index + 1;
    }

    hexNum[outputSize - 3] = 'x';
    hexNum[outputSize - 2] = '0';
    // Reverses the hex number from left to right.
    for (int i = 0; i < (outputSize - 1) / 2; i++)
    {
        hexNum[i] ^= hexNum[outputSize - 2 - i];
        hexNum[outputSize - 2 - i] ^= hexNum[i];
        hexNum[i] ^= hexNum[outputSize - 2 - i];
    }

    hexNum[outputSize - 1] = '\0';
}
