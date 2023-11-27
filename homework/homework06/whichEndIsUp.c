#include <stdlib.h>
#include <stdio.h>

int main()
{
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