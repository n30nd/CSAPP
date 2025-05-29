// The library function calloc has the following declaration:
// void *calloc(size_t nmemb, size_t size);
// According to the library documentation, “The calloc function allocates memory
// for an array of nmemb elements of size bytes each. The memory is set to zero. If
// nmemb or size is zero, then calloc returns NULL.”
// Write an implementation of calloc that performs the allocation by a call to
// malloc and sets the memory to zero via memset. Your code should not have any
// vulnerabilities due to arithmetic overflow, and it should work correctly regardless
// of the number of bits used to represent data of type size_t.
// As a reference, functions malloc and memset have the following declarations:

// void *malloc(size_t size);
// void *memset(void *s, int c, size_t n);

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//calloc = malloc + memset to zero
void* write_calloc(size_t nmemb, size_t size) {
    if(nmemb == 0 || size == 0) return NULL;
    void* p = malloc(nmemb*size);
    if(p==NULL) return NULL;
    memset(p, 0, nmemb*size);
    return p;
}

int main() {
    int* p = (int*)write_calloc(5, sizeof(int));
    for(int i=0;i<5;i++) {
        printf(" %d ", *(p+i));
    }
    printf("\n");
    free(p);
    return 0;
}