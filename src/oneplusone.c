#include <stdio.h>

int main()
{
    volatile int x = 0;
    printf("x heeft waarde %d\n", x);
    x = x + 1;
    printf("x heeft nu waarde %d\n", x);
    return 0;
}
