Decimaal, hexadecimaal , ASCII en binair
========================================

Van kinds af aan hebben we met het decimaale stelsel leren rekenen en het rekenen hiermee voelt 
daarom natuurlijk aan. Voor computers is de basis eenheid het binraire stelsel waarbij een waarde 
enkel een 0 of een 1 kan zijn dit noemen we bits. 8 bits samen is een byte. De doelstelling is om een 
beetje gevoel te krijgen voor deze waardes.


Opdracht decimaal
'''''''''''''''''

We gaan een paar programma's schrijven om e.a. om te zetten. en beginnen met het afdrukken van de getallen van 0 tot 255

Schrijf het volgende programmer over in een bestand met naam binary_count.c

.. literalinclude:: src/binary_count_01.c
  :name: binary_count.c
  :linenos:

256 regels passen waarschijnlijk niet op je scherm. Als je rustig door de uitvoer will kunnen lezen kan het handig zijn 
deze door te sturen naar het programma less door gebruik te maken van pipes 

.. code-block:: bash

    ./binary_count | less

Vervolgens kan je met spatie scrollen naar de volgende pagina. Met q kan je uit het programma stappen


Opdracht hexadecimaal
'''''''''''''''''''''

We gaan nu na regel 7 de hexadecimaale waarde toevoegen. Zorg er voor dat net als bij de decimale notatie
de regels netjes aangelijnd blijven. 

.. code-block:: bash

    > man 3 printf

.. literalinclude:: src/binary_count_02.c
  :lineno-match: 
  :lines: 8

De eerste 20 lijnen van de uitvoer zouden er als volg uit moeten zien.

.. literalinclude:: src/binary_count_02_output.txt
  :lineno-match: 
  :lines: 1-20


Opdracht ascii
''''''''''''''


Naast de decimaale waarde en hexadecimaale waardes willen we nu ook graag de ascii representatie zien.
Hiervoor gaan we de "%c" in het printf format statement zetten. 

.. code-block:: bash

    man ascii

Er bestaan niet voor alle waardes tussen 0 tot 255 en ascii representnatie. je zal daarom gebruik moeten maken
van de isprint functie in de ctype librarie gebruik hiervoor een if / else contructie en als het teken niet afgedrukt kan worden
vergang deze dan door en "-" teken.

.. literalinclude:: src/binary_count_03_output.txt
  :lineno-match:
  :lines: 60-80



Opdracht binair
'''''''''''''''

Binnen de computer worden alle waardes binair opgeslagen. We gaan nu een string representatie van 
deze binrair getallen maken. Er is helaas geen printf argument on dit te doen we zullen dus nu zelfs iets schrijven. Voeg
de volgende regels toe

.. literalinclude:: src/binary_count_04.c
  :lineno-match:
  :lines: 21-30
  :emphasize-lines: 2-8

Neem rustig te tijd om naar de binaire waarde te kijken er zit een zeer elegant patroon in.

.. literalinclude:: src/binary_count_04_output.txt


Opdrach hex2bin
'''''''''''''''

Maak een programma die binaire data kan omzetten in hex waardes. Deze waardes moeten worden gelezen van 
de standard invoer en worden geschreven naar de standard uitvoer. gebruikt getchar en printf en leest totdat
getchar() EOF terug geeft

.. code-block:: bash

  echo "Hello, World" | ./bin2hex
  48656c6c6f2c20576f726c640a


Opdracht bin2hex
''''''''''''''''

Maak een programma die binaire data kan omzetten in hex waardes. 
gebruikt scanf om de hex waarde te lezen en printf voor het afdrukken.


.. code-block:: bash

  echo -n "476f6564207a6f210a" | ./hex2bin
  
Bonus
'''''

In het voorbeeld gebruiken we voor de teller variabele van het type int. Wat gebeurd er als we hier een unsigned char
voor gebruiken?


Uitwerkingen
''''''''''''

.. literalinclude:: src/binary_count_04.c
  :linenos:
  :name: binary_count_final.c
  :caption: binary_count_final.c


.. literalinclude:: src/bin2hex.c
  :name: bin2hex.c
  :caption: bin2hex.c

.. literalinclude:: src/hex2bin.c
  :name: hex2bin.c
  :caption: bin2hex.c



