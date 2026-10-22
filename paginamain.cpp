#include "TDANodoCircular.h"
#include "TDAListaCircular.h"
#include "TDAalejo.h"
#include "pagina.h"
#include <iostream>
/*moverse debe moverse entre los nodos y cada que se mueva va  a mostrar el nodo al que se mueve ( como cuando
usamis cntrl fechas , mostrando la pestaña. Confirmar con la hoja de trabajo si si es asi , si 
es diferente hazlo como crees que sea mejor. confio en tu criterio.*/
int menu(){
	cout << "--------------- MENU ---------------"<<endl<<endl
		<<"Ingrese una opcion numerica: " 
			<<"\n1) Nueva pestana"<<endl
			<<"2) Visitar"<<endl
			<<"3) Moverse"<<endl
			<<"4) Salir\n";
	
	int opcion;
	cin>> opcion;
	cin.ignore();
	return opcion;
}

int main(){
	
	int opcion;
	bool salir= false;
	pagina *p = nullptr;
	while (salir!=true){
		opcion= menu();
		switch (opcion){
		case 1:{
			if (p == nullptr)
			crearPagina(p);
			else
				nuevaPestana(p);
			break;
			}
		case 2:{
			if (p == nullptr)
			cout << "Primero crea una pestana" << endl;
			else
				mostrar(p->actual);
			break;
		}
		/*
		case 3:{
			moverse(p);
			break;
		}*/
		case 4 :{
			salir = true;
			break;
		}
	}
	}
	
	return 0;
}

