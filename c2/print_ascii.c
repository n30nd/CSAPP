#include <stdio.h>

int main() {
    printf("ASCII Character table");
    printf("Char    |   Dec  | Hex\n");
    for (int i=0; i<= 126; i++) {
        printf("%c  | %3d   | 0x%.2X\n", i, i, i);
    }
    // signed char sc = 0xFF; // -1
    // unsigned char uc = 0xFF; // 255
    // printf("%c\n", sc); // Có thể in ký tự không mong muốn hoặc gây lỗi
    // printf("%c\n", uc); // In ký tự tương ứng với 255 (ví dụ: ÿ trong Windows-1252)
    
    return 0;
}