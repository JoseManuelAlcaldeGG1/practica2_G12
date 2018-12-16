#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include "agenda.h"
#include "alumno.h"
#include "persona.h"
#include "funciones.h"

bool Agenda::InsertarAlumno(Alumno a){
list <Alumno>::iterator i;
list <Alumno> aux;
string frase;
bool lider=false;
int cont=0;

	if(compruebaDNI(a.getDNI())==false){
		return false;
	}

	if(compruebaEmail(a.getEmail())==false){
		return false;
	}

	for ( i=ListaAlumnos_.begin(); i!=ListaAlumnos_.end(); i++){
		if( a.getDNI()==(*i).getDNI() ){
			cout<<"DNI repetido"<<endl;
			return false;
		}

		if(a.getEmail()==(*i).getEmail()){
			cout<<"Email repetido"<<endl;
			return false;
		}

		if (a.getEquipo()==(*i).getEquipo()){
			aux.push_back(*i);
		}
	}

	if(aux.size()==3){
		cout<<"El equipo en el que queremos introducir el alumno ya tiene 3 integrantes"<<endl;
		return false;
	}

	for (i=aux.begin(); i!=aux.end(); i++){
		if( ((*i).getLider()==true)&&(a.getLider()==true) ){
			cout<<"El equipo ya posee un lider, ¿quiere insertarlo como no lider?\n\t1.-Si\n\t2.-No"<<endl<<"\t";
			getline(cin,frase);

				if(frase=="1"){
					a.setLider(lider);
				}

				else{
					cout<<"El alumno no se ha insertado"<<endl;
					return false;
				}
		}
	}

	ListaAlumnos_.push_back(a);
	return true;

}


/*

tengo que comprobar que no haya mas de 3 alumnos en un equio y que en ese equipo no haya
mas de un lider

list <Alumno> Agenda::MostrarTodos(int opcion){
	int n;
	string aux;
	list <Alumno> Aux;
	list <Alumno>::iterator it;

	switch (opcion){
		case 1:

			cout<<"Introduzca el equipo que desee imprimir los datos: ";
			getline(cin,aux);
			n=atoi(aux.c_str());

			for(it=ListaAlumnos_.begin(); it!=ListaAlumnos_.end(); it++){
				if(it->getEquipo()==n){
					Aux.push_back(*it);
				}
			}
			return Aux;
			break;	

*/
