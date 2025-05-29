// Suppose we want to compute the complete 2w-bit representation of x . y, where
// both x and y are unsigned, on a machine for which data type unsigned is w bits.
// The low-order w bits of the product can be computed with the expression x*y, so
// we only require a procedure with prototype
// unsigned unsigned_high_prod(unsigned x, unsigned y);
// that computes the high-order w bits of x . y for unsigned variables.
// We have access to a library function with prototype
// int signed_high_prod(int x, int y);
// that computes the high-order w bits of x . y for the case where x and y are in two’s-
// complement form. Write code calling this procedure to implement the function
// for unsigned arguments. Justify the correctness of your solution.
// Hint: Look at the relationship between the signed product x . y and the un-
// signed product x  . y  in the derivation of Equation 2.18.

/*
Solution:
unsigned  x'y' = (x+x_w_1 * 2^w)(y+y_w_1*2^w)
            = xy + (x*y_w_1 + x_w_1*y)*2^w + 2^2w
        => (x'y'>>w) mod (2^w) = xy>>w + xy_w_1 +yx_w_1

*/
#include "stdio.h"
int signed_high_prod(int x, int y);
unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned xm = x >> 31;
    unsigned ym = y >> 31;
    return signed_high_prod(x, y) + x*ym + xm*y;
}

int main() {
    
    return 0;
}