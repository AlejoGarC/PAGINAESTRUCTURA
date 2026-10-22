#ifndef TDALISTACIRCULAR_H
#define TDALISTACIRCULAR_H
#include <iostream>
using namespace std;
#include "TDANodoCircular.h"

struct TDAListaCircular{
	nodo *cab;   
	nodo *cola;  
};

TDAListaCircular *Inicilizar();

bool esVacia(TDAListaCircular *c);
TDAListaCircular *crearLista(TDAListaCircular *c, usuario usu);
void consultarEstado(TDAListaCircular *listaCircularEstado);
nodo *buscarElemento(TDAListaCircular *l, usuario info);
void recorrerLista(nodo *nodoFinal, TDAListaCircular *listaCircular);
void BorrarElemento(TDAListaCircular *&listC, string nombreUsuario);
void addNodo(TDAListaCircular *&listC, nodo *n);
void ImprimirLista(TDAListaCircular *c);

#endif
