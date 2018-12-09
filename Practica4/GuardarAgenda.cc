#include "alumno.h"
#include "agenda.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
#include "profesor.h"

using namespace std;

void Profesor::Guardar_Agenda(string cad, Agenda &a){
	int equipo,curso;
	bool lider;
	char c[50];
	Alumno b(0,0,0,"0","0","0","0","0","0","0","0");				
	fstream fich;
	fich.open(cad.c_str(),ios::out | ios::trunc |ios::binary);
	if(!fich.is_open())
		cout<<"Error al abrir el fichero de datos"<<endl;


	list <Alumno> Aux=a.getLista();
	list <Alumno>::iterator ad;

	for(ad=Aux.begin(); ad!=Aux.end(); ad++){


		int n=ad->getEquipo();
		fich.write((char *)(&n), sizeof(int));
		bool l=ad->getLider();
		fich.write((char *)(&l), sizeof(bool));
		n=ad->getCursoMasAlto();
		fich.write((char *)(&n), sizeof(int));
		
		strcpy(c, (ad->getDNI()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getEmail()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getNombre()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getApellido1()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getApellido2()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getTelefono()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getDireccionPostal()).c_str());
		fich.write((char *)(&c), 50);
		strcpy(c, (ad->getFechaNacimiento()).c_str());
		fich.write((char *)(&c), 50);

	}
		fich.close();
	}
