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
		list <Alumno> MostrarTodos(int opcion, int j);
		bool ModificarAlumno(string dni, Alumno a);
		bool BorrarAlumno(string dni, int &j);
		bool BorrarTodos(string cad);
		bool setLider(string frase, int j);
		inline void VaciaLista(){ ListaAlumnos_.clear();}
		inline list <Alumno> getLista(){return ListaAlumnos_;}

};


#endif