#ifndef STANZA_H
#define STANZA_H
#include "listaPuntatori.h"

class Stanza
{
	public:
		Stanza();
		Stanza(string);
		string getDescrizione();
		ListaPunt<string> * getLista();
	private:
		string descrizione;
		ListaPunt<string> oggetti;
};

Stanza::Stanza(string s)
{ descrizione = s; }

string Stanza::getDescrizione()
{ return descrizione; }

ListaPunt<string> * Stanza::getLista()
{ return &oggetti; }

#endif
