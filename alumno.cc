#include <iostream>
#include "alumno.h"
#include "persona.h"
using namespace std;

bool Alumno::getLider(){
	if (Lider_=true){
		return Lider_;
	}

	else{
		return false;
	}
}
