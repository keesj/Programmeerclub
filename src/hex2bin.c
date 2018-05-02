#include <stdio.h>

int main(int arg, char **argv)
{
    unsigned int hex;
    while (scanf("%02x", &hex) != EOF) {
	printf("%c", hex);
    }
}
