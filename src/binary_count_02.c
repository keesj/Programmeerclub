#include <stdio.h>

int main()
{
    // we gaan van 0 tot 255 tellen
    for (int teller = 0; teller <= 255; teller++) {
	printf("%03d ", teller);
	printf("%02x ", teller);
	printf("\n");

    }
}
