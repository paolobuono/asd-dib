#ifndef PERSONAGGIO_H
#define PERSONAGGIO_H

class Personaggio
{
	public:
		Personaggio();
		Personaggio(string);
		Cella<string> * getLista();
	private:
		string nome;
		ListaPunt<string> oggetti;
};

Personaggio::Personaggio(string s)
{ nome = s; }

Cella<string> * Personaggio::getLista()
{ return oggetti.primolista(); }

#endif
