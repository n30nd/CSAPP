// Suppose we are given the task of generating code to multiply integer variable x
// by various different constant factors K. To be efficient, we want to use only the
// operations +, -, and <<. For the following values of K, write C expressions to
// perform the multiplication using at most three operations per expression.
// A. K = 17
// B. K = −7
// C. K = 60
// D. K = −112

#include "stdio.h"

int A(int x) {
    //17 = 2^4 + 2^0
    return (x<<4) + x;
}

int B(int x) {
    //-7 = -2^3 + 2^0
    return x - (x<<3);
}

int C(int x) {
    //60 = 2^6- 2^2
    return (x<<6) - (x<<2);
}

int D(int x) {
    // -112 = -2^7 + 2^4
    return (x<<4) - (x<<7);
}


int main() {
    
    return 0;
}