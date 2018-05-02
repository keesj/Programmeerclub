Caesar versleuteling
====================

Het versleutelen van berichten is iets waar men zich sinds mensenheugeniss me bezig houd. 
In de tijd van de romeinen gebruikte Julius Ceasar een substituties versleuteling. 
Deze versleuteling is later Caesar versleuteling gaan heten

Dit is een eenvoudige vorm van versleuteling waarbij volgens een vaste formule 
één teken door het andere wordt vervangen op zo een manier dat het vervolgens 
terug kan worden vertaald. 

Om dit te doen geven wel elke letter van het alphabet een bepaalde waarde. 
Met deze waarde (de ascii waarde) gaan we een wiskundige berekening doen die omkeerbaar is. 
In dit geval optellen. 


Voor onze versleuteling gaan wij een vergelijkbare aanpak kiezen. We gaan een regel tekst lezen en in het geheugen opslaan. Vervolgens gaan we het geheugenadres aan een functie doorgeven en deze zal de versleuteling voor ons uitvoeren. We gaan ook nog gebruik maken van een andere eigenschap van pointers namenlijk dat we op pointers zelf bewerkingen kunnen doen zoals "1" bij optellen om naar het volgende geheugen adres te wijzen.

voor het opslaan van deze waarde gaan we een variable van het type "unsigned char" gebruikten. Deze kan een waarde tussen 0 en 255 (inbegrepen innemen). Niet geheel toevallig is dat twee tot de achtste macht en past dit altijd in een byte (8 bits). 

Neem het volgende programma over en probeer het met verschillende input en sleutels

.. literalinclude:: src/caesar_cipher.c
  :caption: caesar_cipher.c
  :linenos:

.. code-block: bash

    echo "School ik leuk" | ./caesar_cipher 0

.. code-block:: bash

    echo "School ik leuk" | ./caesar_cipher 42
 

Het zal je mischien opvallen dat bij het versleutelen sommige tekens niet goed meer op het scherm kunnen worden getoond( deze waarde hebben geen ascii waarde of zijn zogenaamde control tekens zoals een beep of terug naar het being van de lijn teken)

Om hier een beetje makelijk mee te kunnen werken gaan de uitvoer vertalen naar en hexadecimale notitie

.. code-block:: bash

    echo -n "School ik leuk" | ./bin2hex 
    5363686f6f6c206973206c65756b0a

Hierbij is 53 hex 83 decimaal en de ascii letter "S". Het is niet altijd nodig een programma in C te maken om zulke zaken te zien.
Zie hier bijvoorbeeld hoe dit in python zou kunnen doen.

.. literalinclude:: src/python_chr.txt
  :caption: python_chr
  :linenos:


Omgeekeer is het mogelijk deze hex waards terug te zetten naar binaire waardes

.. code-block:: bash

     echo -n 5363686f6f6c206973206c65756b0a | ./hex2bin


Uiteindelijk gaan we dus de uitvoer van School ik leuk naar hexadecimale waarde omzetten en naar een bestand sturen

.. code-block:: bash

    echo "School ik leuk" | ./caesar_cipher 12 | ./bin2hex > mijn_geheim.hex

Omgekerd is het mogelijk deze hex waardes terug te zetten naar binaire waardes met hex2bin

Probeer verschillende waardes voor de sleutel.
Hoeveel verschillende sleultes zijn er?
Probeer nu het versleudelde bericht terug te vertalen naar de originele text door de bewerking ongedaan te maken

.. code-block:: bash

    cat mijn_geheim.hex | ./hex2bin | ./caesar_cipher [getal_hier]


Opdracht probeer het volgende bericht te ontcijferen:

.. code-block:: bash

    57726969797b246d77247069796f


Uitwerkingen
''''''''''''

Hoeveel verschillende sleultes zijn er?

We kunnen in princiepe hele grote getallen gebruiken maar uiteindelijk zijn er maar 256 mogelijkheden. Er zijn 256 sleutels maar sleultel 0 doet niet zoveel.


Probeer nu het versleudelde bericht terug te vertalen naar de originele text door de bewerking ongedaan te maken?


.. code-block:: bash

    cat mijn_geheim.hex | ./hex2bin | ./caesar_cipher -12



We moeten alle 256 mogelijkheden gebruiken en gaan zelf met het oog zoeken naar de juiste oplossing.

.. literalinclude:: src/break_caesar_cipher.c
  :caption: break_caesar_cipher.c
  :linenos:

.. code-block:: bash

    echo -n 57726969797b246d77247069796f0a | ./hex2bin | ./break_caesar_cipher  | less

met een bash script kon het ook

.. code-block:: bash

    for i in `seq 0 256` 
    do 
        echo -n "$i " 
        echo -n 57726969797b246d77247069796f0a | ./hex2bin | ./caesar_cipher $i 
    done
