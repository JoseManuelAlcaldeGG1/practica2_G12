#include "profesor.h"
#include "alumno.h"
#include "agenda.h"
#include <list>
#include <fstream>
#include <iomanip>
#include <cstdlib>

/*
En el main se preguntara lo siguiente:
	1.- Desea mostar un subconjunto?
		En caso afirmativo:
			1.1 Por que campo desea buscar: 1 Equipo 2 Lider 3 Curso
			1.1.1 Si selecciona Equipo, se llama a la funcion MostrarTodos(1)
			1.1.2 Si selecciona Lider, se llama a la funcion MostrarTodos(2)
			1.1.3 Si selecciona Curso se llama a la funcion MostrarTodos(3)

		En caso negativo se muestran todos los alumnos, MostrarTodos(4). La funcion crea el Markdown, devuelve la lista de alumnos y se imprime en
		el main.

		OJITO. DIAGRAMA DE CLASES Y DIAGRAMA DE SECUENCIAS, lo que devuelve la funcion
 */

bool comparaDNIDesc(Alumno &i, Alumno &j){
	return i.getDNI()<j.getDNI();
}
bool comparaDNIAsc(Alumno &i, Alumno &j){
	return i.getDNI()>j.getDNI();
}
bool comparaApellidosDesc(Alumno &i, Alumno &j){
	return (i.getApellido1()+" "+i.getApellido2()+" "+i.getNombre())<(j.getApellido1()+" "+j.getApellido2()+" "+j.getNombre());
}
bool comparaApellidosAsc(Alumno &i, Alumno &j){
	return (i.getApellido1()+" "+i.getApellido2()+" "+i.getNombre())>(j.getApellido1()+" "+j.getApellido2()+" "+j.getNombre());
}
bool comparaCursoDesc(Alumno &i, Alumno &j){
	return i.getCursoMasAlto()<j.getCursoMasAlto();
}
bool comparaCursoAsc(Alumno &i, Alumno &j){
	return i.getCursoMasAlto()>j.getCursoMasAlto();
}


list <Alumno> Agenda::MostrarTodos(int opcion, int j){
	int n, t;
	string frase;
	list <Alumno> Aux;
	list <Alumno>::iterator it;

	switch (opcion){
		case 1:
			
			for(it=ListaAlumnos_.begin(); it!=ListaAlumnos_.end(); it++){
				if(it->getEquipo()==j){
					Aux.push_back(*it);
				}
			}
			break;			

		case 2:

			for(it=ListaAlumnos_.begin(); it!=ListaAlumnos_.end(); it++){
				if(it->getLider()==true){
					Aux.push_back(*it);
				}
			}	
			break;

		case 3:

			
			for(it=ListaAlumnos_.begin(); it!=ListaAlumnos_.end(); it++){
				if(it->getCursoMasAlto()==j){
					Aux.push_back(*it);
				}
			}
			break;

		case 4:
				ofstream fich("MostrarTodos.md", ios::trunc);

				fich<<"#Fichero para la Consulta Mostrar Todos"<<endl<<endl;
			
			Aux=ListaAlumnos_;
			
			
			cout<<"¿Mediante qué campo quiere ordenar la lista? ";
			cout<<"Nombre y Apellidos(1) DNI(2) Curso(3)"<<endl;
			getline(cin,frase);
			n=atoi(frase.c_str());
			cout<<"¿Descendentemente (1) o Ascendentemente (2)? \n";
			getline(cin,frase);
			t=atoi(frase.c_str());
			switch(n){
				case 1:
					if(t==1)
						Aux.sort(comparaApellidosAsc);
					else{
						Aux.sort(comparaApellidosDesc);
					}
					break;
				case 2:
					if(t==1)
						Aux.sort(comparaDNIAsc);
					else{
						Aux.sort(comparaDNIDesc);
					}
					break;
				case 3:
					if(t==1)
						Aux.sort(comparaCursoAsc);
					else{
						Aux.sort(comparaCursoDesc);
					}
					break;
			}



			for(it=Aux.begin(); it!=Aux.end(); it++){

					fich<<"**"<<"Nombre del alumno: "<<it->getApellido1()<<" "<<it->getApellido2()<<", "<<it->getNombre()<<"**"<<endl;
					fich<<"\tDNI: "<<it->getDNI()<<endl;
					fich<<"\tEmail: "<<it->getEmail()<<endl;
					fich<<"\tTelefono:"<<it->getTelefono()<<endl;
					fich<<"\tDireccion: "<<it->getDireccionPostal()<<endl;
					fich<<"\tFecha nacimiento: "<<it->getFechaNacimiento()<<endl;
					fich<<"\tEquipo al que pertenece: "<<it->getEquipo()<<endl;
					
					if(it->getLider())
						fich<<"\tLider: Si"<<endl;
					else
						fich<<"\tLider: No"<<endl;

					fich<<"\tCurso mas alto: "<<it->getCursoMasAlto()<<endl<<endl;
		
			}
			cout<<"\nGenerado fichero Markdown con el nombre MostrarTodos.md"<<endl;
			return Aux;
			break;
}
			cout<<"¿Mediante qué campo quiere ordenar la lista? ";
			cout<<"Nombre y Apellidos(1) DNI(2) Curso(3)"<<endl;
			getline(cin,frase);
			n=atoi(frase.c_str());
			cout<<"¿Descendentemente (1) o Ascendentemente (2)?\n\t ";
			getline(cin,frase);
			t=atoi(frase.c_str());

			switch(n){
				case 1:

					if(t==1)
						Aux.sort(comparaApellidosAsc);
					else{
						Aux.sort(comparaApellidosDesc);
					}
					break;
				case 2:

					if(t==1)
						Aux.sort(comparaDNIAsc);
					else{
						Aux.sort(comparaDNIDesc);
					}
					break;
				case 3:

					if(t==1)
						Aux.sort(comparaCursoAsc);
					else{
						Aux.sort(comparaCursoDesc);
					}
					break;
			}

			return Aux;
}
