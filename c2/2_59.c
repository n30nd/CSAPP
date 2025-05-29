#include "stdio.h"
/*
2.59 ◆◆
Write a C expression that will yield a word consisting of the least significant byte of
x and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210,
this would give 0x765432EF
*/


int merge(int x, int y) {
    x = x & 0xFF;
    // y = (y >> 8) << 8; 
    y = y & 0xFFFFFF00;
    return x | y;
}

void show_bytes_for_little_endian(unsigned char* p, size_t len) {
    for(int i = len-1;i>=0;i--) {
        printf(" %x", p[i]);
    }
    printf("\n");
}
int main() {
    int x = 0x89ABCDEF;
    int y = 0x76543210;

    int z = merge(x, y);
    show_bytes_for_little_endian((unsigned char*)&z, sizeof(int));

    return 0;
}