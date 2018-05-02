#include <stdio.h>

void mijn_pointer_aanroep(int *x_ptr)
{
    *x_ptr = 45;
}

int main()
{
    int x = 12;
    mijn_pointer_aanroep(&x);
    printf("x is %d\n",x);
    return 0;
}
