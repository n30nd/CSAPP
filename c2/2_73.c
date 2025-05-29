// Write code for a function with the following prototype:
// /* Addition that saturates to TMin or TMax */
// int saturating_add(int x, int y);
// Instead of overflowing the way normal two’s-complement addition does, sat-
// urating addition returns TMax when there would be positive overflow, and TMin
// when there would be negative overflow. Saturating arithmetic is commonly used
// in programs that perform digital signal processing.
// Your function should follow the bit-level integer coding rules (page 164).

#include "stdio.h"
int saturating_add(int x, int y) {
    // If x + y is overflow: 
    //     pos: x>0, y>0 , x+y < 0 
    //     neg: __________________
    int mask = 0x80000000;
    int sum = x + y;
    int pos_check = !(x&mask) && !(y&mask) && (sum&mask);
    int neg_check = (x&mask) && (y&mask) && !(sum&mask);


    pos_check && (sum = __INT_MAX__);
    neg_check && (sum = -__INT_MAX__-1);
    return sum;
    
}

int main() {
    printf("%d\n", saturating_add(0x7FFFFFFF, 0x7FFFFFFF));
    printf("INT_MAX = %d", __INT_MAX__);
    return 0;
}