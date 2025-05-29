/*WARNING: THIS IS BUGGY CODE*/
#include "stdio.h"
float sum_elements(float a[], unsigned length) {
    int i;
    float result = 0;

    for (i=0; i<= length-1; i++) {
        printf("CHECKKKKKKKKK\n");
        result += a[i];
    }
    return result;
}
int main(){
    float a[] = {1.2, 2.3, 3.2};

    float res = sum_elements(a, 0);
    printf("%f\n", res);

    return 0;
}