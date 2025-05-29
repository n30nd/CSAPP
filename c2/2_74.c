// Write a function with the following prototype:
// /* Determine whether arguments can be subtracted without overflow */
// int tsub_ok(int x, int y);
// This function should return 1 if the computation x-y does not overflow.



#include "stdio.h"

int tsub_ok(int x, int y) {
    int sub = x - y;
    int mask = 0x80000000;
    //x =0, y = INT_MIN => overflow
    // res = !(!x && !(y^mask));
    int res = x || (y^mask);
    //check1 if x >0, y <0, sub < 0
    int check1 = !(x&mask) && (y&mask) && (sub&mask);
    //check2 if x <0, y>0, sub > 0
    int check2 = (x&mask) && !(y&mask) && (sub&mask);

    res = res && (check1 || check2);
    return res;
}


//version of https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.74/
int tsub_ok2(int x, int y)
{
    int res = 1;

    (y == 0x80000000) && (res = 0);
    // if (y == INT_MIN) res = 0;
    printf("res after compare: %d\n", res);
    int sub = x - y;
    int pos_over = x > 0 && y < 0 && sub < 0;
    int neg_over = x < 0 && y > 0 && sub > 0;

    res = res && !(pos_over || neg_over);

    return res;
}
int main() {
    int min_int = 0x80000000;
    // x = 1, y = INT_MIN don't lead to overflow, so the solution2 is incorrect
    printf("%d\n", tsub_ok(1, min_int));
    printf("%d\n", tsub_ok2(1, min_int));
    return 0;
}