#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    // we gaan van 0 tot 255 tellen
    for (int teller = 0; teller <= 255; teller++) {
	printf("%03d ", teller);

	printf("%02x ", teller);

	if (isprint(teller)) {
	    printf("%c ", teller);
	} else {
	    printf("- ");
	}

	// helaas heeft de c librarie geen standard functie voor het
	// onzetten van binaire getallen naar en door mensen leesbaar
        // geheel.
	for (int bit_nummer = 7; bit_nummer >= 0; bit_nummer--) {
	    if ((teller >> bit_nummer & 1) == 1) {
		printf("1");
	    } else {
		printf("0");
	    }
	}
	printf("\n");
    }
}
