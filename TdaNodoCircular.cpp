#include <iostream>
#include "TDAListaCircular.h"
#include "TDANodoCircular.h"
using namespace std;

usuario SolicitarInfo() {
    usuario temp;
    cout << "Nombre: ";
    getline(cin, temp.nombre);
    cout << "URL: ";
    getline(cin, temp.url);
    cout << "Accion: : ";
    getline(cin, temp.accion);
    return temp;
}

nodo* CrearNodo() {
    nodo* nuevo = new nodo;
    nuevo->info = SolicitarInfo();
    nuevo->sig = nullptr;
    return nuevo;
}

nodo* CrearNodo(usuario usr) {
    nodo* nuevo = new nodo;
    nuevo->info = usr;
    nuevo->sig = nullptr;
    return nuevo;
}

void ModificarInfo(nodo* nodoModificar) {
    cout << "Ingrese nuevo nombre: ";
    getline(cin, nodoModificar->info.nombre);
    cout << "Ingrese nuevo url: ";
    getline(cin, nodoModificar->info.url);
}

void MostrarInfo(usuario usr) {
    cout << "Codigo: " << usr.codigo << endl;
	cout << "Nombre: " << usr.nombre << endl;
    cout << "url: " << usr.url << endl;
    cout << "Nombre de usuario: " << usr.accion << endl;
}

