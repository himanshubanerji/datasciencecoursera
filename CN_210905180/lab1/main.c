#include <stdio.h>
#include <string.h>

int main() {
    char ch[256];
    gets(ch);

    printf("Length is: %ld\n", strlen(ch));

    ch[strlen(ch)] = '4';
    printf("Length is: %ld\n", strlen(ch));

    return 0;
}