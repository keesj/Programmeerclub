Pointers and references
=======================

Tot nu toe hebben we verschillende type variablen zoals de int en float leren kennen maar voor deze oefening zullen we iets nieuws leren over computers. Computers kunnen over het algemeen niet direct in het werkgeheugen operaties zoals optellen of aftrekken uitvoeren. Ze moeten eerst de waarde laden in een register om er vervolgens operatie op uit te kunnen voeren. Er zijn vaak maar weinig registers en als de operatie is uitgevoerd moeten die waarde weer terug in het geheugen worden gezet. Vaak gebeurd dit ontzichtbaar voor de programeur. Een regel zoals x = x +1 zal x uit het werk geheugen halen, 1 bij x optellen en x weer terug in het werkgeheugen zetten.

.. note::

    Pointer zijn vrij moeilijk te begrijpen en gevaarlijk in gebruik en zorgen voor de meest gevaarlijke bugs in code. Zij zorgen er ook voor dat C als taal zeer geschikt is om andere talen mee te schrijven of besturingssystemen me te maken.


Variabelen leven in het geheugen maar worden in registers bewerkt
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

Neem het voglende programma over en compileer het met het volgende commandos

.. code-block:: bash

    gcc -Wall -m32 -g -O0 -o oneplusone oneplusone.c

.. literalinclude:: src/oneplusone.c
  :caption: oneplusone.c
  :linenos:

Typische uitvoer:

.. literalinclude:: src/oneplusone_output.txt

We gaan nu een kijkje nemen in de machine code van deze functie

.. code-block:: bash

    objdump -S oneplusone > oneplusone.dump.txt

Bekijk nu het oneplusone.dump.txt bestand en zoek naar "main" of "x = x + 1"

We hebben hier een voorbeeldje

.. literalinclude:: src/oneplusone.dump.txt
    :caption: oneplusone.dump.txt
    :lines: 205-210

je hoeft niet alles te begrijpen maar de eesrte mov instructies verplaatst data van het geheugen naar een register %eax, vervolgens wordt 1 bij %eax opgeteld. Als laatste wordt %eax naar het geheugen verplaatst.

Argumenten van functie worden "by value" doorgegeven
'''''''''''''''''''''''''''''''''''''''''''''''''''''

Neem het volgende programma over en probeer er voor te zorgen dat x in de main functie wordt aangepast

.. literalinclude:: src/by_value.c
  :caption: by_value.c
  :linenos:


Een variabele heeft en adres
''''''''''''''''''''''''''''

De taal C bied echter ook direct toegang to het geheugen door middel van verwijzingen en referenties.

We hebben in de voorgaande lessen reeds een aantal keer de & operator gebruik voor de aanroep van scanf.
De & operator vertaalt een variabele in een geheugen adres. Bij scanf werd dus niet de waarde van de variable doorgegeven maar het geheugen adres waar scanf de waarde moest gaan schrijven. De reden dat we het adres moesten doorgeven is dat de argumenten die een functie mee krijgt kopien zijn van het origineel. In het scanf voorbeeld zouden we dan een kopie van de 0 waarde mee hebben geven aan scanf. De scanf functie kan hier niets mee. Met een kopie van het adres wel.
de & operator in het voorbeeld kan je het beste lezen als "het adres van"

.. literalinclude:: src/has_address.c
  :caption: has_adress.c
  :linenos:

Voer het een paar keer uit. Wat valt je op?

Een variabele die een adres bevat noemen we een pointer
'''''''''''''''''''''''''''''''''''''''''''''''''''''''

Een verwijzing naar een adres wordt gangbaar een pointer genoemd en gedeclareed met "*". Pointers in C mogen een type hebben zo kan men een float of een int pointer maken maar er zijn veel meer mogelijkheden. 

https://xkcd.com/138/

.. warning::

    Het gebruik van * in een declaratie en in gebruikt zijn elkars tegenovergestelde

    char \*mijn_pointer; geeft aan dat mijn_pointer en geheugen adres zou moeten bevatten die naar een char wijst.

    Als men later in code \*mijn_pointer schrijft (de dereference operator) wordt exact het omgekeerde bekreikt. \*mijn_pointer = 'a' zorgt er voor dat de char 'a' op de geheugenlocatie waar mijn_pointer naar wijst geschreven. 

Hier is een voorbeeld

.. literalinclude:: src/pointers.c
  :caption: pointers.c
  :linenos:

Pointers zijn ook maar data
'''''''''''''''''''''''''''

Met pointers kunnen ook bewerkingen gedaan worden. 

.. todo:: 

    Add info about pointer arimetrics

Uitwerkingen
''''''''''''

We zagen dat het adres van x niet altijd op dezelfde plek was. Dit is een maatregel die genomen is om het moelijker te maken voor hackers om te kunnen gokken waar waardes in het geheugen zitten. Dat is best handig maar niet tijdens het leren programeren!

.. code-block:: bash

    > setarch `uname -m` -R ./oneplusone
    # hint man setarch
