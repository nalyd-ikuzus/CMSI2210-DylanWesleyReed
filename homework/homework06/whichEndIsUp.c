#include <stdlib.h>
#include <stdio.h>

int whichEndIsUp();

int whichEndIsUp()
{
    /*
        Checks the computer's endian.

        Returns:
            int:
                Returns 1 if computer is Little Endian.
                Returns 0 if computer is Big Endian.
    */
    int num = 1;
    char *cpointer = (char *)&num;
    if (cpointer)
    {
        printf("Little Endian\n");
        return 1;
    }
    else
    {
        printf("Big Endian\n");
        return 0;
    }
}