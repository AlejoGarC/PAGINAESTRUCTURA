#ifndef TDANodoCircular_H
#define TDANodoCircular_H

#include<iostream>
#include <string>
#include "TDAalejo.h"

struct usuario {
	int codigo;
    string nombre;
    string url;
    string accion;
    TDAalejo *recents;   
	TDAalejo *y;
};

struct nodo {
    usuario info;
    nodo* sig;
};

usuario SolicitarInfo();
nodo* CrearNodo();
nodo* CrearNodo(usuario usr);
void ModificarInfo(nodo* nodoModificar);
void MostrarInfo(usuario usr);

#endif
