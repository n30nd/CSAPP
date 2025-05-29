/*
2.63 ◆◆◆
Fill in code for the following C functions. Function srl performs a logical right
shift using an arithmetic right shift (given by value xsra), followed by other oper-
ations not including right shifts or division. Function sra performs an arithmetic
right shift using a logical right shift (given by value xsrl), followed by other
operations not including right shifts or division. You may use the computation
8*sizeof(int) to determine w, the number of bits in data type int. The shift
amount k can range from 0 to w − 1.
unsigned srl(unsigned x, int k) {
/* Perform shift arithmetically
unsigned xsra = (int) x >> k;
.
.
.
.
.
.
}
int sra(int x, int k) {
/* Perform shift logically
int xsrl = (unsigned) x >> k;
.
.
.
.
.
.
}
*/

#include "stdio.h"

unsigned srl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int)x >> k;

    unsigned mask = (unsigned) (-1) >> k;
    return xsra & mask;
}

int sra(int x, int k)
{
    /* Perform shift logically */
    int xsrl = (unsigned)x >> k;
    // int mask = x >> ((sizeof(int) << 3) - 1) << ((sizeof(int) << 3) - 1);
    int mask = x & 0x80000000;
    mask = mask >> k;
    return xsrl | mask;
}

int main()
{
    printf("%x\n", srl(0xff000000, 2));
    printf("%x\n", sra(0xff000000, 4));
    return 0;
}