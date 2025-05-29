// Write code for the function with the following prototype:
// /*
// * Return 1 when x can be represented as an n-bit, 2’s-complement
// * number; 0 otherwise
// * Assume 1 <= n <= w
// */
// int fits_bits(int x, int n);
#include "stdio.h"


int fits_bits(int x, int n) {
    // int w = sizeof(int) << 3;
    // int x1 = x >> n;
    // int x2 = x << (w-n) >> (w-1);
    // return !(x1^x2);

    int w = sizeof(int) << 3;
    int x2 = x << (w-n) >> (w-n);
    return !(x2^x);
}


int main() {
    printf("%d\n", fits_bits(0x3, 1));
    return 0;
}