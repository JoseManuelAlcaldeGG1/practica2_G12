#include <iostream>
#include <cstdlib>
#include <list>
#include "agenda.h"
#include "alumno.h"
#include "persona.h"
#include "funciones.h"



bool Agenda::ModificarAlumno(string dni, Alumno a){
	list <Alumno>::iterator i;
	list <Alumno>::iterator j;
	list <Alumno>::iterator k;
	list <Alumno> aux;
	list <Alumno> auxiliar;

	string Email;
	int equipo=0;
	bool lider=false;

	if(compruebaDNI(a.getDNI())==false ){
		return false;
	}

	if(compruebaEmail(a.getEmail())==false ){
		return false;
	}

	for(i = ListaAlumnos_.begin(); i != ListaAlumnos_.end(); i++){

		if(dni==(*i).getDNI()){
			Email = (*i).getEmail();
			equipo = (*i).getEquipo();

				if (equipo!= a.getEquipo()){
					equipo=a.getEquipo();

						if ( (*i).getLider()==true ){
							cout<<"No se pudo modificar el alumno porque era lider de su equipo original"<<endl;
							return false;
						}

						for(j = ListaAlumnos_.begin(); j != ListaAlumnos_.end(); j++){
							if(equipo==(*j).getEquipo()){
								aux.push_back(*j);
							}
						}

						if(aux.size()==3){
							cout<<"No se pudo modificar el alumno porque el nuevo equipo ya cuenta con 3 integrantes"<<endl;
							return false;
						}

						else{
							for(k= aux.begin(); k!= aux.end(); k++){
								if( ((*k).getLider()==true)&&(a.getLider()==true) ){
									(*k).setLider(lider);
								}
							}
						}

				}

		}
	}

	for(i = ListaAlumnos_.begin(); i != ListaAlumnos_.end(); i++){
		if(equipo==(*i).getEquipo()){
			auxiliar.push_back(*i);
		}
	}

	for(i= auxiliar.begin(); i!= auxiliar.end(); i++){
		if( ((*i).getLider()==true)&&(a.getLider()==true) ){
			(*i).setLider(lider);
		}
	}


	if (dni!=a.getDNI()){

		for(i = ListaAlumnos_.begin(); i != ListaAlumnos_.end(); i++){

			if( a.getDNI()==(*i).getDNI() ){
				cout<<"El DNI esta repetido"<<endl;
				return false;
			}
		}

	}

	if( Email!=a.getEmail() ){
		for(i = ListaAlumnos_.begin(); i != ListaAlumnos_.end(); i++){

			if( a.getEmail()==(*i).getEmail() ){
				cout<<"El Email esta repetido"<<endl;
				return false;
			}
		}
	}


	for(i = ListaAlumnos_.begin(); i != ListaAlumnos_.end(); i++){
		if(dni==(*i).getDNI()){
			ListaAlumnos_.erase(i);
			ListaAlumnos_.push_back(a);
			return true;
			
		}
	}


}