#include <stdlib.h>
#include <stdio.h>

int whichEndIsUp();
unsigned int makeNBO(unsigned int);

unsigned int makeNBO(unsigned int number)
{
    /*
        Method that reverses the byte order of number. For
        example, if the computer runs on Big Endian, then this
        method is called to change the data to Little Endian when
        the data is sent to another computer that runs on Little
        Endian. It will print and return the new number.

        Parameters:
            number (int):
                The number that needs to be in reverse order. It
                can either be signed or unsigned.
        Return:
            int:
                The new number where its bytes were reversed. It
                will return a signed number. Note: if the computer
                is in Big Endian, then just return the number itself.
    */
    if (!whichEndIsUp())
    {
        return number;
    }

    unsigned int reverse = 0;
    int byteIndex = 3;

    for (unsigned int num = number; num > 0; num /= 256)
    {
        reverse += ((num % 256) << (8 * byteIndex));
        byteIndex--;
    }

    printf("%08x\n", reverse);
    return reverse;
}
