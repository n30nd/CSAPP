/*
Write code to implement the following function:
/* Return 1 when x contains an odd number of 1s; 0 otherwise.
Assume w=32 
int odd_ones(unsigned x);
Your function should follow the bit-level integer coding rules (page 164),
except that you may assume that data type int has w = 32 bits.
Your code should contain a total of at most 12 arithmetic, bitwise, and logical
operations
*/

/*
Intution:  If x has odd number of 1s then 
x0^x1^...^x31 = 1 else 0

*/


#include "stdio.h"
int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}

int main() {
    printf("%d\n", odd_ones(0xf));    
    return 0;
}