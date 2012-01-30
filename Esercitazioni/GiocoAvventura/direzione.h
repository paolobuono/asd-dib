#ifndef DIREZIONE_H
#define DIREZIONE_H

class Direzione
{
	public:
		Direzione();
		Direzione(string, string);
		string getCoordinata();
		string getOggetto();
	private:
		string coordinata;
		string oggetto;
};

Direzione::Direzione(string s, string o)
{
	coordinata = s;
	oggetto = o;
}

string Direzione::getCoordinata()
{ return coordinata; }

string Direzione::getOggetto()
{ return oggetto; }

#endif
