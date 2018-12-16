#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <iostream>
#include "persona.h"

class Alumno: public Persona{

	private:
		int Equipo_;
		bool Lider_;
		int CursoMasAlto_;

	public:
		Alumno(int Equipo, bool Lider, int CursoMasAlto, string DNI, string Email, string Nombre, string Apellido1, string Apellido2, string Telefono, string DireccionPostal, string FechaNacimiento):Persona(DNI, Email, Nombre, Apellido1, Apellido2, Telefono, DireccionPostal, FechaNacimiento)
		{Equipo_= Equipo; Lider_=Lider; CursoMasAlto_=CursoMasAlto;};

		inline int getEquipo() {return Equipo_;};
		inline void setEquipo(int Equipo) {Equipo_=Equipo;};

		inline bool getLider(){return Lider_;};
		inline void setLider(bool Lider) {Lider_=Lider;};

		inline int getCursoMasAlto() {return CursoMasAlto_;};
		inline void setCursoMasAlto(int CursoMasAlto) {CursoMasAlto_= CursoMasAlto;};
};

#endif