/*
Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1
(most significant). Write code for the following C function, which will return an
unsigned value in which byte i of argument x has been replaced by byte b:
unsigned replace_byte (unsigned x, int i, unsigned char b);
Here are some examples showing how the function should work:
replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/

#include "stdio.h"

void show_bytes_for_little_endian(unsigned char* p, size_t len) {
    for(int i = len-1;i>=0;i--) {
        printf(" %x", p[i]);
    }
    printf("\n");
}

unsigned replace_byte (unsigned x, int i, unsigned char b) {
    // unsigned mask = 0xFF << (i << 3);
    // unsigned b_unsigned = (unsigned) b << (i << 3);
    // return (x& ~mask) | (b_unsigned & mask);

    //just for little endian
    unsigned char* p = (unsigned char *)&x;
    p += i;
    *p = b;
    return x;
}
int main() {
    unsigned r = replace_byte(0x12345678, 2, 0xAB);
    show_bytes_for_little_endian((unsigned char *)&r, sizeof(unsigned));
    return 0;
}