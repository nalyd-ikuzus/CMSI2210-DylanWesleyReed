/*
To Compile and Link: gcc parityTester.c paritygen.o -o parityTester
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int paritygen( int64_t );

int main() {
    printf("The parity flag would be: %d for a value of 0x0F \n", paritygen(0x0F));
    assert(paritygen(0x0F) == 1);
    printf("The parity flag would be: %d for a value of 0x0E \n", paritygen(0x0E));
    assert(paritygen(0x0E) == 0);
    printf("The parity flag would be: %d for a value of 0x34 \n", paritygen(0x34));
    assert(paritygen(0x34) == 0);
    printf("The parity flag would be: %d for a value of 0x69 \n", paritygen(0x69));
    assert(paritygen(0x69) == 1);
}