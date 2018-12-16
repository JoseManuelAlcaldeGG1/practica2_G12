#include "funciones.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool existeFichero(char* nfichero){
	bool aux;
	ifstream f1(nfichero);
	aux= f1.good();
	f1.close();
	return aux;
	
}

bool compruebaDNI(string DNI){
	char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
  	if (DNI.size()!=9)
      return false;
 
 	if(letra[atoi(DNI.c_str())%23]==DNI[8])
 	 	return true;

 	return false;
}

bool compruebaEmail(string Email){
	int var=0;
	for(int i=0; i<Email.size(); i++){
		if(Email[i]=='@'){
			var++;
		}
	}
	if(var!=1)
		return false;

	else{
		return true;
	}
}