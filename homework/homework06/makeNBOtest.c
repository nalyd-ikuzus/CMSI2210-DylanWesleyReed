/*
    MAIN PROGRAM: A test file that runs assertions to check makNBOC's correctness

    filename: makeNBOtest.c

    Compile and link: gcc makeNBOtest.c -o makeNBOtest
    Compile only: gcc -c makeNBOtest.c
    Link: gcc makeNBOtest.c makeNBOC.c whichEndIsUp.o -o makeNBOtest
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

unsigned int makeNBO(int);

int main()
{
    /*
        Program that tests the correctness
        of makeNBO.c.
    */

    // Test for making sure that the end bytes switch properly.
    assert(makeNBO(240) == 4026531840u);
    assert(makeNBO(4026531840u) == 240);

    // Test to see for palindromatic bytes, the number does not change.
    assert(makeNBO(-572662307) == -572662307);
    assert(makeNBO(1236447817) == 1236447817);

    // Test to see if the middle bytes switch
    assert(makeNBO(8952064) == 10061824);
    assert(makeNBO(10061824) == 8952064);

    return 0;
}