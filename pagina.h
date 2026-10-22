#ifndef PAGINA_H
#define PAGINA_H
#include<iostream>
#include"TDANodoCircular.h"
#include"TDAListaCircular.h"
#include "TDAalejo.h"

struct pagina{
	TDAListaCircular *pestanas;
	nodo *actual;
};

void crearPagina(pagina *&p);
void nuevaPestana(pagina *p);
void recents (nodo *p);
void controlz (nodo *p, TDAalejo *pila1);
void mostrar(nodo *n);
#endif
