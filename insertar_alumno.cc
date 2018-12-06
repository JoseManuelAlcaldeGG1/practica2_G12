#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include "agenda.h"
#include "alumno.h"
#include "persona.h"

bool compruebaDNI(string DNI){
	char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
  	if (DNI.size()!=9)
      return false;
 
 	if(letra[atoi(DNI.c_str())%23]==DNI[8])
 	 	return true;

 	return false;
}

bool compruebaEmail(string Email){
	int var=0;
	for(int i=0; i<Email.size(); i++){
		if(Email[i]=='@'){
			var++;
		}
	}
	if(var!=1)
		return false;

	else{
		return true;
	}
}



bool Agenda::InsertarAlumno(Alumno a){
list <Alumno>::iterator i;

	if(compruebaDNI(a.getDNI())==false){
		return false;
	}

	if(compruebaEmail(a.getEmail())==false){
		return false;
	}

	for ( i=ListaAlumnos_.begin(); i!=ListaAlumnos_.end(); i++){
		if( (a.getDNI()==(*i).getDNI())||(a.getEmail()==(*i).getEmail()) ){
			return false;
		}
	}

	ListaAlumnos_.push_back(a);
	return true;

}
