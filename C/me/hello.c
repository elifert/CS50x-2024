#include <stdio.h>
#define MAX_LENGTH 100

int main(void) {
    char name[MAX_LENGTH];
    printf("What's your name? ");
    scanf("%s", name);
    printf("hello, %s\n", name);
}
