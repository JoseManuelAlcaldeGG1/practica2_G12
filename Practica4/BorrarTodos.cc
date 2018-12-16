#include <iostream>
#include <list>
#include <fstream>
#include "agenda.h"
#include "funciones.h"


bool Agenda::BorrarTodos(string cad){
	fstream fichero;
	char cadena[50];

	if(ListaAlumnos_.size()==0){
		return false;
	}

	else {
		VaciaLista();
	}

	strcpy( cadena, cad.c_str() );

	if(!existeFichero(cadena)){
		return false;
	}

	fichero.open(cad.c_str(),ios::out | ios::trunc |ios::binary);

	if(fichero.fail()){
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}

	fichero.close();
	return true;

}