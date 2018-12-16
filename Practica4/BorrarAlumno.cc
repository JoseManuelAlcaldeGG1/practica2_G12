#include <iostream>
#include <string>
#include "agenda.h"
#include "alumno.h"

bool Agenda::BorrarAlumno(string dni, int &j){

	Alumno Aux=BuscarAlumno(dni,1);
	if(Aux.getDNI()=="0"){
		return false;
	}

	list <Alumno>::iterator it;

	for(it=ListaAlumnos_.begin(); it!=ListaAlumnos_.end(); it++){
		if(it->getDNI()==Aux.getDNI()){
			ListaAlumnos_.erase(it);
			return true;
		}
	}
}