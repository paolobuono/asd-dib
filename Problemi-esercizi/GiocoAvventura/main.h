/*
 * main.h
 *      Autore: Domenico Monaco - domenico.monaco@kiuz.it
 *      Descrizione: Gioco di avventura da traccia Appello di Laboratorio
 *      Data prova laboratorio: 12 / 01 / 2012
 *
 */

#ifndef MAINGIOCOAVVENTUTRA_domenico_monaco_H_
#define MAINGIOCOAVVENTUTRA_domenico_monaco_H_

#include <string>
#include <iostream>
using namespace std;
typedef bool boolean;

#include "../../Grafo/arcoGrafoListaArchi.h"
#include "../../Grafo/grafoListaArchi.h"

#include "../../Lista/lista.h"
#include "../../Lista/nodolista.h"
#include "../../Lista/listaBidirezionale.h"

#include "oggetto.h"
#include "campodigioco.h"
#include "personaggio.h"

void caricaGrafo(CampoDiGioco*);
void aggiungiOggetto(Personaggio *Giocatore, Oggetto Object);

void init_gioco_avventura_domenico_monaco();

void init_gioco_avventura_domenico_monaco() {
	cout << "Inizio Gioco Avventura 1" << endl;

	cout << "... inizializzo lo scenario." << endl;
	CampoDiGioco Scenario;
	Scenario.creaGrafo();

	cout << "... inizializzo il personaggio." << endl;
	Personaggio Giocatore("Domenico");

	cout << "... Carico i dati dello scenario" << endl;
	caricaGrafo(&Scenario);

}

void caricaGrafo(CampoDiGioco* Campo) {

	data_Nodo cucina, salagiochi, salone, cantina, fuori;

	data_Arco cucina_salagichi_ovest, cucina_salone_sud, salagiochi_cantina_sud,
			salone_cantina_ovest, salone_fuori_sud;

	data_Arco cucina_salagichi_est, cucina_salone_nord, salagiochi_cantina_nord,
			salone_cantina_est, salone_fuori_nord;

	Oggetto chiavecantina, binocolo, maniglia, chiaveportone;

	//DICHIARAZIONI
	cucina.setDescription(
			"Sei nella Cucina. Ad Ovest vedi una porta senza maniglia.");
	salagiochi.setDescription(
			"Sei nella sala giochi a sud c' una porta chiusa a chiave.");
	salone.setDescription("Sei nel salone di ingresso.");
	cantina.setDescription("Sei nella Cantina");
	fuori.setDescription("Sei fuori dall'edificio complimenti.");

	//OGGETTI
	chiavecantina.setName("Chiavecantina");
	binocolo.setName("Binocolo");
	maniglia.setName("Maniaglia");
	chiaveportone.setName("Chiaveportone");

	//cucina.addObject()
	salagiochi.addObject(chiavecantina);
	salone.addObject(binocolo);
	salone.addObject(maniglia);
	cantina.addObject(chiaveportone);

	//Archi e direzioni

	cucina_salagichi_ovest.setDirection("ovest");
	cucina_salone_sud.setDirection("sud");

	salagiochi_cantina_sud.setDirection("sud");
	salagiochi_cantina_sud.setObject(chiavecantina);

	salone_cantina_ovest.setDirection("ovest");

	salone_fuori_sud.setDirection("sud");
	salone_fuori_sud.setObject(chiaveportone);

	cucina_salagichi_est.setDirection("est");
	cucina_salagichi_est.setObject(maniglia);

	cucina_salone_nord.setDirection("nord");
	salagiochi_cantina_nord.setDirection("nord");

	salone_cantina_est.setDirection("est");
	salone_cantina_est.setObject(chiavecantina);

	salone_fuori_nord.setDirection("nord");

	cellaGrafo<data_Nodo>* nodo1;
	cellaGrafo<data_Nodo>* nodo2;
	cellaGrafo<data_Nodo>* nodo3;
	cellaGrafo<data_Nodo>* nodo4;
	cellaGrafo<data_Nodo>* nodo5;

	nodo1 = new cellaGrafo<data_Nodo>;
	nodo2 = new cellaGrafo<data_Nodo>;
	nodo3 = new cellaGrafo<data_Nodo>;
	nodo4 = new cellaGrafo<data_Nodo>;
	nodo5 = new cellaGrafo<data_Nodo>;

	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco1;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco2;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco3;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco4;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco5;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco6;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco7;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco8;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco9;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* arco10;

	arco1 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco2 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco3 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco4 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco5 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco6 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco7 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco8 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco9 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;
	arco10 = new arcoGrafoListaArchi<data_Arco, data_Nodo>;

	Campo->insNodo(nodo1, cucina);
	Campo->insNodo(nodo2, salagiochi);
	Campo->insNodo(nodo3, salone);
	Campo->insNodo(nodo4, cantina);
	Campo->insNodo(nodo5, fuori);

	//cucina_salagichi_ovest.setDirection("ovest");
	//cucina_salagichi_est.setDirection("est");
	Campo->insArco(nodo1, nodo2, arco1, cucina_salagichi_est);
	Campo->insArco(nodo2, nodo1, arco2, cucina_salagichi_ovest);

	//cucina_salone_nord.setDirection("nord");
	//cucina_salone_sud.setDirection("sud");
	Campo->insArco(nodo1, nodo3, arco3, cucina_salone_sud);
	Campo->insArco(nodo3, nodo1, arco4, cucina_salone_nord);

	//salagiochi_cantina_sud.setDirection("sud");
	//salagiochi_cantina_nord.setDirection("nord");
	Campo->insArco(nodo2, nodo4, arco5, salagiochi_cantina_sud);
	Campo->insArco(nodo4, nodo2, arco6, salagiochi_cantina_nord);

	//salone_cantina_ovest.setDirection("ovest");
	//salone_cantina_est.setDirection("est");
	Campo->insArco(nodo4, nodo3, arco7, salone_cantina_ovest);
	Campo->insArco(nodo3, nodo4, arco8, salone_cantina_est);

	//salone_fuori_sud.setDirection("sud");
	//salone_fuori_nord.setDirection("nord");
	Campo->insArco(nodo3, nodo5, arco9, salone_fuori_sud);
	Campo->insArco(nodo5, nodo3, arco10, salone_fuori_nord);

}

