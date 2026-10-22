#ifndef TDAalejo_H
#define TDAalejo_H

#include<iostream>
#include <string>

using namespace std;

struct nodoPila{
	string info;
	nodoPila *sig;
};
struct TDAalejo{
	nodoPila *tope;
};
 
nodoPila *crearnodoPila(string info);
void imprimirndo(nodoPila *imp);


TDAalejo *crearPila();
bool esvacia(TDAalejo *p);
void insertar(TDAalejo *&p , string dato);
void insertarr(TDAalejo *&p);
void eliminar(TDAalejo *&p);

#endif
