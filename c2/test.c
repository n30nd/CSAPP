#include "stdio.h"
#include "math.h"
typedef unsigned char *byte_pointer;

void show_byte(byte_pointer p, size_t cnt) {
    for(int i=cnt-1;i>=0;i--) {
        printf("%.2x ", p[i]);
    }
    printf("\n");
}

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
    return ((int) word << 24) >>24;
}

int main() {
    // unsigned w = 0x000000c9;
    // int w1 = fun1(w);
    // int w2 = fun2(w);
    // show_byte((byte_pointer)&w1, sizeof(int));
    // show_byte((byte_pointer)&w2, sizeof(int));

    // int x = 53191;
    // short sx = (short) x;
    // int y = sx;

    // show_byte((byte_pointer)&x, sizeof(int));
    // show_byte((byte_pointer)&sx, sizeof(short));
    // show_byte((byte_pointer)&y, sizeof(int));

    // printf("x = %d, sx= %d, y = %d \n", x, sx, y);


    // printf("%ld\n", sizeof(size_t));

    // int x = -3;
    // int y = 2;
    // unsigned ux = x;
    // unsigned uy = y;

    // printf("%d, %d\n", x*~y + uy*ux, -x );

    // int x = sqrt(__INT_MAX__);
    // printf("%d\n", x);

    // int y = (x+1)*(x+1);
    // printf("%d\n", y);

    // int x = 123;
    // int* p = &x;
    // int* t = p+1;
    // int* z = p++;
    // printf("p: %p \n", p);
    // printf("t: %p\n", t);
    // // printf("z: %p\n", z);
    // printf("p: %p \n", p);

    // int x = -1;

    // unsigned z = (unsigned) x >> 1;
    // printf("z: %x\n", z);

    // unsigned t = x; 
    // printf("t: %x\n", t >> 1);
    int x = 0x12345678;
    int y = -1;
    printf("%x\n", x*y);



    return 0;
}