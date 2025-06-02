// We are running programs on a machine where values of type int have a 32-
// bit two’s-complement representation. Values of type float use the 32-bit IEEE
// format, and values of type double use the 64-bit IEEE format.
// We generate arbitrary integer values x, y, and z, and convert them to values
// of type double as follows:
// /* Create some arbitrary values */
// int x = random();
// int y = random();
// int z = random();
// /* Convert to double */
// double
// dx = (double) x;
// double
// dy = (double) y;
// double
// dz = (double) z;
// For each of the following C expressions, you are to indicate whether or
// not the expression always yields 1. If it always yields 1, describe the underlying
// mathematical principles. Otherwise, give an example of arguments that make
// it yield 0. Note that you cannot use an IA32 machine running gcc to test your
// answers, since it would use the 80-bit extended-precision representation for both
// float and double.
// A. (float) x == (float) dx
// B. dx - dy == (double) (x-y)
// C. (dx + dy) + dz == dx + (dy + dz)
// D. (dx * dy) * dz == dx * (dy * dz)
// E. dx / dx == dz / dz


#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>


int random_int(void) {
    // Tạo số ngẫu nhiên 32-bit
    unsigned int rand_val = ((unsigned int)rand() << 16) | rand();
    
    // Chuyển đổi sang kiểu int, đảm bảo phạm vi từ INT_MIN đến INT_MAX
    return (int)(rand_val % (INT_MAX + 1U));
}
int A(int x, double dx) {
    return (float)x == (float)dx;
}

int B(double dx, double dy, int x, int y) {
    return (dx - dy) == (double)(x - y);
}

int C(double dx, double dy, double dz) {
    return (dx + dy) + dz == dx + (dy + dz);
}

int D(double dx, double dy, double dz) {
    double d1 = (dx * dy) * dz;
    double d2 = dx * (dy * dz);

    if (d1 != d2) {
        printf("d1: %lf, d2: %lf\n", d1, d2);
    }

    return d1 == d2;
}

int E(double dx, double dz) {
    printf("dx: %lf, dz: %lf\n", dx, dz);
    printf("dx/dx: %lf, dz/dz: %lf\n", dx / dx, dz / dz);
    return dx / dx == dz/dz;
}
int main(int argc, char* argv[]) {
    srand(time(NULL));

    int x = random_int();
    int y = random_int();
    int z = random_int();

    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;


    printf("x: %x, y: %x, z: %x\n", x, y, z);

    // A. (float) x == (float) dx
    // for(int x=INT_MIN; x <= INT_MAX; x++) {
    //     double dx = (double)x;
    //     if (!A(x, dx)) {
    //         printf("A failed for x = %d\n", x);
    //         break;
    //     }
    // }

    // printf("A: %d\n", A(x, dx));
    // printf("B: %d\n", B(dx, dy, x, y));
    // printf("C: %d\n", C(dx, dy, dz));
    dx = (double) (1<<30)+1;
    dy = (double) (1<<23)+1;
    // dz = 2e20+5;
    dz = (double) (1<<24)+1;
    printf("D: %d\n", D(dx, dy, dz));

    // printf("E: %d\n", E(dx, 0.0));
    return 0;
}