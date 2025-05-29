/*
with w bit
-2^(w-1) <= x, y <= 2^(w-1)-1
if overflow:
case1: 0<x,y<=2^(w-1)-1
0<x+y<2^w-2 , s' = x+y-2^w < -2 < 0

tuonw tu vs x, y <0 => x+y > 0
*/

#include "stdio.h"

int tadd_ok(int x, int y) {
    if(x>0 && y>0) {
        int s = x+y;
        return s > 0;
    }
    if(x<0 && y<0) {
        int s = x+y;
        return s < 0;
    }
    return 1;
}
int tadd_ok_buggy(int x, int y) {
    int sum = x+y;
    return (sum-x == y) && (sum-y == x);
}
int main() {
    int x = -__INT_MAX__ -1 ;
    int y = -1;
    printf("x=%d, y=%d, s=%d\n", x, y, x+y);
    printf("%d\n", tadd_ok_buggy(x, y));
    return 0;
}