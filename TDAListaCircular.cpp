#include "TDANodoCircular.h"
#include "TDAListaCircular.h"
#include <iostream>

using namespace std; 

TDAListaCircular *Inicilizar(){
	TDAListaCircular *c;
	c = new TDAListaCircular;
	c->cola=NULL;
	c->cab = NULL;
	return c;
}

bool esVacia(TDAListaCircular *c){
	if (c->cola==NULL)
		return true;
	else
		return false;
}

TDAListaCircular *crearLista(TDAListaCircular *c, usuario usu){
    nodo *aux;
	aux = CrearNodo(usu) ;
	if (c->cab==NULL){
		c->cab = c->cola = aux;
	}
	else {
		c->cola->sig = aux;
		c->cola=aux;
    }
    aux ->sig = c->cab;
	return c;
}

void consultarEstado(TDAListaCircular *listaCircularEstado)
{
	nodo *recorrer, *recorrer1;
 	recorrer=listaCircularEstado->cab;
	recorrer1=listaCircularEstado->cola;
	if (recorrer == NULL && recorrer1 == NULL)
	{
		cout<<"La lista circular se encuentra vacia."<<endl;
	}
	else{
		if (recorrer == NULL || recorrer1 == NULL) {
			cout<<"No es una lista circular."<<endl;
		}
		else{
			cout<<"La lista circular tiene elementos."<<endl;
		}
	}
}

nodo *buscarElemento(TDAListaCircular *l, usuario info) {

	nodo *recorrer;
	nodo *encontrado = NULL;
	nodo *principio;
	principio = l->cab;
	recorrer = l->cab;

	do{
		if(recorrer->info.nombre == info.nombre) {
			encontrado = recorrer;
		}
		else{
			recorrer = recorrer->sig;
		}
	}while (recorrer != principio && encontrado == NULL);
	return encontrado;
}

void recorrerLista(nodo *nodoFinal, TDAListaCircular *listaCircular)
{
	nodo *recorrer;
	recorrer = listaCircular->cab;
	while(recorrer != nodoFinal)
	{
		MostrarInfo(recorrer->info);
		recorrer = recorrer->sig;
	}
}

void BorrarElemento(TDAListaCircular*&listC, string nombreUsuario) {
    if (esVacia(listC)) {
        cout << "La lista esta vacia, no hay elementos para borrar." << endl;
        return;
    }
    nodo* actual = listC->cab;
    nodo* anterior = listC->cola;
    do {
        if (actual->info.nombre == nombreUsuario){   
            if (actual == listC->cab && actual == listC->cola) { // Solo un elemento
                listC->cab = listC->cola = nullptr;
            } else {
                if (actual == listC->cab) {
                    listC->cab = actual->sig;
                }
                if (actual == listC->cola) {
                    listC->cola = anterior;
                }
                anterior->sig = actual->sig;
            }
            delete actual;
            cout << "Usuario " << nombreUsuario << " eliminado." << endl;
            return;
        }
        anterior = actual;
        actual = actual->sig;
    } while (actual != listC->cab);
    cout << "Usuario " << nombreUsuario << " no encontrado." << endl;
}

void addNodo(TDAListaCircular *&listC, nodo *n) {
	if (listC->cola==NULL && listC->cab ==NULL){
		listC->cab=n;
		listC->cola=n;
		n->sig=n;
	}
	else
	{
		listC->cola->sig=n;
		listC->cola=n;
		listC->cola->sig=listC->cab;
	}
}

void ImprimirLista(TDAListaCircular *c){
	if (c->cab==NULL){
		cout<<"\n"<<"La lista no esta creada";
	}
	else {
	    nodo *aux;
		aux=c->cab;
		do{
			MostrarInfo(aux->info);
			aux=aux->sig;
		}while (aux!=c->cab);
	}
    cout<<"\n";
}
