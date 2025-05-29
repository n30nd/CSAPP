#include "stdio.h"
// Write C expressions that evaluate to 1 when the following conditions are true and
// to 0 when they are false. Assume x is of type int.
// A. Any bit of x equals 1.
// B. Any bit of x equals 0.
// C. Any bit in the least significant byte of x equals 1.
// D. Any bit in the most significant byte of x equals 0.
// Your code should follow the bit-level integer coding rules (page 164), with the
// additional restriction that you may not use equality (==) or inequality (!=) tests.


/*
Intution: 
a, b. if all is 1, ~x give 0, when work with all bit in logic true false we only have 0 (0x0) and 1 (else).
So we transform to 0
c, d. 
Assum that: 
    A = B + C
    We can prove A is correct
Now if we want proof B is correct, we proof A and C is correct.
and C can be assum have same property with B (if B correct)

Now with problem C, 
I want proof number with least significant byte of x = 1 is correct
We 1. B = 8-right bit of x (want to proof equal 1s)
      C = 24 bit of 1s
      A = full of 1s
We proof with A (in prob a), now we need to tranform x to the form of 
A = B + C (11111 follow by B)

*/
int check_a(int x) {
    return !(~x);
}

int check_b(int x) {
    return !x;
}

int check_c(int x) {
    // int y = 0xffffff00;
    int y = ~0xff;
    x = x | y;
    return check_a(x);
}

int check_d(int x) {
    // int y = 0xff000000;
    int y = 0xff << ((sizeof(int) - 1) << 3);
    x = x & y;
    return check_b(x);
}
int main() {
    printf("%d\n", check_a(0xffffffff));
    printf("%d\n", check_b(0x0));
    printf("%d\n", check_c(0xff));
    printf("%d\n", check_c(0xff));

    return 0;
}