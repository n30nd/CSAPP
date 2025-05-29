/*
2.67 ◆◆
You are given the task of writing a procedure int_size_is_32() that yields 1
when run on a machine for which an int is 32 bits, and yields 0 otherwise. You are
not allowed to use the sizeof operator. Here is a first attempt:
1
2
3
4
5
6
/* The following code does not run properly on some machines */
// int bad_int_size_is_32() {
// /* Set most significant bit (msb) of 32-bit machine */
// int set_msb = 1 << 31;
// /* Shift past msb of 32-bit word */
// int beyond_msb = 1 << 32;
// 7
/* set_msb is nonzero when word size >= 32
beyond_msb is zero when word size <= 32
return set_msb && !beyond_msb;
8
9
10
11
*/
/*
}
When compiled and run on a 32-bit SUN SPARC, however, this procedure
returns 0. The following compiler message gives us an indication of the problem:
warning: left shift count >= width of type

A. In what way does our code fail to comply with the C standard?
B. Modify the code to run properly on any machine for which data type int is
at least 32 bits.
C. Modify the code to run properly on any machine for which data type int is
at least 16 bits.
*/

#include "stdio.h"

// run on machine has int at least 32 bits
int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return !beyond_msb;
}

// run on machine has int at least 16 bits
int int_size_is_32_for_least_16bit_machine() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && (!beyond_msb); // int= 32 thi vs may 16 bit !beyond return 1 roi, xet ca xem no co bieu dien dc so 32 bit k nx
}

int main() {
    

    return 0;
}