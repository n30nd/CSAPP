// Write code for a function mul3div4 that, for integer argument x, computes 3 ∗
// x/4 but follows the bit-level integer coding rules (page 164). Your code should
// replicate the fact that the computation 3*x can cause overflow.

#include "stdio.h"

int devide_power2(int x, int k) {
    int x_sig = x & 0x80000000;
    x_sig && (x= x + (1<<k) - 1);
    return x >> k; 
}


int mul3div4(int x) {
    return devide_power2(x + (x<<1), 2);
}


int main() {
    printf("%d\n", mul3div4(4));
    printf("%d\n", mul3div4(5));
    printf("%d\n", mul3div4(6));
    printf("%d\n", mul3div4(7));
    printf("%d\n", mul3div4(-4));
    printf("%d\n", mul3div4(-5));
    printf("%d\n", mul3div4(-6));
    printf("%d\n", mul3div4(-7));
    return 0;
}