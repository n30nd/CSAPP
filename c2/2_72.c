// You are given the task of writing a function that will copy an integer val into a
// buffer buf, but it should do so only if enough space is available in the buffer.
// Here is the code you write:
// /* Copy integer into buffer if space is available */
// /* WARNING: The following code is buggy */
// void copy_int(int val, void *buf, int maxbytes) {
// if (maxbytes-sizeof(val) >= 0)
// memcpy(buf, (void *) &val, sizeof(val));
// }
// This code makes use of the library function memcpy. Although its use is a bit
// artificial here, where we simply want to copy an int, it illustrates an approach
// commonly used to copy larger data structures.
// You carefully test the code and discover that it always copies the value to the
// buffer, even when maxbytes is too small.
// A. Explain why the conditional test in the code always succeeds. Hint: The
// sizeof operator returns a value of type size_t.
// B. Show how you can rewrite the conditional test to make it work properly.

//this code I copy from https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.72/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void copy_int(int val, void* buf, int maxbytes) {
    if (maxbytes >= (int) sizeof(val)){
        memcpy(buf, (void*)&val, sizeof(val));
    }
}
int main() {
    int maxbytes = sizeof(int)*10;
    void* buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    printf("%x\n", val);
    printf("%x\n", *(int*)buf);


    free(buf);
    return 0;
}