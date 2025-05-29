/*
Write code to implement the following function:
/* Return 1 when any odd bit of x equals 1; 0 otherwise.
Assume w=32
int any_odd_one(unsigned x);
Your function should follow the bit-level integer coding rules (page 164),
except that you may assume that data type int has w = 32 bits.
*/



/*
Solution: with any odd bit = 1 mean exist odd position that value of bit = 1
*/


#include "stdio.h"
int any_odd_one(unsigned x) {
    x = x & 0xAAAAAAAA;
    return !!x;
}
int main() {
    printf("%d \n", any_odd_one(0x02));
    return 0;
}