#ifndef PAGINA_H
#define PAGINA_H
#include <iostream>
#include "TDANodoCircular.h"
#include "TDAListaCircular.h"
#include "TDAalejo.h"

struct pagina{
	TDAListaCircular *pestanas;
	nodo *actual;
};

int contarPestanas(pagina *p);
void moverse(pagina *p);
void crearPagina(pagina *&p);
void nuevaPestana(pagina *p);
void acciones(nodo *n);
void EliminarPestana(pagina *p);
void recents(nodo *p);
void controlz(nodo *p, TDAalejo *pila1);
void recuperar(nodo *p);
void imprimirFila(nodo *n, int num);
void mostrar(pagina *p);
void imprimirDetalle(pagina *p, nodo *sel);

#endif
