/* prova di laboratorio di ASD
   studente: Manca Antonio Luca
*/

#include "templateServ.h"

int main(int argc, char *argv[])
{
	ListaVett<Canale> Rete;

	// caricaPalinsesto(), che carica il palinsesto della rete
	caricaPalinsesto(Rete);

	// elencoCanali(), che restituisce l'elenco di canali messi a disposizione dalla rete televisiva
	elencoCanali(Rete);

	// elencoProgrammi(canale), che restituisce l'elenco dei programmi disponibili nel canale specificato
	elencoProgrammi(Rete, "Rai Due");

	// ottieniProgramma(codiceProgramma), che restituisce il programma per stamparne titolo e descrizione
	Programma* puntAprog = ottieniProgramma(Rete, 2010);
	if( puntAprog != NULL ){
		cout << "Programma con codice " << puntAprog->getCodice() << ":" <<endl;
		cout<< puntAprog->getTitolo() << " -> ";
		cout<< puntAprog->getDescrizione() << endl;
	} else {
		cout << "Programma con codice xxx non trovato!" <<endl;
	}
	cout << endl;

	// registraProgramma(codiceProgramma), che memorizza il programma passato al metodo ad una lista contenente i programmi in registrazione
	ListaPunt<Programma *> Registrazioni;
	registraProgramma(Rete, 1010, Registrazioni);
	registraProgramma(Rete, 1020, Registrazioni);
	registraProgramma(Rete, 2020, Registrazioni);

	// ottieniRegistrazioni(), che restituisce l'elenco di film in registrazione
	ottieniRegistrazioni(Registrazioni);

	cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
