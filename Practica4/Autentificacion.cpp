  #include <iostream> 
#include <cstring> 
#include <string>
#include <unistd.h>  
#include <termios.h>
#include <fstream>
#include "profesor.h"
using namespace std;

int getch(void){                              //La función getch es originaria de Windows. Esto es una 
                                              //adaptación para que funcione aqui
  struct termios oldattr, newattr;
  unsigned char ch;
  int retcode;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr=oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  retcode=read(STDIN_FILENO, &ch, 1);
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return retcode<=0? EOF: (int)ch;
}


void leerPasw(char frase[])
{
    int i=0;
    cout.flush();

    do
    {
        frase[i] = (unsigned char)getch();

        if((frase[i]!=127))             // no es retroceso. Si quereis añadirle * cuando pulsemos una tecla, decidmelo
        {
            i++;
        }
        else if(frase[i]==127)          // es retroceso
        {
          //cout<<"Retroceso"<<endl;
            frase[ i ] = '\0';          //Corto el último caracter que se tecleó
            i--;                       //Decremento hacia el caracter anterior
      
        }
        
        cout.flush();

    }while(frase[i-1]!='\n');          // si presiona ENTER

    frase[i-1] = '\0';
    cout << endl;
}

int Profesor::Autentificar(login &usuario){
  
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
  
  fichero.open("ficherocredenciales.bin", ios::in | ios::binary);
    if (fichero.fail()){
      cout<<"El fichero no se abrio correctamente"<<endl;
      return -3;
    }

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

      string n_usuario(nombre_usuario);
      string password(contrasena);

      if(usuario.nombre_usuario.compare(n_usuario)==0){

         if(usuario.contrasena.compare(password)==0){              
            fichero.close();
            return 0;
         }
        else{   
            fichero.close();                                     
            return -2;                                            
        }
      }
    }
  fichero.close();
  return -1; 
   
}
