#include <stdio.h>

void mijn_int(int x)
{
    x = x + 1;
    printf("%s:%d\tx = %d\n", __FUNCTION__, __LINE__, x);
    printf("%s:%d\tadres van x = %p\n", __FUNCTION__, __LINE__, &x);
}

void mijn_pointer_aanroep(int *x_ptr)
{
    *x_ptr = 45;
    printf("%s:%d\tx = %d\n", __FUNCTION__, __LINE__, *x_ptr);
    printf("%s:%d\tadres van x = %p\n", __FUNCTION__, __LINE__, x_ptr);
}

int main()
{
    int x = 12;
    printf("%s:%d\tx = %d\n", __FUNCTION__, __LINE__, x);
    printf("%s:%d\tadres van x = %p\n", __FUNCTION__, __LINE__, &x);

    mijn_int(x);
    printf("%s:%d\tx = %d\n", __FUNCTION__, __LINE__, x);
    printf("%s:%d\tadres van x = %p\n", __FUNCTION__, __LINE__, &x);

    mijn_pointer_aanroep(&x);
    printf("%s:%d\tx = %d\n", __FUNCTION__, __LINE__, x);
    printf("%s:%d\tadres van x = %p\n", __FUNCTION__, __LINE__, &x);

    return 0;
}
