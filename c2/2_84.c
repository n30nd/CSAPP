// Fill in the return value for the following procedure, which tests whether its first
// argument is less than or equal to its second. Assume the function f2u returns an
// unsigned 32-bit number having the same bit representation as its floating-point
// argument. You can assume that neither argument is NaN. The two flavors of zero,
// +0 and −0, are considered equal.

#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
    return *(unsigned* )&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    /* Give an expression using only ux, uy, sx, and sy */
    // x <= y 
    // x = 0+, y = 0- 
    // x <=0, y >=0 : sgnx=1, sgny=0
    // x >=0, y>= 0: ux <= uy
    // x <=0, y <=0: ux >= uy

    printf("!(sx >> 1) && !(sy >> 1) = %d\n", !(sx >> 1) && !(sy >> 1));
    printf("x = +0, y= -0\n");
    printf("sx && !y = %d\n",sx && !sy);
    printf("(!sx && !sy) && ux <= uy: %d\n", (!sx && !sy) && ux <= uy);
    printf("(sx && sy) && ux >= uy = %d\n", (sx && sy) && ux >= uy);
    return
        (sx >> 1) && (sy >> 1)  || 
        (sx && !sy) ||
        (!sx && !sy) && ux <= uy ||
        (sx && sy) && ux >= uy; 
}


int main(int argc, char* argv[]) {
    // assert(float_le(+0, -0));
    // assert(float_le(0, 3));
    // assert(float_le(-4, -0));
    // assert(float_le(-4, 4));
    // assert(float_le(2, 3));

    printf("%d\n", float_le(+0, -0));
    return 0;
}