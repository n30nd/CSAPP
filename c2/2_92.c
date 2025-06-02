// Following the bit-level floating-point coding rules, implement the function with
// the following prototype:
// /* Compute -f. If f is NaN, then return f. */
// float_bits float_negate(float_bits f);
// For floating-point number f , this function computes −f . If f is NaN, your
// function should simply return f .
// Test your function by evaluating it for all 232 values of argument f and com-
// paring the result to what would be obtained using your machine’s floating-point
// operations.

#include <stdio.h>
#include <assert.h>
typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    // if (exp == 0xFF)
    // {
    //     if (!frac)
    //     {
    //         return f;
    //     }
    // }
    if(exp == 0xFF && !frac) {
        return f;
    }
    unsigned new_sign = !sign;
    return (new_sign << 31) | (exp << 23) | frac;
}
float u2f(float_bits f)
{
    return *(float *)&f;
}
float_bits f2u(float f)
{
    return *(float_bits *)&f;
}
int main(int argc, char *argv[])
{
    // assert(-1.0 * u2f(0x12345678) == float_negate(0x12345678));
    float_bits flb_x = 0xfffffc0e;
    printf("%lf\n", -1.0 * u2f(flb_x));
    printf("%lf\n", u2f(float_negate(flb_x)));
    printf("%d\n",-1.0 * u2f(flb_x) == u2f(float_negate(flb_x)));
    // for (float_bits u = 0; u < 0xFFFFFFFF; u++)
    // {
    //     if (-1.0 * u2f(u) != u2f(float_negate(u)))
    //     {
    //         printf("float_bit don't correct: %x\n", u);
    //     }
    // }
 
    return 0;
}