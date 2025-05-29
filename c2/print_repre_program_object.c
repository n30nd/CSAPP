#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i=0; i<len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));

}
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_binary(byte_pointer start, size_t len) {
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 7; j >= 0; j--) {
            printf("%d", (start[i] >> j) & 1);
        }
        printf(" "); // Add a space between bytes for readability
    }
    printf("\n");
}
int main() {
    // int x = 0x123456789;
    // show_int(x);

    // float x = 1.21;
    // show_float(x);

    // int x = 2;
    // int *p = &x;
    // printf("%p\n",p);
    // show_pointer(p);


    // short val = 12345;
    // short mval = -val;

    // printf("Hex for short (%d): ", val);
    // show_bytes((byte_pointer) &val, sizeof(short));
    // printf("Binary for short (%d): ", val);
    // show_binary((byte_pointer) &val, sizeof(short));
    // printf("\n");

    // printf("Hex for short (%d): ", mval);
    // show_bytes((byte_pointer) &mval, sizeof(short));
    // printf("Binary for short (%d): ", mval);
    // show_binary((byte_pointer) &mval, sizeof(short));
    // printf("\n");

    unsigned u = 2147483648;
    printf("Hex for short (%d): ", u);
    show_bytes((byte_pointer) &u, sizeof(unsigned));
    printf("Binary for short (%d): ", u);
    show_binary((byte_pointer) &u, sizeof(unsigned));
    printf("\n");
    return 0;
}