#include <iostream>
#include <string>
#include <cstdlib>
#include "agenda.h"
#include "alumno.h"
#include "persona.h"
#include <iomanip>

void Agenda::MostrarAlumno(Alumno a){

	cout << setw( 143 ) << setfill( '.' ) << '\n' << setfill( ' ' );
    cout << "| "<< left << setw(35) << "Alumno" << "|"<< left << setw( 10 ) << "DNI"<< "|" << left << setw( 17 ) << "Email" 
    << "|"<< left << setw( 10 ) << "Telefono" << "|"<< left << setw( 30 ) << "Direccion" << "|"<< left << setw( 10 ) << "Fecha" << "|"<< left << setw( 7) << "Equipo" << "|"<< left << setw( 6 ) << "Lider" << "|"<< left << setw(6 ) << "Curso" << "|";

    cout << "| "<< left<<setw(35)<<a.getApellido1()+" "+a.getApellido2()+" "+a.getNombre()<< "|" << left << setw( 10 ) << a.getDNI()  << "|" << left << setw( 17 ) << a.getEmail() 
    << "|"<< left << setw( 10 ) << a.getTelefono() << "|"<< left << setw( 30 ) << a.getDireccionPostal() << "|"<< left << setw( 10 ) << a.getFechaNacimiento() << "|"<< left << setw(7) << a.getEquipo() << "|"<< left << setw( 6 ) << a.getLider()<< "|"<< left << setw(6 ) << a.getCursoMasAlto()<< "|" << endl;

    cout << setw( 142 ) << setfill( '.' ) << '.' << setfill( '.' )<<endl;

}