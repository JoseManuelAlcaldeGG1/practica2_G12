#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "profesor.h"
#include "persona.h"
using namespace std;


void Profesor::setLogin(struct login l){
	Login_.nombre_usuario=l.nombre_usuario;
	Login_.contrasena = l.contrasena;
}


bool Profesor::AnadirProfesor(Profesor p){

	fstream fichero;
	char DNI[50];
	char Email[50];
	char Nombre[50];
	char Apellido1[50];
	char Apellido2[50];
	char Telefono[50];
	char DireccionPostal[50];
	char FechaNacimiento[50];
	char nombre_usuario[50];
	char contrasena[50];
	bool coordinador;

	if( (p.compruebaDNI(p.getDNI())==false)||(p.compruebaEmail(p.getEmail())==false) ){
		return false;
	}


	fichero.open("ficherocredenciales.bin", ios::app | ios::binary);
		if (fichero.fail()){
			cout<<"El fichero no se abrio correctamente"<<endl;
			exit(-1);
		}
	fichero.close();

	fichero.open("ficherocredenciales.bin", ios::in | ios::binary);
		if (fichero.fail()){
			cout<<"El fichero no se abrio correctamente"<<endl;
			exit(-1);
		}
	
		fichero.seekg(ios::beg);

		while( !fichero.eof() ){

			fichero.read((char *) &DNI, 50);
			fichero.read((char *) &Email, 50);
			fichero.read((char *) &Nombre, 50);
			fichero.read((char *) &Apellido1, 50);
			fichero.read((char *) &Apellido2, 50);
			fichero.read((char *) &Telefono, 50);
			fichero.read((char *) &DireccionPostal, 50);
			fichero.read((char *) &FechaNacimiento, 50);
			fichero.read((char *) &nombre_usuario, 50);
			fichero.read((char *) &contrasena, 50);
			fichero.read((char *) &coordinador, sizeof(bool));

			string dni(DNI);
			string email(Email);
			string nombre(Nombre);
			string apellido1(Apellido1);
			string apellido2(Apellido2);
			string telefono(Telefono);
			string direccion(DireccionPostal);
			string nacimiento(FechaNacimiento);
			string usuario(nombre_usuario);
			string contra_sena(contrasena);


			if( (usuario==p.getNombreUsuario()) ){
				cout<<"Nombre de usuario repetido"<<endl;
				return false;
			}
		}


	fichero.close();

	fichero.open("ficherocredenciales.bin", ios::app | ios::binary);
		if (fichero.fail()){
			cout<<"El fichero no se abrio correctamente"<<endl;
			exit(-1);
		}

	strcpy( DNI, (p.getDNI()).c_str() );
	strcpy( Email, (p.getEmail()).c_str() );
	strcpy( Nombre, (p.getNombre()).c_str() );
	strcpy( Apellido1, (p.getApellido1()).c_str() );
	strcpy( Apellido2, (p.getApellido2()).c_str() );
	strcpy( Telefono, (p.getTelefono()).c_str() );
	strcpy( DireccionPostal, (p.getDireccionPostal()).c_str() );
	strcpy( FechaNacimiento, (p.getFechaNacimiento()).c_str() );
	strcpy( nombre_usuario, (p.getNombreUsuario()).c_str() );
	strcpy( contrasena, (p.Login_.contrasena).c_str() );
	coordinador=p.getCoordinador();

		fichero.seekg(ios::end);

			fichero.write((char *) &DNI, 50);
			fichero.write((char *) &Email, 50);
			fichero.write((char *) &Nombre, 50);
			fichero.write((char *) &Apellido1, 50);
			fichero.write((char *) &Apellido2, 50);
			fichero.write((char *) &Telefono, 50);
			fichero.write((char *) &DireccionPostal, 50);
			fichero.write((char *) &FechaNacimiento, 50);
			fichero.write((char *) &nombre_usuario, 50);
			fichero.write((char *) &contrasena, 50);
			fichero.write((char *) &coordinador, sizeof(bool));

	fichero.close();

	return true;
}