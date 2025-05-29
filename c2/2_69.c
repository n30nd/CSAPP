// Write code for a function with the following prototype:
// /*
// * Do rotating left shift. Assume 0 <= n < w
// * Examples when x = 0x12345678 and w = 32:
// *
// n=4 -> 0x23456781, n=20 -> 0x67812345
// */
// unsigned rotate_left(unsigned x, int n);
// Your function should follow the bit-level integer coding rules (page 164). Be
// careful of the case n = 0

#include "stdio.h"
unsigned rotate_left(unsigned x, int n) {
    unsigned w = sizeof(unsigned) << 3;
    // printf("w=%d\n", w);
    
    // unsigned mask = (unsigned) -1 << (w-n);
    // printf("mask=%x\n", mask);
    // unsigned x1 = (x & mask) >> (w-n);
    // printf("x1=%x\n", x1);
    // unsigned x2 = (x & ~mask) << n;
    // printf("x2=%x\n", x2);
    // return x1 | x2;

    return x << n | x >> (w-n-1) >> 1;
}
int main() {
    printf("%x\n", rotate_left(0x12345678, 4));
    return 0;
}