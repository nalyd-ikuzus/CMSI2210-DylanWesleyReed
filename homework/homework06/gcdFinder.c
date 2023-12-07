/*
To Compile and Link: gcc gcdFinder.c findGCDfunc.o -o gcdFinder
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int64_t findGCD( int64_t, int64_t );

int main() {
    printf("The GCD of 3113041662 and 11570925 is: %lld\n", findGCD(3113041662, 11570925));
    assert(findGCD(3113041662, 11570925) == 462837);
    printf("The GCD of 234567 and 3248597 is: %lld\n", findGCD(234567, 3248597));
    assert(findGCD(234567, 3248597) == 1);
    printf("The GCD of 2370854 and 283452 is: %lld\n", findGCD(2370854, 283452));
    assert(findGCD(2370854, 283452) == 2);
    printf("The GCD of 92567400 and 11570925 is: %lld\n", findGCD(92567400, 11570925));
    assert(findGCD(92567400, 11570925) == 11570925);
}