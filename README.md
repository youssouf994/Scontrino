ESERCIZIO UTILE A COMPRENDERE MEGLIO ANCHE LA DINAMICA DELLE ASSOCIAZIONI IN QUESTO CASO UNO A MOLTI, RIFERITO ALL'ASSOCIAZIONE TRA UN CLIENTE E MOLTI SCONTRINI.

--DOCUMENTAZIONE SCRITTA UTILIZZANDO CHAT GPT--
Ecco una documentazione superficiale del codice, che spiega i componenti principali e il loro funzionamento a livello generale.

## Documentazione del Codice

### **1. Main Program (`main.cpp`)**
Questo è il file principale del programma, che gestisce un sistema di gestione di clienti, articoli e scontrini. Attraverso un menù a scelta numerica, l'utente può eseguire diverse operazioni come selezionare un cliente, visualizzare i suoi scontrini, registrare nuovi scontrini e aggiungere nuovi clienti.

- **Variabili principali:**
  - `num`: utilizzato per aggiornare e gestire il numero di scontrino.
  - `scelta`: usato per gestire la selezione del menù.
  - `nome`, `prezzo`, `quanti`: informazioni sugli articoli che vengono aggiunti a uno scontrino.

- **Funzioni principali:**
  - `gc.selezionaCliente()`: permette di selezionare il cliente su cui si vuole operare.
  - `gc.checkIdClienti()`: controlla e restituisce gli scontrini associati a un cliente.
  - `gc.aggiungiCliente()`: aggiunge un nuovo cliente al sistema.

### **2. Classe `Scontrino` (`scontrino.cpp`)**
La classe `Scontrino` rappresenta un singolo scontrino. Contiene informazioni come il nome dell'azienda, partita IVA, articoli venduti, il totale e il numero dello scontrino.

- **Attributi:**
  - `nomeAzienda`, `pIva`: dettagli fissi per identificare l'azienda.
  - `num`: numero dello scontrino.
  - `prezzo`: totale del prezzo di tutti gli articoli nello scontrino.
  - `artic`: un vettore di articoli acquistati nello scontrino.
  - `idCliente`: ID del cliente associato allo scontrino.

- **Funzioni principali:**
  - `setArticoli(Articoli a)`: aggiunge un articolo alla lista di articoli.
  - `setTotale()`: calcola il totale degli articoli.
  - `getScontrino()`: stampa lo scontrino su console.
  - `salvaScontrinoSuFile()`: salva lo scontrino in un file.
  - `leggiNumScontrino()`: legge il numero dello scontrino corrente da un file.
  - `aggiornaNumScontrino()`: aggiorna il numero dello scontrino in un file.

### **3. Classe `GestisciClienti` (`gestisciCliente.cpp`)**
La classe `GestisciClienti` gestisce la selezione e l'aggiunta di clienti nel sistema. Ogni cliente ha un ID univoco generato automaticamente.

- **Attributi:**
  - `idCliente`: l'ID del cliente attualmente selezionato.
  
- **Funzioni principali:**
  - `generaIdCliente()`: genera un ID cliente casuale e verifica che non esista già.
  - `checkIdClienti()`: controlla gli scontrini associati a un cliente.
  - `aggiungiCliente()`: permette di aggiungere un nuovo cliente.
  - `selezionaCliente()`: permette di selezionare un cliente esistente.
  - `visualizzaClienti()`: mostra tutti i clienti nel database.

### **4. Classe `Cliente` (`clienti.cpp`)**
La classe `Cliente` rappresenta un cliente con un ID univoco, un nome e un cognome.

- **Attributi:**
  - `idCliente`: ID univoco del cliente.
  - `nome`: nome del cliente.
  - `cognome`: cognome del cliente.

- **Funzioni principali:**
  - `getNome()`: restituisce il nome del cliente.
  - `getCognome()`: restituisce il cognome del cliente.
  - `getId()`: restituisce l'ID del cliente.

### **5. Classe `Articoli` (`articoli.cpp`)**
La classe `Articoli` rappresenta un singolo articolo venduto in uno scontrino, con informazioni su nome, prezzo e quantità.

- **Attributi:**
  - `nome`: nome dell'articolo.
  - `prezzo`: prezzo dell'articolo.
  - `quanti`: quantità venduta dell'articolo.

- **Funzioni principali:**
  - `getPrezzo()`: restituisce il prezzo dell'articolo.
  - `getQuanti()`: restituisce la quantità venduta dell'articolo.
  - `toString()`: converte l'articolo in una stringa formattata per la stampa.

### **Funzionamento Generale**
Il programma permette di gestire clienti e scontrini. Si possono registrare nuovi clienti e scontrini, visualizzare i clienti e i loro scontrini, e gestire la vendita di articoli. Gli articoli vengono associati a uno scontrino, che viene salvato su file. Lo stesso accade per i clienti, che vengono salvati con il loro ID, nome e cognome in un file separato.

### **Miglioramenti Possibili**
- **Gestione degli errori**: Aggiungere controlli di errori più robusti quando si accede ai file o si convertono le stringhe.
- **Miglioramento della User Experience**: Potrebbero essere utili più messaggi di conferma o di errore durante le operazioni con i clienti e gli scontrini.
- **Modularità**: Alcune funzioni, come la generazione di ID o la gestione degli articoli, potrebbero essere ulteriormente modularizzate o migliorate.

### **Conclusione**
Il codice implementa un semplice sistema di gestione vendite e clienti, ma è ben organizzato. La struttura delle classi è chiara, e le operazioni principali sono facili da comprendere.
