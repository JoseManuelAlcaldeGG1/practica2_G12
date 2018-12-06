#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

struct login{
	string nombre_usuario;
	string contrasena;
};

class Profesor: public Persona{
	private:
		struct login Login_;
		bool Coordinador_;
		
	public:
		Profesor(struct login Login, bool Coordinador, string DNI, string Email, string Nombre, string Apellido1, string Apellido2, string Telefono, string DireccionPostal, string FechaNacimiento)
		:Persona(DNI, Email, Nombre, Apellido1, Apellido2, Telefono, DireccionPostal, FechaNacimiento){
			Login_.nombre_usuario = Login.nombre_usuario;
			Login_.contrasena = Login.contrasena; 
			Coordinador_=Coordinador;
		}
		
		void setLogin(struct login l);
		inline string getNombreUsuario(){return Login_.nombre_usuario;};
		inline bool getCoordinador(){return Coordinador_;};

		bool GuardarCopia(string cad, Agenda &a);
		bool RestaurarCopia(string cad, Agenda &a);

		int Autentificar(login &usuario);

		bool AnadirProfesor(Profesor p);
		void mostrarProfesores();
		bool EliminarProfesor();

		void Guardar_Agenda(string cad, Agenda &a);
		void Cargar_Agenda(string cad, Agenda &a);
};
#endif
