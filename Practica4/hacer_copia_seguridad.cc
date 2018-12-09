#include <iostream>
#include <fstream>
#include <cstring>
#include "profesor.h"

bool existeFichero(char* nfichero){
	bool aux;
	ifstream f1(nfichero);
	aux= f1.good();
	f1.close();
	return aux;
	
}


bool Profesor::GuardarCopia(string ncopia, Agenda &a){

	if(getCoordinador()==false) return false;

	int n;
	bool lider;
	char c[50];
	int opcion=0;
	char aux[50];

	strcpy(aux,ncopia.c_str());

	if(!existeFichero(aux)){}
	else{
		cout<<"Ya existe un fichero con ese nombre, ¿desea sobreescribirlo?\n\t1.-Si\n\t2.-No"<<endl;

		while((opcion!=1)||(opcion!=2)){
			cin>>opcion;
			switch(opcion){
							case 1:
								break;
							case 2:
								cout<<"Introduzca el nuevo nombre del fichero: "<<endl;
								getline(cin,ncopia);	
								if(existeFichero(aux)){
									cout<<"Ya existe un fichero con ese nombre, ¿desea sobreescribirlo?\n\t1.-Si\n\t2.-No"<<endl;
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
	
	for(it=a.begin(); it!=a.end(); it++){
	
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
	return true;
	


}
