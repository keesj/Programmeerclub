#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 40

void verseutel(char *invoer, int sleutel)
{
    while (1) {
	//we gaan nu telkens de waarde uit het geheugen laden 
	//het gebruik van * als operator heet het dereferencen (van een adres terug naar de waarde)
	char waarde = *invoer;
	if (waarde == '\0' || waarde == '\n') {
	    return;
	}
	// Er kan hier bij het versleutelen van alles mis gaan. Waarde is van het type char
	// en kan dus maar 256 verschillende waardes aannemen. 
	waarde = waarde + sleutel;

	//omgekeerd vertellen we de compiler hier dat we in inhoud van waarde willen opslaan waar 
	//invoer naar wijst in het geheugen.
	*invoer = waarde;
	//invoer bevat het adres van het teken(niet het teken zelf) en in 
	//C mag je ook met deze waarde spelen maar pas op! deze pointer kunnen
	//overall in het geheugen wijzen.
	invoer++;		// we gaan iets verder in het geheugen. Hoe ver? (sizeof(char))
    }
}


int main(int argc, char **argv)
{
    int sleutel = 0;
    if (argc != 2) {
	fprintf(stderr,
		"Dit programma verlangt een sleutel als argument\n: %s [sleutel]\n",
		argv[0]);
	return 1;
    }
    sleutel = atoi(argv[1]);

    //We vragen hier om een stukje geheugen en maken het leeg
    char *invoer = malloc(MAX_LEN);
    memset(invoer, '\0', MAX_LEN);

    if (fgets(invoer, MAX_LEN, stdin) == NULL) {
	fprintf(stderr, "Er ging iets fout tijdens het lezen\n");
	return 1;
    }
    verseutel(invoer, sleutel);

    printf("%s", invoer);
    return 0;
}
