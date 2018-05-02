#include <stdio.h>
#include <ctype.h>


int main()
{
    // we gaan van 0 tot 255 tellen
    for (int teller = 0; teller <= 255; teller++) {
	printf("%03d ", teller);
	printf("%02x ", teller);

	// gebruik de isprint functie van ctype om te weten of
	// de waarde en ascii representatie heeft.
	if (isprint(teller)) {
	    printf("%c ", teller);
	} else {
	    printf("- ");
	}

	printf("\n");

    }
}
