/* with x, y is unsinged
0 <= x, y <= Umax_w
s = x+y
if no overflow: s >=x, y
if overflow s < x (or y) 
    because now s = x+y - 2^w
    (y-2^w) < 0 so s < x

*/
#include "stdio.h"

int uadd_ok(unsigned x, unsigned y) {
    unsigned s = x + y;
    printf("x=%u, y=%u, s=%u\n", x, y, s);
    return s > x;
}

int main() {
    unsigned x = 4294967293;
    unsigned y = 3;
    printf("%d\n", uadd_ok(x, y));
    return 0;
}