/* Determine whether string s is longer than string t */
/* WARNING: This function is buggy */
#include "stdio.h"
#include "string.h"
int strlonger(char *s, char *t) {
    return strlen(s) - strlen(t) > 0;
}
int main(){
    char* s = "nam";
    char* t = "quang";

    printf("%d\n", strlonger(s,s));
    return 0;
}