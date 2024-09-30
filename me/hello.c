#include <stdio.h>

int main(void)
{
    char name[25];
    printf("what's your name?");
    scanf("%s", name);
    printf("Hello,%s\n", name);
    return 0;
}
