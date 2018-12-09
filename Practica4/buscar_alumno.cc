#include "agenda.h"
#include "alumno.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;
/*
La funcion alumno recibe dos parametros, una cadena que será un dni o unos apellidos y el otro parametro que indicará si
vamos a buscar por DNI o por apellidos.
*/

Alumno Agenda::BuscarAlumno(string cad, int opcion){
	
	Alumno fallo(-1,0,0,"0","0","0","0","0","0","0","0");



	switch(opcion){

		case 1:
		{	
			list <Alumno>::iterator it;
								
			for(it=ListaAlumnos_.begin();it!=ListaAlumnos_.end();it++){
				
				if(it->getDNI()==cad){
					return (*it);
				}
			}
							
			return fallo; //HAY QUE AJUSTAR ESTO EN LA FUNCION QUE LO USE PARA QUE IMPRIMA QUE NO SE HA ENCONTRADO EL ALUMNO
			break;
			}
		case 2:
		{
			list <Alumno>::iterator it2;
			
			for(it2=ListaAlumnos_.begin();it2!=ListaAlumnos_.end();it2++){
				
				if((it2->getApellido1()+" "+it2->getApellido2())==cad){
					return (*it2);
				}
			}
			
			return fallo;////HAY QUE AJUSTAR ESTO EN LA FUNCION QUE LO USE PARA QUE IMPRIMA QUE NO SE HA ENCONTRADO EL ALUMNO
			break;
		}

			
	}

	
}
