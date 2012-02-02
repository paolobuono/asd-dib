#ifndef PROGRAMMA_H
#define PROGRAMMA_H

class Programma
{
	public:
		Programma();
		Programma(int, string, string);
		int getCodice();
        string getTitolo();
        string getDescrizione();
	private:
        int codice;
		string titolo;
        string descrizione;
};

Programma::Programma(int codice, string titolo, string descrizione)
{
    this->codice = codice;
    this->titolo = titolo;
    this->descrizione = descrizione;
}

int Programma::getCodice()
{ return codice; }

string Programma::getTitolo()
{ return titolo; }

string Programma::getDescrizione()
{ return descrizione; }

#endif
