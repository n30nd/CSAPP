// You have been assigned the task of writing a C function to compute a floating-
// point representation of 2x . You decide that the best way to do this is to directly
// construct the IEEE single-precision representation of the result. When x is too
// small, your routine will return 0.0. When x is too large, it will return +∞. Fill in the
// blank portions of the code that follows to compute the correct result. Assume the function u2f returns a floating-point value having an identical bit representation
// as its unsigned argument.

#include <stdio.h>
#include <assert.h>
#include <math.h>
float u2f(unsigned u) {
    return *(float*)&u;
}

float fpwr2(int x)
{
    // float
    //  s(1), exp(8), frac(23);

    /* Result exponent and fraction */
    unsigned exp, frac;
    unsigned u;
    int bias = 127; // Bias for single-precision float

    // v = 2^x
    // v_denormalized_min = 2^(1-bias)*2^-23 = 2^(1-bias-23)
    if (x < 1 - bias - 23)
    {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    }
    // v_normalized_min = 2^(1-bias)*1.0//e=0(7)1, frac=00
    else if (x < 1 - bias)
    {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (x + 23  + bias - 1); // v = 2^x = 2^(1-bias)*0.frac
        // then frac = 2^x*2^23*2^(bias-1)
    }
    // normalized
    //  v= 2^x = 2^(e-bias)*1.frac
    //  v_max with e = 01(7)_2= 2^7-1 //127
    //   frac = 1(23) //but I represent int so frac = 1.0
    //  v = 2^(127-bias)*1.0
    //  e-bias = x

    else if (x < (1<<8) - 1 - bias)
    {
        /* Normalized result. */
        exp = x + bias;
        frac = 0;
    }
    else
    {
        /* Too big. Return +oo */
        exp = 0xFF;
        frac = 0;
    }
    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

int main(int argc, char *argv[])
{
    // printf("fpwr2(0) = %f\n", fpwr2(0));
    // printf("powf(2, 0) = %f\n", powf(2, 0));
    // printf("fpwr2(100) = %f\n", fpwr2(100));
    // printf("powf(2, 100) = %f\n", powf(2, 100));

    assert(fpwr2(0) == powf(2, 0));
    assert(fpwr2(100) == powf(2, 100));
    assert(fpwr2(-100) == powf(2, -100));
    assert(fpwr2(10000) == powf(2, 10000));
    assert(fpwr2(-10000) == powf(2, -10000));
    return 0;
}