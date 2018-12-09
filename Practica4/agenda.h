#ifndef AGENDA_H_
#define AGENDA_H_

#include <iostream>
#include <list>
#include "alumno.h"
using namespace std;

class Agenda{

	private:
		list <Alumno> ListaAlumnos_;

	public:
	
		Agenda(){};
		bool InsertarAlumno(Alumno a);
		void MostrarAlumno(Alumno a);
		Alumno BuscarAlumno(string cad, int opcion);
		void MostrarTodos();
		bool ModificarAlumno();
		bool BorrarAlumno();
		bool BorrarTodos();
		inline void VaciaLista(){ ListaAlumnos_.clear();}
		inline list <Alumno> getLista(){return ListaAlumnos_;}

};


#endif
