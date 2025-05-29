// Write code for a function with the following prototype:
// /*
// * Mask with least signficant n bits set to 1
// * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
// * Assume 1 <= n <= w
// */
// int lower_one_mask(int n);
// Your function should follow the bit-level integer coding rules (page 164). Be
// careful of the case n = w.

#include "stdio.h"
int lower_one_mask(int n) {
    int t = (sizeof(int) << 3 ) - n;
    // printf("t=%d\n", t);
    unsigned x = (unsigned) -1;
    x = x >> t;

    return x;
}

int main() {
    printf("%x\n", lower_one_mask(6));
    printf("%x\n", lower_one_mask(17));
    printf("%x\n", lower_one_mask(0));

    return 0;
}