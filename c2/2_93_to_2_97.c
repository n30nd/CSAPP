// 2.93
//  Following the bit-level floating-point coding rules, implement the function with
//  the following prototype:
//  /* Compute |f|. If f is NaN, then return f. */
//  float_bits float_absval(float_bits f);
//  For floating-point number f , this function computes |f |. If f is NaN, your
//  function should simply return f .
//  Test your function by evaluating it for all 232 values of argument f and com-
//  paring the result to what would be obtained using your machine’s floating-point
//  operations.

// 2.94
//  Following the bit-level floating-point coding rules, implement the function with
//  the following prototype:
//  /* Compute 2*f. If f is NaN, then return f. */
//  float_bits float_twice(float_bits f);
//  For floating-point number f , this function computes 2.0 . f . If f is NaN, your
//  function should simply return f .
//  Test your function by evaluating it for all 232 values of argument f and com-
//  paring the result to what would be obtained using your machine’s floating-point
//  operations.

// 2.95
//  Following the bit-level floating-point coding rules, implement the function with
//  the following prototype:
//  /* Compute 0.5*f. If f is NaN, then return f. */
//  float_bits float_half(float_bits f);
//  For floating-point number f , this function computes 0.5 . f . If f is NaN, your
//  function should simply return f .
//  Test your function by evaluating it for all 232 values of argument f and com-
//  paring the result to what would be obtained using your machine’s floating-point
//  operations.

// 2_96
// Following the bit-level floating-point coding rules, implement the function with
// the following prototype:
// /*
// * Compute (int) f.
// * If conversion causes overflow or f is NaN, return 0x80000000
// */
// int float_f2i(float_bits f);
// For floating-point number f , this function computes (int) f . Your function
// should round toward zero. If f cannot be represented as an integer (e.g., it is out
// of range, or it is NaN), then the function should return 0x80000000.
// Test your function by evaluating it for all 232 values of argument f and com-
// paring the result to what would be obtained using your machine’s floating-point
// operations.

// 2.97
//  Following the bit-level floating-point coding rules, implement the function with
//  the following prototype:
//  /* Compute (float) i */
//  float_bits float_i2f(int i);
//  For argument i, this function computes the bit-level representation of
//  (float) i.
//  Test your function by evaluating it for all 232 values of argument f and com-
//  paring the result to what would be obtained using your machine’s floating-point
//  operations.

#include <stdio.h>
#include <assert.h>
typedef unsigned float_bits;
float u2f(float_bits f)
{
    return *(float *)&f;
}
float_bits f2u(float f)
{
    return *(float_bits *)&f;
}
float_bits float_absval(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    unsigned is_neg = sign;
    if (is_neg)
    {
        sign = !sign;
    }
    return (sign << 31) | (exp << 23) | frac;
}

// 2.94
float_bits float_twice(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && !frac)
        return f;
    if (exp == 0)
    {
        // denormalized
        frac <<= 1;
    }
    else
    {
        if (exp == 0xFF - 1)
        {
            exp = 0xFF;
            frac = 0;
        }
        else
        {
            exp += 1;
        }
    }
    return (sign << 31) | (exp << 23) | frac;
}

// 2.95
float_bits float_half(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    unsigned two_least_bits = frac & 0x3;
    unsigned addition = two_least_bits == 0x3;
    if (exp == 0xFF)
        return f;
    if (exp == 0)
    {
        // denormalized
        // even round, if 2 least bits of frac is 11 then frac =(frac+1) >> 1

        frac = (frac + addition) >> 1;
    }
    else
    {
        // normalized
        if (exp == 1)
        {
            // from normalize to denormalize
            exp = 0;
            frac = (frac & 0x800000) + addition;
            frac >> 1;
        }
        else
            exp -= 1;
    }
    return (sign << 31) | (exp << 23) | frac;
}

// 2.96
int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    int bias = 0x7F;

    int e = (int)exp - bias;
    if (e < 0)
    {
        return 0;
    }
    else if (e >= 31)
    {
        return 0x80000000;
    }
    else
    {
        // 0 <= e <31
        // normalized
        unsigned m = frac | 0x800000;
        if (e < 23)
        {
            m >>= (23 - e);
        }
        else
        {
            m <<= (e - 23);
        }
        return sign ? -(int)m : (int)m;
    }
}

// 2.97
float_bits float_i2f(int i)
{
    unsigned exp;
    unsigned frac;
    unsigned bias = 0x7F;

    unsigned sign = (i >> 31) & 0x1;
    if (i == 0x80000000)
    {
        exp = bias + 31;
        frac = 0;
    }
    else
    {
        sign && (i = -i);

        int left_most_1 = -1;
        // find most significant bit = 1 (not bit 31)
        for (int j = 30; j >= 0; j--)
        {
            unsigned isok = (i >> j) & 0x1;
            if (isok)
            {
                left_most_1 = j;
                break;
            }
        }
        if (left_most_1 == -1)
        {
            frac = 0;
            exp = 0;
        }
        else
        {
            exp = left_most_1 + bias;
            frac = left_most_1 <= 23 ? (unsigned)i << (32 - left_most_1) >> 9 : (unsigned)i << (32 - left_most_1) >> (32 - 23);
        }
    }
    return (sign << 31) | (exp << 23) | frac;
}

int main(int argc, char *argv[])
{
    // printf("2_93 abs of -0.12345 is %f\n", u2f(float_absval(f2u(-0.12345))));
    // printf("2.94: 2*0.1234=%f\n", u2f(float_twice(f2u(0.1234))));

    // printf("%d\n", float_f2i(f2u(12345.67)));
    int x = 0;
    printf("hex of %d is: %x\n", x, x);
    printf("%f\n", u2f(float_i2f(x)));

    // int x = 0x80000000;
    // printf("%d\n", x);
    // printf("%f\n, ", (float) x);
    return 0;
}