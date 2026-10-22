#include "TDAalejo.h"
#include <iostream>
using namespace std;

TDAalejo *crearPila() {
	TDAalejo *tope = new TDAalejo;
	tope -> tope = nullptr;
	return tope; 
}

bool esvacia(TDAalejo *p) {
	if (p == nullptr || p->tope == nullptr)
		return true;
	else 
		return false;
}

void insertar (TDAalejo *&p, string dato) {
	if (p == nullptr){
		p = crearPila(); 
	}
	nodoPila *aux = crearnodoPila(dato);
	aux->sig = p->tope;
	p->tope = aux;
}

void eliminar(TDAalejo *&p) {
	if (!esvacia(p)) {
		nodoPila *aux = p->tope;
		p->tope = p->tope -> sig;
		delete aux;
	}
}

nodoPila *crearnodoPila (string info){
    nodoPila* nuevo = new nodoPila;
    nuevo->info = info;
    nuevo->sig = nullptr;
    return nuevo;
}

