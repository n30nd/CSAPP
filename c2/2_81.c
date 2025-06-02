// Write C expressions to generate the bit patterns that follow, where a k represents
// k repetitions of symbol a. Assume a w-bit data type. Your code may contain
// references to parameters j and k, representing the values of j and k, but not a
// parameter representing w.


#include "stdio.h"

void printf_binary_for_32_bit(int x) {
    unsigned y = (unsigned) x;
    for(int i=31;i>=0;i--) {
        printf("%x", (y>>i) & 0x1);
    }
    printf("\n");
}

int A(int k) {
    return -1 << k;
}
int B(int j, int k) {
    // int x = -1 << j;
    // int mask = (unsigned)-1 >> (sizeof(int)<<3)-k-j;
    // return x & mask;

    int x = (unsigned) -1 >> (sizeof(int)<<3)-k-j;
    int y = (unsigned) -1 >> (sizeof(int)<<3)-j;
    return x^y;
}

int main() {
    // printf_binary_for_32_bit(A(5));
    printf_binary_for_32_bit(B(2, 2));

    return 0;
}