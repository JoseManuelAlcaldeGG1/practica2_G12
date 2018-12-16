#include "alumno.h"
#include "agenda.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include "profesor.h"
using namespace std;


void Profesor::Cargar_Agenda(string cad, Agenda &a){
	int equipo,curso;
	bool lider;
	char c[50];
	Alumno b(0,0,0,"0","0","0","0","0","0","0","0");
	fstream fich;
	fich.open(cad.c_str(),ios::in| ios::out |ios::binary);

	if(!fich.is_open())
		cout<<"Error al abrir el fichero de datos"<<endl;

	a.VaciaLista();

     while(!fich.eof()){
  	 fich.read((char *)(&equipo), sizeof(int));
  		 if(fich.eof()){break;}
		b.setEquipo(equipo);
		fich.read((char *)(&lider), sizeof(bool));
		b.setLider(lider);
		fich.read((char *)(&curso), sizeof(int));
		b.setCursoMasAlto(curso);
		fich.read((char *)(&c), 50);
		string dni(c);
		b.setDNI(dni);
		fich.read((char *)(&c), 50);
		string email(c);
		b.setEmail(email);
		fich.read((char *)(&c), 50);
		string nombre(c);
		b.setNombre(nombre);
		fich.read((char *)(&c), 50);
		string apellido1(c);
		b.setApellido1(apellido1);
		fich.read((char *)(&c), 50);
		string apellido2(c);
		b.setApellido2(apellido2);
		fich.read((char *)(&c), 50);
		string telefono(c);
		b.setTelefono(telefono);
		fich.read((char *)(&c), 50);
		string direccion(c);
		b.setDireccionPostal(direccion);
		fich.read((char *)(&c), 50);
		string fechanacimiento(c);
		b.setFechanacimiento(fechanacimiento);
		
		a.InsertarAlumno(b);

	}
   fich.close();

}
