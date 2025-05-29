// Write code for a function threefourths that, for integer argument x, computes
// the value of 43 x, rounded toward zero. It should not overflow. Your function should
// follow the bit-level integer coding rules (page 164).


#include "stdio.h"
int devide_power2(int x, int k) {
    int x_sig = x & 0x80000000;
    x_sig && (x= x + (1<<k) - 1);
    return x >> k; 
}

int mul3(int x) {
    return x + (x<<1);
}
int div4(int x) {
    return devide_power2(x, 2);
}
int mul3div4(int x) {
    /*
    x = x' +r where x' is max and x' < x, r = 0, 1, 2, 3
    x * 3/4 = (x'+r) *3/4
            = x'*3/4 + r*3/4
            = (x'/4)*3 + (r*3)/4
    
    */
//    int x1 = x >> 2 << 2;
//    int r = x - x1;
// //    return x1/4*3 + (r*3)/4;
//     printf("x=%d, x1=%d, r=%d\n", x, x1, r);
//     return mul3(div4(x1)) + div4(mul3(r));
     // return div4(mul3(x));
//

    int x1 = div4(x) << 2;
    int r = x - x1;
    return mul3(div4(x1)) + div4(mul3(r));
}


// idea from https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.80/
int mul3div4v2(int x) {
    // x = l + r, l with left l bits of x, r with right r bits of x
    int l = x & ~0x3;
    int r = x & 0x3;

    int ld4 = l >> 2;
    int ld4m3 = ld4 + (ld4 << 1);

    int rm3 = r + (r << 1);
    int is_neg = x & 0x80000000;
    int bias = (1<<2) - 1; //2^k-1
    is_neg && (rm3 += bias);
    int rm3d4 = rm3 >> 2;

    return ld4m3 + rm3d4;
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

    printf("---------------\n");

    printf("%d\n", mul3div4v2(4));
    printf("%d\n", mul3div4v2(5));
    printf("%d\n", mul3div4v2(6));
    printf("%d\n", mul3div4v2(7));
    printf("%d\n", mul3div4v2(-4));
    printf("%d\n", mul3div4v2(-5));
    printf("%d\n", mul3div4v2(-6));
    printf("%d\n", mul3div4v2(-7));

    return 0;
}