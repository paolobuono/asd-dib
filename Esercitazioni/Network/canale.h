#ifndef CANALE_H
#define CANALE_H
#include "programma.h"
#include "listaPuntatori.h"

class Canale
{
	public:
		Canale();
		Canale(string);
        string getNome();
		ListaPunt<Programma *> * getPali();
	private:
        string nome;
		ListaPunt<Programma *> *palinsesto;
};

Canale::Canale(){}

Canale::Canale(string nome)
{
    this->nome = nome;
	palinsesto = new ListaPunt<Programma *>;
}

string Canale::getNome()
{ return nome; }

ListaPunt<Programma *> * Canale::getPali()
{ return palinsesto; }

#endif
