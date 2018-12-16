
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "profesor.h"
#include "persona.h"

using namespace std;


bool Profesor::EliminarProfesor(string cadena){

	fstream fichero;
	fstream ficheroAux;
	int cont=0;
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

	fichero.open("ficherocredenciales.bin", ios::in | ios::binary);
		if (fichero.fail()){
			cout<<"El fichero no se abrio correctamente"<<endl;
			return false;
		}

	ficheroAux.open("ficheroAux.bin", ios::out | ios::binary);
		if (ficheroAux.fail()){
			cout<<"El fichero auxiliar no se abrio correctamente"<<endl;
			return false;
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

			string usuario(nombre_usuario);

			if(cadena==usuario){
				cont=1;
			}

			if(cadena!=usuario){

				strcpy(nombre_usuario, usuario.c_str() );

				ficheroAux.write((char *) &DNI, 50);
				ficheroAux.write((char *) &Email, 50);
				ficheroAux.write((char *) &Nombre, 50);
				ficheroAux.write((char *) &Apellido1, 50);
				ficheroAux.write((char *) &Apellido2, 50);
				ficheroAux.write((char *) &Telefono, 50);
				ficheroAux.write((char *) &DireccionPostal, 50);
				ficheroAux.write((char *) &FechaNacimiento, 50);
				ficheroAux.write((char *) &nombre_usuario, 50);
				ficheroAux.write((char *) &contrasena, 50);
				ficheroAux.write((char *) &coordinador, sizeof(bool));
			}

		}

		if(cont==0){
			cout<<"\nEl usuario introducido no esta registrado"<<endl;
			ficheroAux.close();
			fichero.close();
			remove("ficheroAux.bin");
			return false;
		}


	ficheroAux.close();
	fichero.close();

	remove("ficherocredenciales.bin");
	rename("ficheroAux.bin","ficherocredenciales.bin");

	return true;

}