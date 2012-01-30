#include "grafoListeAdiacenza.h"
#include "stanza.h"
#include "direzione.h"
#include "personaggio.h"
#include "listaPuntatoriServ.h"

void caricaGrafo(GrafoListeAd<Stanza *, Direzione *> &);
void stampaAdiacenti(ListaPunt< GNodo<Stanza *, Direzione *> *> &);

int main_gioco(int argc, char *argv[])
{
	GrafoListeAd<Stanza *, Direzione *> g;
	caricaGrafo(g);

	cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

void caricaGrafo(GrafoListeAd<Stanza *, Direzione *> &g)
{
	Stanza *cucina = new Stanza("cucina");
	Stanza *salagiochi = new Stanza("sala giochi");
	Stanza *saloneingresso = new Stanza("salone di ingresso");
	Stanza *cantina = new Stanza("cantina");
	Stanza *esterno = new Stanza("esterno");

	salagiochi->getLista()->inslista("chiavecantina", salagiochi->getLista()->primolista());
	saloneingresso->getLista()->inslista("binocolo", saloneingresso->getLista()->primolista());
	saloneingresso->getLista()->inslista("maniglia", saloneingresso->getLista()->primolista());
	cantina->getLista()->inslista("chiaveportone", cantina->getLista()->primolista());

	Direzione *cucina_salagiochi = new Direzione("ovest", "");
	Direzione *salagiochi_cucina = new Direzione("est", "maniglia");
	Direzione *cucina_saloneingresso = new Direzione("sud", "");
	Direzione *saloneingresso_cucina = new Direzione("nord", "");
	Direzione *salagiochi_cantina = new Direzione("sud", "");
	Direzione *cantina_salagiochi = new Direzione("nord", "chiavecantina");
	Direzione *saloneingresso_cantina = new Direzione("ovest", "");
	Direzione *cantina_saloneingresso = new Direzione("est", "chiavecantina");
	Direzione *saloneingresso_esterno = new Direzione("sud", "");
	Direzione *esterno_saloneingresso = new Direzione("nord", "chiaveportone");

	g.insnodo(cucina);
	g.insnodo(salagiochi);
	g.insnodo(saloneingresso);
	g.insnodo(cantina);
	g.insnodo(esterno);
	g.insarco(cucina, salagiochi, cucina_salagiochi);
	g.insarco(salagiochi, cucina, salagiochi_cucina);
	g.insarco(cucina, saloneingresso, cucina_saloneingresso);
	g.insarco(saloneingresso, cucina, saloneingresso_cucina);
	g.insarco(salagiochi, cantina, salagiochi_cantina);
	g.insarco(cantina, salagiochi, cantina_salagiochi);
	g.insarco(saloneingresso, cantina, saloneingresso_cantina);
	g.insarco(cantina, saloneingresso, cantina_saloneingresso);
	g.insarco(saloneingresso, esterno, saloneingresso_esterno);
	g.insarco(esterno, saloneingresso, esterno_saloneingresso);

	stampaAdiacenti(*g.adiacenti(cucina));
}

void stampaAdiacenti(ListaPunt< GNodo<Stanza *, Direzione *> *> &l)
{
	if( !l.listavuota() ){
		int i = 1;
		while ( !l.finelista(mappapos(l, i)) ){
			cout<< l.leggilista(mappapos(l, i))->getNodo()->getDescrizione() << " ";
			i++;
		}
		cout << endl;
	}
	else { cout<< "EMPTY!" << endl; }
}