void aggiungiOggetto(Personaggio* Giocatore, Oggetto Object) {
	Giocatore->addObject(Object);
}

cellaGrafo<data_Nodo>* spostamento(cellaGrafo<data_Nodo>* Nodo,
		string direzione, Personaggio* Giocatore, CampoDiGioco Scenario) {

	cellaGrafo<data_Nodo>* NodoOut;
	NodoLista<cellaGrafo<data_Nodo>*>* pos_nodo_Adi;

	ListaBidirezionale<cellaGrafo<data_Nodo>*,
			NodoLista<cellaGrafo<data_Nodo>*>*> ListaAdiacenti;

	ListaBidirezionale<arcoGrafoListaArchi<data_Arco, data_Nodo>*
			, NodoLista<arcoGrafoListaArchi<data_Arco, data_Nodo>*>*> ListaDirezioni;
	NodoLista<arcoGrafoListaArchi<data_Arco, data_Nodo>*>* pos_nodo_Dir;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* nodo_Dir;

	pos_nodo_Adi = ListaAdiacenti.primoLista();

	boolean check = false;

	boolean check_obj = false;

	//adiacenti di NODO
	ListaAdiacenti = Scenario.adiacenti(Nodo);

	pos_nodo_Dir = Scenario.ListaArchi.primoLista();

	//Cerco l'arco con la direzione selezionata
	while (pos_nodo_Dir != NULL && check != true) {
		nodo_Dir = Scenario.ListaArchi.leggiLista(pos_nodo_Dir);
		if (nodo_Dir->leggiNodoPartenza() == Nodo
				&& nodo_Dir->getInfo().getDirection() == direzione) {
			check = true;
		} else {
			pos_nodo_Dir = Scenario.ListaArchi.succLista(pos_nodo_Dir);
		}
	}

	//se esce o pos_nodo_Dir NULL oppure ha trovato qualcosa

	if (pos_nodo_Dir != NULL && check == true) {

		//OK, AERCO della DIREZIONE selezionata TROVATO
		//ListaBidirezionale<Oggetto, NodoLista<Oggetto>*> Objects_list;

		NodoLista<Oggetto>* pos_nodo_ogg;

		pos_nodo_ogg = Giocatore->Objects.primoLista();

		while (pos_nodo_ogg != NULL && check_obj != true) {
			if (Giocatore->Objects.leggiLista(pos_nodo_ogg).getName()
					== Scenario.ListaArchi.leggiLista(pos_nodo_Dir)->getInfo().object.getName()) {
				check_obj = true;
			} else {
				pos_nodo_ogg = Giocatore->Objects.succLista(pos_nodo_ogg);
			}
		}

		//Controllo se ho trovato l'oggetto nella lista degli oggetti del giocatore
		if (pos_nodo_ogg != NULL && check_obj == true) {
			NodoOut =
					Scenario.ListaArchi.leggiLista(pos_nodo_Dir)->leggiNodoArrivo();

			if (!NodoOut->getInfo().Objects.listaVuota()) {
				pos_nodo_ogg = NodoOut->getInfo().Objects.primoLista();

				while (pos_nodo_ogg != NULL) {
					Giocatore->addObject(
							NodoOut->getInfo().Objects.leggiLista(pos_nodo_ogg));
					pos_nodo_ogg = NodoOut->getInfo().Objects.succLista(
							pos_nodo_ogg);
				}
			}

		} else {
			NodoOut = Nodo;
		}
	} else {
		NodoOut = Nodo;
	}
	return NodoOut;
}

ListaBidirezionale<string, NodoLista<string>*> direzioniDisponibili(
		cellaGrafo<data_Nodo>* Nodo, CampoDiGioco Scenario) {

	ListaBidirezionale<string, NodoLista<string>*> direzioni;
	NodoLista<string>* pos_dir;

	direzioni.creaLista();


	NodoLista<arcoGrafoListaArchi<data_Arco, data_Nodo>*>* pos_nodo_Dir;
	arcoGrafoListaArchi<data_Arco, data_Nodo>* nodo_Dir;

	pos_nodo_Dir = Scenario.ListaArchi.primoLista();

	//Cerco l'arco con la direzione selezionata
	while (pos_nodo_Dir != NULL) {
		nodo_Dir = Scenario.ListaArchi.leggiLista(pos_nodo_Dir);
		if (nodo_Dir->leggiNodoPartenza() == Nodo) {

			pos_dir = direzioni.primoLista();
			direzioni.insLista(nodo_Dir->getInfo().getDirection(), pos_dir);

		} else {
			pos_nodo_Dir = Scenario.ListaArchi.succLista(pos_nodo_Dir);
		}
	}

	return direzioni;
}

#endif /* MAINGIOCOAVVENTUTRA_domenico_monaco_H_ */
