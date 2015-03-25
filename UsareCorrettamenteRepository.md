# Regole Base #

  * Effettuare sempre prima l'UPDATE
  * Effettuare il COMMIT solo dopo aver effettuato l'UPDATE
  * Assircurarsi che il materiale caricato con il COMMIT sia valido, cioè, COMPILARE e verificare che il compilatore NON DIA ERRORE prima di aggiornare il repository.

# Buone Pratiche di Lavoro #

  * Mai lavorare due persone sugli stessi FILE, si finsce per sovrascrivere il lavoro dell'altro
  * Coordinare il Lavoro su File diversi e Documentare i cambiamenti, altri potrebbero aver bisogno di quei FILE

# Strumenti per la gestione dei file del repository #
Questo è un repository di tipo subversion, tutti gli strumenti di gestione di subversioning (svn) vanno bene. In particolare si può utilizzare Eclipse con le estensioni per il C++ e per il subversioning.
Ecco [Una utile guida](http://blog.msbbc.co.uk/2007/06/using-googles-free-svn-repository-with.html) per configurare Eclipse.

**Fare sempre attenzione** alle operazioni di **update, commit, synchronize**:

  * **Update**: repository->file locali, cioè: SCARICA dal repository i file ed eventualmente sovrascrive i file già presenti in locale
  * **Commit**:  file locali->repository, cioè: CARICA i file locali nel repository, se ci sono file uguali li aggiorna, altrimenti li aggiunge
  * **Synchronize**: eclipse vi chiede di passare alla modalità Team synchronizing, si potrà confrontare i file e decidere le operazioni da fare

Torna all'[Introduzione](HomePage.md)