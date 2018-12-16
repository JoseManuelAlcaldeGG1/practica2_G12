#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona{
	private:
		string DNI_;
		string Email_;
		string Nombre_;
		string Apellido1_;
		string Apellido2_;
		string Telefono_;
		string DireccionPostal_;
		string FechaNacimiento_;

	public:
		Persona(string DNI, string Email, string Nombre, string Apellido1, string Apellido2, string Telefono, string DireccionPostal, string FechaNacimiento):DNI_(DNI),Email_(Email),Nombre_(Nombre),Apellido1_(Apellido1),Apellido2_(Apellido2),Telefono_(Telefono),DireccionPostal_(DireccionPostal),FechaNacimiento_(FechaNacimiento){}
		inline string getDNI(){return DNI_;};
		bool setDNI(string DNI);

		inline string getEmail(){return Email_;};
		bool setEmail(string Email);

		inline string getNombre(){return Nombre_;};
		inline void setNombre(string Nombre){Nombre_=Nombre;};

		inline string getApellido1(){return Apellido1_;};
		inline void setApellido1(string Apellido1){Apellido1_=Apellido1;};

		inline string getApellido2(){return Apellido2_;};
		inline void setApellido2(string Apellido2){Apellido2_=Apellido2;};

		inline string getTelefono(){return Telefono_;};
		inline void setTelefono(string Telefono){Telefono_=Telefono;};

		inline string getDireccionPostal(){return DireccionPostal_;};
		inline void setDireccionPostal(string DireccionPostal){DireccionPostal_=DireccionPostal;};

		inline string getFechaNacimiento(){return FechaNacimiento_;};
		inline void setFechanacimiento(string FechaNacimiento){FechaNacimiento_=FechaNacimiento;};

};


#endif