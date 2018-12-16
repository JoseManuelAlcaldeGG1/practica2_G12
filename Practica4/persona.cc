#include "persona.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "funciones.h"

bool Persona::setDNI(string DNI){
	if(!compruebaDNI(DNI))
		return false;

	else{
		DNI_=DNI;
		return true;
	}
}


bool Persona::setEmail(string Email){
	if(!compruebaEmail(Email))
		return false;

	else{
		Email_=Email;
		return true;
	}
}