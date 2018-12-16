#include <iostream>
#include <fstream>
#include <cstring>
#include "profesor.h"
#include "funciones.h"
#include <cstdlib>
#include <unistd.h>

bool Profesor::GuardarCopia(string ncopia, Agenda &a){



	char* directorio=(char*)malloc(100);
	getcwd(directorio,100);
	string dir=directorio;
	free(directorio);

	string dircopias=dir+"/Copias_Seguridad";
	char auxdir[100];

	strcpy(auxdir,dircopias.c_str());
	chdir(auxdir);

	int n;
	bool lider;
	char c[50];
	int opcion=0;
	char aux[50];
	string cad;

	strcpy(aux,ncopia.c_str());

	if(!existeFichero(aux)){}
	else{
		cout<<"Ya existe un fichero con ese nombre, ¿desea sobreescribirlo?\n\t1.-Si\n\t2.-No"<<endl;

		while((opcion!=1)&&(opcion!=2)){
			getline(cin,cad);
			opcion=atoi(cad.c_str());
			switch(opcion){
							case 1:
								
								break;
							case 2:
								cout<<"Introduzca el nuevo nombre del fichero: "<<endl;
								getline(cin,ncopia);
								strcpy(aux,ncopia.c_str());	
								if(existeFichero(aux)){
									cout<<"Ya existe un fichero con ese nombre, ¿desea sobreescribirlo?\n\t1.-Si\n\t2.-No"<<endl;
									getline(cin,cad);
									if(cad=="2")
										opcion=0;
								}
								break;
							default:
								cout<<"Numero incorrecto"<<endl;
								break;	
			}
		}
	}

	
	
	ofstream f;
	f.open(ncopia.c_str(), ios::out| ios::binary);
		
	
	list <Alumno>::iterator it;
	list <Alumno> Aux;

	Aux=a.getLista();
	
	for(it=Aux.begin(); it!=Aux.end(); it++){
	
		n=it->getEquipo();
		f.write(reinterpret_cast<char*>(&n), sizeof(int));
		lider=it->getLider();
		f.write(reinterpret_cast<char*>(&lider),sizeof(bool));
		n=it->getCursoMasAlto();
		f.write(reinterpret_cast<char*>(&n),sizeof(int));
	
		strcpy(c, (it->getDNI()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
		strcpy(c, (it->getEmail()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
		strcpy(c, (it->getNombre()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
		strcpy(c, (it->getApellido1()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
		strcpy(c, (it->getApellido2()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);	
		strcpy(c, (it->getTelefono()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
		strcpy(c, (it->getDireccionPostal()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
		strcpy(c, (it->getFechaNacimiento()).c_str());
		f.write(reinterpret_cast<char*>(&c),50);
	}
	
	f.close();
	strcpy(auxdir,dir.c_str());
	chdir(auxdir);
	return true;
	


}