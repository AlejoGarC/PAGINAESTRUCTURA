#include "pagina.h"
#include <iostream>
#include <iomanip>
using namespace std;

int contarPestanas(pagina *p){
	int total = 0;
	if (esVacia(p->pestanas)){
		return 0;
	}
	nodo *aux = p->pestanas->cab;
	do{
		total = total + 1;
		aux = aux->sig;
	} while (aux != p->pestanas->cab);
	return total;
}

void moverse(pagina *p){
	if (esVacia(p->pestanas)){
		cout << "No hay pestanas abiertas para desplazarse..." << endl;
		return;
	}
	cout << endl << "Las pestañas abiertas son:" << endl;
	nodo *aux = p->pestanas->cab;
	int numero = 1;
	do {
		cout << numero << ") " << aux->info.nombre;
		if (aux == p->actual){
			cout << "   :esta es la actual";
		}
		cout << endl;
		aux = aux->sig;
		numero = numero + 1;
	} while (aux != p->pestanas->cab);

	int total = contarPestanas(p);
	int eleccion;
	cout << "Ingrese el numero de la pestana...si desea cancelar presione 0: ";
	cin >> eleccion;
	cin.ignore(1000, '\n');

	if (eleccion == 0){
		cout << "Cancelado." << endl;
		return;
	}
	if (eleccion < 1 || eleccion > total){
		cout << "Numero invalido." << endl;
		return;
	}

	aux = p->pestanas->cab;
	for (int i = 1; i < eleccion; i++){
		aux = aux->sig;
	}
	p->actual = aux;  
	acciones(aux);        
	mostrar(p);      
}

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
	insertar(user->info.recents, user->info.accion);   
	addNodo(p->pestanas, user);
	p->actual = user;
}
void acciones(nodo *n){
	cout << "Desea agregar (1), deshacer (2), rehacer (3) acciones o ninguna (0)?? ";
	int opcion;
	cin >> opcion;
	cin.ignore(1000, '\n');   // limpia el \n, si no el getline de recents se salta

	switch (opcion){
		case 1:{
			recents(n);
			break;
		}
		case 2:{
			controlz(n, n->info.recents);   // pila1 = historial del nodo
			break;
		}
		case 3:{
			recuperar(n);
			break;
		}
		case 0:{
			return;
		}
		default:{
			cout << "Opcion invalida." << endl;
		}
	}
}

void EliminarPestana(pagina *p){
	if (esVacia(p->pestanas)){
		return;
	}
	cout << endl << "Las pestañas abiertas son:" << endl;
	nodo *aux = p->pestanas->cab;
	int numero = 1;
	do {
		cout << numero << ") " << aux->info.nombre;
		if (aux == p->actual){
			cout << "   :esta es la actual";
		}
		cout << endl;
		aux = aux->sig;
		numero = numero + 1;
	} while (aux != p->pestanas->cab);
	int total = contarPestanas(p);
	int eleccion;
	cout << "Ingrese el numero de la pestana...si desea cancelar presione 0: ";
	cin >> eleccion;
	cin.ignore(1000, '\n');

	if (eleccion == 0){
		cout << "Cancelado." << endl;
		return;
	}
	if (eleccion < 1 || eleccion > total){
		cout << "Numero invalido." << endl;
		return;
	}

	aux = p->pestanas->cab;
	for (int i = 1; i < eleccion; i++){
		aux = aux->sig;
	}
	p->actual = aux;          
	BorrarElemento(p->pestanas, aux->info.nombre);
	if (esVacia(p->pestanas)){
		p->actual = nullptr;
	} else if (p->actual == aux){
		p->actual = p->pestanas->cab;
	}
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


void imprimirFila(nodo *n, int num){
	TDAalejo *pila = n->info.recents;
	nodoPila *h = (pila != nullptr) ? pila->tope : nullptr;

	string accion = (h != nullptr) ? h->info : "(sin accion)";

	int tam = 0;
	for (nodoPila *a = h; a != nullptr; a = a->sig) tam++;
	int lineas = (tam > 4) ? tam : 4;   // minimo 4 lineas: nombre, codigo, url, accion

	for (int i = 0; i < lineas; i++){
		cout << left << setw(15);
		if (i == 0) cout << num; else cout << "";

		string col2 = "";
		if (i == 0) col2 = n->info.nombre;
		else if (i == 1) col2 = "Codigo: " + to_string(n->info.codigo);
		else if (i == 2) col2 = "URL: " + n->info.url;
		else if (i == 3) col2 = "Accion actual: " + accion;
		cout << setw(35) << col2;

		if (h != nullptr){
			cout << h->info;
			h = h->sig;
		} else if (i == 0 && tam == 0){
			cout << "(sin acciones)";
		}
		cout << endl;
	}
}

void mostrar(pagina *p){
	if (p == nullptr || esVacia(p->pestanas)){
		cout << "No hay pestanas abiertas." << endl;
		return;
	}

		cout << endl << string(80, '-') << endl;   // <- nueva
	cout << left << setw(15) << "Nodo"
	     << setw(35) << "Pestana / Datos"
	     << "Historial de acciones" << endl;

	nodo *aux = p->pestanas->cab;
	int num = 1;
	do {
		imprimirFila(aux, num);
		cout << string(80, '-') << endl;
		aux = aux->sig;
		num++;
	} while (aux != p->pestanas->cab);

	string user;
	cout << "Nombre de la pestana a buscar: ";
	getline(cin, user);

	nodo *actual = p->pestanas->cab;
	nodo *recorrer = actual;
	nodo *encontrado = nullptr;

	do{
		if (recorrer->info.nombre == user){
			encontrado = recorrer;
		}else{
			recorrer = recorrer->sig;
		}
	}while (recorrer != actual && encontrado == nullptr);

	if (encontrado == nullptr){
		cout << "Pestana no encontrada" << endl;
		return;
	}
	imprimirDetalle(p, encontrado);
	}
 
void imprimirDetalle(pagina *p, nodo *sel){
	int total = contarPestanas(p);

	nodoPila *h = (sel->info.recents != nullptr) ? sel->info.recents->tope : nullptr;
	int tam = 0;
	for (nodoPila *a = h; a != nullptr; a = a->sig) tam++;

	int filas = total;
	if (filas < 4) filas = 4;
	if (tam > filas) filas = tam;

	string accion = (h != nullptr) ? h->info : "(sin accion)";

	cout << endl << string(90, '=') << endl;
	cout << left << setw(20) << "Nodos"
	     << setw(35) << "Datos (nodo actual)"
	     << "Historial del nodo" << endl;
	cout << string(90, '-') << endl;

	nodo *n = p->pestanas->cab;
	for (int i = 0; i < filas; i++){
		// Columna 1: nombres de los nodos
		string col1 = "";
		if (i < total){
			col1 = n->info.nombre;
			if (n == sel) col1 = "> " + col1;
			n = n->sig;
		}
		cout << setw(20) << col1;

		// Columna 2: datos solo del nodo seleccionado
		string col2 = "";
		if (i == 0) col2 = sel->info.nombre;
		else if (i == 1) col2 = "Codigo: " + to_string(sel->info.codigo);
		else if (i == 2) col2 = "URL: " + sel->info.url;
		else if (i == 3) col2 = "Accion actual: " + accion;
		cout << setw(35) << col2;

		// Columna 3: historial solo del nodo seleccionado
		if (h != nullptr){
			cout << h->info;
			h = h->sig;
		}
		cout << endl;
	}
	cout << string(90, '=') << endl;
}



