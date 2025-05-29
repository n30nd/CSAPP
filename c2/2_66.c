/*
Write code to implement the following function:
/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
* If x = 0, then return 0.
*/
/*
int leftmost_one(unsigned x);
Your function should follow the bit-level integer coding rules (page 164),
except that you may assume that data type int has w = 32 bits.
Your code should contain a total of at most 15 arithmetic, bitwise, and logical
operations.
Hint: First transform x into a bit vector of the form [0 . . . 011 . . . 1].
*/

#include "stdio.h"
int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x>>1) + (x&&1);
}
int main() {
    printf("%x\n", leftmost_one(0x8));

    return 0;
}