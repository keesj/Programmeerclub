Modulo rekenen
==============

Wat oefeningen
''''''''''''''

Als je de extra opgaven hebt gemaakt van de eerste opdracht dan zal het je zijn opgevallen dat we werken met een beperkt aantal waardes. Een byte bijvoorbeeld kan maar 256 (2*2*2*2*2*2*2*2) waardes hebben.

Wat gebeurd er als we er toch 1 bij optellen?

Schrijf het volgende programma over en compileer het met

.. code-block:: bash

    gcc -o modulo_01 modulo_01.c

.. literalinclude:: src/modulo_01.c
  :caption: modulo_01.c
  :linenos:

Voer het uit en kijk met "less" naar de output

.. code-block:: bash

    ./modulo_01 | less


.. literalinclude:: src/modulo_01_output.txt
  :lineno-match:
  :lines: 254-266

* Pas nu het programma zo aan dat je in stappen van 4 optelt en bekijk de uitvoer

.. literalinclude:: src/modulo_02.c
  :caption: modulo_02.c
  :linenos:

.. literalinclude:: src/modulo_02_output.txt
  :lineno-match:
  :lines: 63-73

Als laatste gaan we het programma nog eens aapassen maar nu gaan we 255 optellen.

.. literalinclude:: src/modulo_03.c
  :caption: modulo_03.c
  :linenos:

.. literalinclude:: src/modulo_03_output.txt
  :lineno-match:
  :lines: 0-15

Modulo rekenen
''''''''''''''

Het rekenen met deze eigenschappen is het vakgebied van het modulo rekenen en dit levert verschillende mooie eigenschappen op.

Voorlopig is het voor ons en de volgende opdracht voldoende te begrijpen dat als we een bewerking zoals optelen doen het antwoord anders kan uitvallen dan we zouden kunnen verwachten. 

Omgekeerd hebben we geleerd dat 255 ergens mij optellen hetzelfde effect heeft als 1 aftrekken.

Modulo rekenen heeft nog meer mooie eigenschappen maar hier komen we later op terug