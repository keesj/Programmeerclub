#include <stdio.h>

int main(int argc,char **argv)
{
    unsigned char waarde =0;
    for (int x =0 ; x < 300 ; x++){
        printf("stap %d: %d\n", x,waarde);
        waarde = waarde +255;
    }
    return 0;
}
