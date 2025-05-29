// Write code for a function with the following prototype:
// /* Divide by power of 2. Assume 0 <= k < w-1 */
// int divide_power2(int x, int k);
// The function should compute x/2k with correct rounding, and it should follow
// the bit-level integer coding rules (page 164).





// (x<0 ? x+(1<<k)-1 : x) >> k

#include "stdio.h"
int devide_power2(int x, int k) {
    int x_sig = x & 0x80000000;
    x_sig && (x= x + (1<<k) - 1);
    return x >> k; 
}
int main() {
    printf("%d\n", devide_power2(-7, 1));
    return 0;
}