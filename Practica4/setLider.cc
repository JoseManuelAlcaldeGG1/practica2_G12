#include "agenda.h"
#include "alumno.h"

bool Agenda::setLider(string frase, int j){
	list <Alumno>::iterator it;
	for(it=ListaAlumnos_.begin(); it!=ListaAlumnos_.end(); it++){
		if((it->getDNI()==frase)&&(it->getEquipo()==j)){
			it->setLider(true);
			return true;
   		}
	}
	return false;
}