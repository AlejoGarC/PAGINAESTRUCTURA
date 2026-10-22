#include "pagina.h"
#include <iostream>
#include <iomanip>
using namespace std;

void crearPagina(pagina *&p){
	if (p != nullptr){
		cout << "Solo puedes tener una pagina abierta en curso. Abre una nueva pestana" << endl;
		return;
	}
	p = new pagina;
	p->pestanas = Inicilizar();
	nuevaPestana(p);
}

void nuevaPestana(pagina *p){
	nodo *user = CrearNodo();
	user->info.recents = crearPila();
	user->info.y = crearPila();
	addNodo(p->pestanas, user);
	p->actual = user;
	recents(user);
}

void recents(nodo *p){
	string dato;
	cout << "Ingrese una nueva accion" << endl;
	getline(cin, dato);
	insertar(p->info.recents, dato);
}

void controlz(nodo *p, TDAalejo *pila1){
	int opcion;
	if (esvacia(pila1)){
		cout << "No hay acciones para deshacer" << endl;
		return;
	}
	cout << "Esta seguro de que quiere deshacer?" << endl
		 << "Ingrese (1) para continuar o (0) para abortar" << endl;
	cin >> opcion;
	cin.ignore();
	if (opcion == 1){
		string dato = pila1->tope->info;
		insertar(p->info.y, dato);
		eliminar(pila1);
		if (esvacia(pila1)){
			cout << "No quedan acciones recientes" << endl;
		}else{
			cout << "Accion actual: " << pila1->tope->info << endl;
		}
	}
}

void recuperar(nodo *p){
	if (esvacia(p->info.y)){
		cout << "No hay acciones para recuperar" << endl;
		return;
	}
	string dato = p->info.y->tope->info;
	insertar(p->info.recents, dato);
	eliminar(p->info.y);
	cout << "Accion recuperada: " << dato << endl;
}

void mostrar(nodo *actual){
	nodo *aux = actual;
	usuario user;
	if (aux == nullptr){
		cout << "No hay pestanas abiertas" << endl;
		return;
	}
	cout << "Ingrese la pestana que quiere visitar";
	getline(cin,user.nombre);
	cout << "\n" << string(120, '-') << endl;
	cout << left
		 << setw(30) << "Pestana"
		 << setw(90) << "Accion actual"
		 << endl;
	cout << string(120, '-') << endl;
	nodo *recorrer = actual;
	nodo *encontrado = nullptr;

do{
	if (recorrer->info.nombre == user.nombre){
		encontrado = recorrer;
	}else{
		recorrer = recorrer->sig;
	}}while (recorrer != actual && encontrado == nullptr);

if (encontrado == nullptr){
	cout << "Pestana no encontrada" << endl;
	return;
}else{
	cout << left
		 << setw(30) << encontrado->info.nombre
		 << setw(90) << encontrado->info.recents->tope->info
		 << endl;
	cout << string(120, '-') << endl;
	
};
}



