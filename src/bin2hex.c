#include <stdio.h>

int main(int argc, char **argv)
{
    int invoer = 0;
    while ((invoer = getchar()) != EOF) {
	printf("%02x", invoer);
    }
    return 0;
}
