Colofon
=======

Over deze cursus.



-----------------

De documentatie voor deze curses is gemaakt met sphinx en maakt gebruik van de "read the docs" templates.
de code van de website kan je hier bekijken github link en hieronder
kan je leren hoe je deze aan zou kunnen passen (en verbeteren!)

Een locale kopie can de broncode krijgen

.. code-block:: bash

	export GIT_SSL_NO_VERIFY=1
	# Het kan zijn dat je hier een username/wachtwoord voor nodig hebt
	git clone https://github/asdf

HTML versie van de bron code maken
''''''''''''''''''''''''''''''''''


.. code-block:: bash

	cd asdf
	make html

PDF versie van de bron code maken
''''''''''''''''''''''''''''''''''

.. code-block:: bash

	cd asdf
	make pdf


Notities over write access
''''''''''''''''''''''''''

Maak een ssh key op je eigen machine

.. code-block:: bash

	> ssh-keygen 

Stuur de ssh key (.ssh/id_rsa.pub) naar kees om toegang te krijgen to de server
Als het zover is kan je de volgende commandos uitvoeren om de code en historie binnen te halen.

.. code-block:: bash

	git clone git@github/stuffcode



