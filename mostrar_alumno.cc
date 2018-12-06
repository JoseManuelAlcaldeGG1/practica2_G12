#include <iostream>
#include <string>
#include <cstdlib>
#include "agenda.h"
#include "alumno.h"
#include "persona.h"

void Agenda::MostrarAlumno(Alumno a){

	cout<<"DNI: "<<a.getDNI()<<endl;
	cout<<"Email: "<<a.getEmail()<<endl;
	cout<<"Nombre: "<<a.getNombre()<<endl;
	cout<<"Apellido 1: "<<a.getApellido1()<<endl;
	cout<<"Apellido 2: "<<a.getApellido2()<<endl;
	cout<<"Telefono: "<<a.getTelefono()<<endl;
	cout<<"Dirección postal: "<<a.getDireccionPostal()<<endl;
	cout<<"Fecha de Naciemiento: "<<a.getFechaNacimiento()<<endl;
	cout<<"Equipo: "<<a.getEquipo()<<endl;
	cout<<"Lider: "<<a.getLider()<<endl;
	cout<<"Curso mas alto matriculado: "<<a.getCursoMasAlto()<<endl;

}