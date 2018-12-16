#include <iostream>
#include "persona.h"
#include "alumno.h"
#include "profesor.h"
#include "agenda.h"
#include <cstring>
#include "funciones.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <vector>

using namespace std;

int main(){

  char aux[50];
  



  login usuario;
  char frase[50];
  bool coordinador=false;
  string dni, email, nombre, apellido1, apellido2, telefono, direccion, fechanac;

  usuario.nombre_usuario="";
  usuario.contrasena="";

  Profesor p(usuario, coordinador, "0", "0", "0", "0", "0", "0", "0", "0");
  Alumno a(0,false,0,"","","","","","","","");
  Agenda ag;

  string aux2;
  int grupo, curso;
  bool lider;

  string ficheroalumnos;
  char fichaux[50];

  int op_fichero=0;

  char nfichero[50]="ficherocredenciales.bin";
  if(existeFichero(nfichero)==false){
    cout<<"¡Hola! Bienvenido a la base de datos de alumnos\nComo es la primera vez que inicia el programa debe introducir la informacion del coordinador:\n"<<endl;
    
    cout<<"Nombre de usuario: ";
    getline(cin, usuario.nombre_usuario);

    cout<<"Contraseña: ";
    getline(cin, usuario.contrasena);

    coordinador=true;

    cout<<"DNI: ";
    getline(cin, dni);
    if(!compruebaDNI(dni)){
      while(!compruebaDNI(dni)){
        cout<<"El DNI introducido es incorrecto, por favor introduzcalo de nuevo"<<endl;
        cout<<"DNI: ";
        getline(cin, dni);
      }
    }

    cout<<"Email: ";
    getline(cin, email);
    if(!compruebaEmail(email)){
      while(!compruebaEmail(email)){
        cout<<"El Email introducido es incorrecto, por favor introduzcalo de nuevo. Debe contener '@uco.es'."<<endl;
        cout<<"Email: ";
        getline(cin, email);
      }
    }
    cout<<"Nombre: ";
    getline(cin, nombre);

    cout<<"Primer apellido: ";
    getline(cin, apellido1);

    cout<<"Segundo apellido: ";
    getline(cin, apellido2);

    cout<<"Telefono: ";
    getline(cin, telefono);

    cout<<"Direccion postal: ";
    getline(cin, direccion);

    cout<<"Fecha de nacimiento: ";
    getline(cin, fechanac);

    cout<<"\n";
    





    ofstream f;
    f.open(nfichero, ios::out|ios::binary);


    strcpy(aux, dni.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, email.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, nombre.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, apellido1.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, apellido2.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, telefono.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, direccion.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, fechanac.c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, (usuario.nombre_usuario).c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, (usuario.contrasena).c_str());
    f.write((char *) &aux, 50);
    strcpy(aux, dni.c_str());
    f.write((char *) &coordinador, sizeof(bool));

    f.close();

    cout<<"¡Perfecto! "<<usuario.nombre_usuario<<" sera el coordinador, y dispondra de un mayor numero de funcionalidades.\n Ahora, es necesario reiniciar el sistema.\n"<<endl;
    return 0;

  }

    cout<<"Introduzca el usuario: ";
    getline(cin,usuario.nombre_usuario);

    cout <<"Introduzca la contraseña: ";
    leerPasw(frase);
    usuario.contrasena=frase;
  

    int valor=p.Autentificar(usuario);
    
    if(valor==-3){
        cout<<"Error al leer el fichero de credenciales"<<endl;
        return -1;
    }

    if(valor==-1){
        cout<<"Error, el usuario no se encuentra en el sistema."<<endl;
        return -1;
    }
    if(valor==0){
        cout<<"Usuario y contraseña introducidos correctamente."<<endl;
    }
    if(valor==-2){
        cout<<"La contraseña introducida para el usuario "<<usuario.nombre_usuario<<" es incorrecta."<<endl;
        return -1;
      }
  cout<<"\n";

  cout<<"Introduzca el nombre del fichero donde almacena los datos de los alumnos: ";
  getline(cin, ficheroalumnos);
  strcpy(fichaux,ficheroalumnos.c_str());

  if(!existeFichero(fichaux)){
    cout<<"No existe un fichero llamado "<<ficheroalumnos<<", ¿desea crear uno nuevo? 1.Si 2.No\n";
    
    getline(cin,aux2);
    op_fichero=atoi(aux2.c_str());

    switch(op_fichero){
      case 1:{
          ofstream f;
        f.open(fichaux, ios::out|ios::binary);
        f.close();
        cout<<"Fichero creado con exito"<<endl;
        break;
      }
    case 2:
      cout<<"Es necesario un fichero binario para trabajar, por favor indique uno existente o cree uno nuevo.\nFIN DEL PROGRAMA"<<endl;
      return -1;
      break;
    default:
      cout<<"Numero no valido, no se pudo crear el fichero. \nFIN DEL PROGRAMA"<<endl;
      return -1;
      break;  

    }

  }

  p.Cargar_Agenda(ficheroalumnos,ag);

  int opcion=0, opcion2=0;

  while(opcion!=13){

    cout<<"\n\033[1;093m(Las opciones marcadas con * solo las puede realizar el profesor coordinador)\nMENU:\n\t1.Insertar nuevo alumno\n\t2.Mostrar alumno\n\t3.Mostrar todos o subconjunto\n\t4.Modificar alumno\n\t5.Borrar alumno\n\t6.Borrar base de datos de alumnos\n\t7.Guardar base de datos\n\t8.Cargar base de datos\n\t9.Añadir nuevo profesor*\n\t10.Borrar profesor*\n\t11.Crear copia de seguridad*\n\t12.Cargar copia de seguridad*\n\t13.SALIR\n\033[0mIntroduzca su opcion: ";
   
    getline(cin,aux2);
    opcion=atoi(aux2.c_str());

    switch(opcion){

      case 1:
        cout<<"\nINSERTAR ALUMNO:\n\t";
        cout<<"DNI:";
        getline(cin, dni);

      if(!compruebaDNI(dni)){
        while(!compruebaDNI(dni)){
          cout<<"El DNI introducido es incorrecto, por favor introduzcalo de nuevo"<<endl;
          cout<<"\tDNI: ";
          getline(cin, dni);
        }
      }

        a.setDNI(dni);

        cout<<"\tEmail:";
        getline(cin,aux2);
        if(!compruebaEmail(aux2)){
            while(!compruebaEmail(aux2)){
              cout<<"El Email introducido es incorrecto, por favor introduzcalo de nuevo. Debe contener '@uco.es'."<<endl;
              cout<<"\tEmail: ";
              getline(cin, aux2);
            }
        }
        a.setEmail(aux2);

        cout<<"\tNombre:";
        getline(cin,aux2);
        a.setNombre(aux2);

        cout<<"\tPrimer apellido:";
        getline(cin,aux2);
        a.setApellido1(aux2);

        cout<<"\tSegundo apellido:";
        getline(cin,aux2);
        a.setApellido2(aux2);

        cout<<"\tTelefono:";
        getline(cin,aux2);
        a.setTelefono(aux2);

        cout<<"\tDireccion postal:";
        getline(cin,aux2);
        a.setDireccionPostal(aux2);

        cout<<"\tFecha de nacimiento:";
        getline(cin,aux2);
        a.setFechanacimiento(aux2);

        cout<<"\tIntroduzca el curso mas alto al que pertenece:";
        getline(cin,aux2);
        curso=atoi(aux2.c_str());
        if(curso>4){
          cout<<"\tEl curso no puede ser mayor de 4. Se establecerá como 4."<<endl;
          curso=4;
        }
        if(curso<2){
          cout<<"\tEl curso no puede ser menor que 2. Se establecerá como 2."<<endl;
          curso=2;
        }
        a.setCursoMasAlto(curso);
        
        cout<<"\tIntroduzca el equipo al que pertenece:";
        getline(cin,aux2);
        grupo=atoi(aux2.c_str());
        a.setEquipo(grupo);
       
        cout<<"\t¿Es el lider del equipo?\n\t\t1.Si\n\t\t2.No\t"<<endl<<"\t";
          getline(cin,aux2);
          opcion2=atoi(aux2.c_str());
          switch(opcion2){
            case 1:
              lider=true;
              break;
            case 2:
              lider=false;
              break;  
            default:
              cout<<"\tNumero erroneo, el alumno no sera lider"<<endl;
              lider=false;
              break;
          }
        
        a.setLider(lider);

        if(ag.InsertarAlumno(a))
          cout<<"Alumno insertado con exito"<<endl;
        else
          cout<<"El alumno no se pudo insertar"<<endl;

        break;


      case 2:{
      
        int op_mostrar=0;
        cout<<"MOSTRAR UN ALUMNO:\n\t1.Buscar por DNI\n\t2.Buscar por apellidos"<<endl<<"\t";
      
        while(op_mostrar==0){
          getline(cin,aux2);
          op_mostrar=atoi(aux2.c_str());
            switch(op_mostrar){
            case 1:
              cout<<"Introduzca el DNI: ";
              getline(cin,aux2);
              if(!compruebaDNI(aux2)){
                while(!compruebaDNI(aux2)){
                  cout<<"El DNI introducido es incorrecto, por favor introduzcalo de nuevo"<<endl;
                  cout<<"\tDNI: ";
                  getline(cin, aux2);
                }
              }
              a=ag.BuscarAlumno(aux2,1);
              break;
            case 2:
              cout<<"Introduzca los apellidos separados por un espacio: ";
              getline(cin,aux2);
              a=ag.BuscarAlumno(aux2,2);
              break;
            default:
              op_mostrar=0;
              cout<<"Numero introducido no valido"<<endl;
              cout<<"MOSTRAR UN ALUMNO:\n\t1.Buscar por DNI\n\t2.Buscar por apellidos"<<endl<<"\t"; 
      
            }
        }
        if(a.getDNI()=="0"){
          cout<<"El alumno buscado no se encuentra en la base de datos."<<endl;
        }
        else{
           ag.MostrarAlumno(a);
        }
        break;
      }

      case 3:{

        int op_mostrar=0;
        int j=0;
        cout<<"MOSTRAR:\n\t1.Mostrar un equipo\n\t2.Mostrar lideres\n\t3.Mostrar por curso\n\t4.Mostrar todos"<<endl<<endl;


        getline(cin,aux2);
        op_mostrar=atoi(aux2.c_str());

        if(aux2=="1"){
          cout<<"Introduzca el numero del equipo que quiere buscar: ";
          getline(cin,aux2);
          j=atoi(aux2.c_str());
        }

        if(aux2=="3"){
          cout<<"Introduzca el curso que quiere buscar: ";
          getline(cin,aux2);
          j=atoi(aux2.c_str());
        }
          
        list <Alumno> lista_aux=ag.MostrarTodos(op_mostrar,j);//el entero tengo que poner para que sea el equipo o el curso
        list <Alumno>::iterator it;

        if(lista_aux.empty()){
          cout<<"La lista no contiene ningún alumno."<<endl;
        }
        else{
           cout << setw( 143 ) << setfill( '.' ) << '\n' << setfill( ' ' );
            cout << "| "<< left << setw(35) << "Alumno" << "|"<< left << setw( 10 ) << "DNI"<< "|" << left << setw( 17 ) << "Email" 
          << "|"<< left << setw( 10 ) << "Telefono" << "|"<< left << setw( 30 ) << "Direccion" << "|"<< left << setw( 10 ) << "Fecha" << "|"<< left << setw( 7) << "Equipo" << "|"<< left << setw( 6 ) << "Lider" << "|"<< left << setw(6 ) << "Curso" << "|";

           for(it=lista_aux.begin(); it!=lista_aux.end(); it++){
              cout << "| "<< left<<setw(35)<<it->getApellido1()+" "+it->getApellido2()+" "+it->getNombre()<< "|" << left << setw( 10 ) << it->getDNI()  << "|" << left << setw( 17 ) << it->getEmail() 
              << "|"<< left << setw( 10 ) << it->getTelefono() << "|"<< left << setw( 30 ) << it->getDireccionPostal() << "|"<< left << setw( 10 ) << it->getFechaNacimiento() << "|"<< left << setw(7) << it->getEquipo() << "|"<< left << setw( 6 ) << it->getLider()<< "|"<< left << setw(6 ) << it->getCursoMasAlto()<< "|" << endl;
           }

           cout << setw( 142 ) << setfill( '.' ) << '.' << setfill( '.' )<<endl;
        }
      break;
      }


    case 4:{

      int op_buscar=0;
      int op_modificar=0;
      int op=0;
        cout<<"MODIFICAR UN ALUMNO:\n\t1.Buscar por DNI\n\t2.Buscar por apellidos"<<endl<<"\t";
      
        while(op_buscar==0){
          getline(cin,aux2);
          op_buscar=atoi(aux2.c_str());
            switch(op_buscar){

            case 1:
              cout<<"Introduzca el DNI: ";
              getline(cin,aux2);
              if(!compruebaDNI(aux2)){
                 while(!compruebaDNI(aux2)){
                     cout<<"El DNI introducido es incorrecto, por favor introduzcalo de nuevo"<<endl;
                      cout<<"DNI: ";
                     getline(cin, aux2);
                  }
              }
              a=ag.BuscarAlumno(aux2,1);
              break;

            case 2:
              cout<<"Introduzca los apellidos separados por un espacio: ";
              getline(cin,aux2);
              a=ag.BuscarAlumno(aux2,2);
              break;

            default:
              op_buscar=0;
              cout<<"Numero introducido no valido"<<endl;
              cout<<"MOSTRAR UN ALUMNO:\n\t1.Buscar por DNI\n\t2.Buscar por apellidos"<<endl<<"\t"; 
      
            }
        }

        dni=a.getDNI();
        
        while(op==0){
            cout<<"¿Que campo quiere modificar?\n\t1.DNI\n\t2.Email\n\t3.Nombre\n\t4.Apellido1\n\t5.Apellido2\n\t6.Telefono\n\t7.Direccion postal\n\t8.Fecha de nacimiento\n\t9.Equipo\n\t10.Curso mas alto\n\t11.Lider\nIntroduzca su opcion: ";
            getline(cin,aux2);
            op_modificar=atoi(aux2.c_str());

            switch(op_modificar){
        
              case 1:
                cout<<"Introduzca el nuevo DNI: ";
                getline(cin,aux2);
                if(!compruebaDNI(aux2)){
                  while(!compruebaDNI(aux2)){
                    cout<<"El DNI introducido es incorrecto, por favor introduzcalo de nuevo"<<endl;
                    cout<<"DNI: ";
                    getline(cin, aux2);
                 }
                }
                a.setDNI(aux2);
                break;
                  
              case 2:
                cout<<"Introduzca el nuevo email: ";
                getline(cin,aux2);
                if(!compruebaEmail(aux2)){
                    while(!compruebaEmail(aux2)){
                      cout<<"El Email introducido es incorrecto, por favor introduzcalo de nuevo. Debe contener '@uco.es'."<<endl;
                      cout<<"Email: ";
                      getline(cin, aux2);
                    }
                }
                a.setEmail(aux2);
                break;
                    
              case 3:
                cout<<"Introduzca el nuevo nombre: ";
                getline(cin,aux2);
                a.setNombre(aux2);
                break;
        
              case 4:
                cout<<"Introduzca el nuevo primer apellido: ";
                getline(cin,aux2);
                a.setApellido1(aux2);
                break;
        
              case 5:
                cout<<"Introduzca el nuevo segundo apellido: ";
                getline(cin,aux2);
                a.setApellido2(aux2);
                break;
        
              case 6:
                cout<<"Introduzca el nuevo telefono: ";
                getline(cin,aux2);
                a.setTelefono(aux2);
                break;
        
              case 7:
                cout<<"Introduzca la nueva direccion postal: ";
                getline(cin,aux2);
                a.setDireccionPostal(aux2);
                break;  
        
              case 8:
                cout<<"Introduzca la nueva fecha de nacimiento: ";
                getline(cin,aux2);
                a.setFechanacimiento(aux2);
                break;
        
              case 9:
                cout<<"Introduzca el nuevo equipo: ";
                getline(cin,aux2);
                grupo=atoi(aux2.c_str());
                a.setEquipo(grupo);
                break;
        
              case 10:
                cout<<"Introduzca el nuevo curso: ";
                getline(cin,aux2);
                curso=atoi(aux2.c_str());
                if(curso>4){
                    cout<<"El curso no puede ser mayor de 4. Se establecerá como 4."<<endl;
                    curso=4;
                }
                if(curso<2){
                     cout<<"El curso no puede ser menor que 2. Se establecerá como 2."<<endl;
                     curso=2;
                }
                a.setCursoMasAlto(curso);
                break;
        
              case 11:
                cout<<"Introduzca si es lider(1.Si 2.No): ";
                getline(cin,aux2);
                if(aux2=="1")
                  a.setLider(true);
                
                else{
                  if(aux2!="2"){
                    cout<<"Numero no valido, alumno no lider"<<endl;
                  }
                
                  a.setLider(false);
                }
                break;
    
            }
          while(op!=1&&op!=2){ 
              cout<<"¿Quiere Modificar otro campo?\n\t1.Si\n\t2.No\nIntroduzca su opcion:";
              getline(cin,aux2);
              op=atoi(aux2.c_str());
              if(op!=1&&op!=2){
                cout<<"Valor erroneo, introduzca de nuevo"<<endl;
              }
              if(op==1){
                op=0;
                break;
              }
              if(op==2){
                break;
              }

          }

        }
        if(!ag.ModificarAlumno(dni,a))
          cout<<"Error al modificar"<<endl;

        else cout<<"Alumno modificado con exito"<<endl;
      } 
      break;

    case 5:{

      int j;
      string dni, frase;
      vector<string> Ayudante;
      list <Alumno> Aux2;
      list <Alumno>::iterator it;

      cout<<"Introduzca el dni del alumno que desee borrar: ";
      getline(cin, dni);
      Alumno Aux=ag.BuscarAlumno(dni,1);
      j=Aux.getEquipo();

    if(Aux.getDNI()=="0"){
      cout<<"Error, el dni que ha introducido no se encuentra en el listado de Alumnos"<<endl;
    }

    else{

      if(Aux.getLider()==true){
        while((frase!="Si")&& (frase!="No")){
          cout<<"¿El alumno es lider del equipo "<<Aux.getEquipo()<<". ¿Desea borrarlo? (Si/No)"<<endl;
          getline(cin, frase);
        }

        if(frase=="No"){
          cout<<"Operacion de borrado cancelada"<<endl;
          break;
        }

        if(frase=="Si"){
            ag.BorrarAlumno(dni, j);
            cout<<"A continuación se mostrará una lista con los demás integrantes del equipo."<<endl;
            Aux2=ag.MostrarTodos(1,j);

          if(!Aux2.empty()){
              cout << setw( 143 ) << setfill( '.' ) << '\n' << setfill( ' ' );
            cout << "| "<< left << setw(35) << "Alumno" << "|"<< left << setw( 10 ) << "DNI"<< "|" << left << setw( 17 ) << "Email" 
            << "|"<< left << setw( 10 ) << "Telefono" << "|"<< left << setw( 30 ) << "Direccion" << "|"<< left << setw( 10 ) << "Fecha" << "|"<< left << setw( 7) << "Equipo" << "|"<< left << setw( 6 ) << "Lider" << "|"<< left << setw(6 ) << "Curso" << "|";

            for(it=Aux2.begin(); it!=Aux2.end(); it++){
              Ayudante.push_back(it->getDNI());
                  cout << "| "<< left<<setw(35)<<it->getApellido1()+" "+it->getApellido2()+" "+it->getNombre()<< "|" << left << setw( 10 ) << it->getDNI()  << "|" << left << setw( 17 ) << it->getEmail() 
                  << "|"<< left << setw( 10 ) << it->getTelefono() << "|"<< left << setw( 30 ) << it->getDireccionPostal() << "|"<< left << setw( 10 ) << it->getFechaNacimiento() << "|"<< left << setw(7) << it->getEquipo() << "|"<< left << setw( 6 ) << it->getLider()<< "|"<< left << setw(6 ) << it->getCursoMasAlto()<< "|" << endl;
              }

              cout << setw( 142 ) << setfill( '.' ) << '.' << setfill( '.' )<<endl;

            cout<<"De los dos o uno alumnos anteriores seleccione cual de ellos será líder introduciendo su DNI: ";
            getline(cin,frase);

            while(!compruebaDNI(frase)&&(frase!=Ayudante[0]||frase!=Ayudante[1])){
              cout<<"El dni introducido no es correcto, por favor, introduzcalo de nuevo: ";
              getline(cin,frase);
            }
  
            if(ag.setLider(frase, j)){
              cout<<"Nuevo lider del Grupo "<<j<<" establecido con exito."<<endl;
            }
          }
          else{
            cout<<"El equipo "<<j<<" ha quedado sin integrantes."<<endl;
          }
        }
        cout<<"Alumno borrado con exito"<<endl;
      }

      else{
        ag.BorrarAlumno(dni,j);
        cout<<"Alumno con DNI: "<<dni<<" borrado con exito."<<endl;
      }
    }

}
      break;

      case 6: 

        cout<<"Perderá todos los datos de "<<ficheroalumnos<<", ¿quiere continuar?\n\t1.-Si\n\t2.-No\n\t";
        getline(cin,aux2);
        if(aux2=="2"){
          cout<<"No se elimino la base de datos"<<endl;
          break;
        }
        else{
          ag.BorrarTodos(ficheroalumnos);
          cout<<"Base de datos eliminada con exito"<<endl;
          break;
        }

      case 7:

        p.Guardar_Agenda(ficheroalumnos,ag);
        cout<<"\nAgenda guardada en "<<ficheroalumnos<<endl<<endl;
        break;

      case 8:

        cout<<"Introduzca el nombre del fichero del que quiere cargar la base de datos: ";
        getline(cin,aux2);
        strcpy(fichaux,aux2.c_str());
        if(!existeFichero(fichaux)){
          cout<<"No se pudo cargar el fichero"<<endl;
          break;
        }
        ficheroalumnos=aux2;
        p.Cargar_Agenda(ficheroalumnos,ag);
        cout<<"Fichero cargado con exito"<<endl;
        break;

      case 9:{
              
          if(!p.getCoordinador()){
            cout<<"Solo el coordinador puede ejecutar esta accion"<<endl;
            break;
          }
      
          Profesor p2(usuario, coordinador, "0", "0", "Javier", "0", "0", "0", "0", "0");
          cout<<"AÑADIR PROFESOR:\n";
          cout<<"Nombre de usuario: ";
        getline(cin, usuario.nombre_usuario);
      
        cout<<"Contraseña: ";
        getline(cin, usuario.contrasena);
      
        coordinador=false;
      
        cout<<"DNI: ";
        getline(cin, dni);
        if(!compruebaDNI(dni)){
          while(!compruebaDNI(dni)){
            cout<<"El DNI introducido es incorrecto, por favor introduzcalo de nuevo"<<endl;
            cout<<"DNI: ";
            getline(cin, dni);
          }
        }
      
        cout<<"Email: ";
        getline(cin, email);
        if(!compruebaEmail(email)){
          while(!compruebaEmail(email)){
            cout<<"El Email introducido es incorrecto, por favor introduzcalo de nuevo. Debe contener '@uco.es'."<<endl;
            cout<<"Email: ";
            getline(cin, email);
          }
        }

        cout<<"Nombre: ";
        getline(cin, nombre);
      
        cout<<"Primer apellido: ";
        getline(cin, apellido1);
      
        cout<<"Segundo apellido: ";
        getline(cin, apellido2);
      
        cout<<"Telefono: ";
        getline(cin, telefono);
      
        cout<<"Direccion postal: ";
        getline(cin, direccion);
      
        cout<<"Fecha de nacimiento: ";
        getline(cin, fechanac);
  
        p2.setLogin(usuario);
        p2.setDNI(dni);
                p2.setEmail(email);
                p2.setNombre(nombre);
                p2.setApellido1(apellido1);
                p2.setApellido2(apellido2);
                p2.setTelefono(telefono);
                p2.setDireccionPostal(direccion);
                p2.setFechanacimiento(fechanac);
                p2.setCoordinador(coordinador);

 
        if(!p.AnadirProfesor(p2)){
          cout<<"No se pudo añadir el profesor"<<endl;
          break;
        }
      
        cout<<"\nProfesor "<<p2.getNombre()<<" "<<p2.getApellido1()<<" "<<p2.getApellido2()<<" añadido con exito"<<endl<<endl;
      
          break;
      }

      case 10:
        
        if(!p.getCoordinador()){
            cout<<"Solo el coordinador puede ejecutar esta accion"<<endl;
            break;
          }

        cout<<"BORRAR PROFESOR:"<<endl;
        cout<<"Introduzca el usuario del profesor que quiere borrar: ";
        getline(cin,aux2);
        if(aux2==p.getNombreUsuario()){
        	cout<<"No se puede borrar a si mismo"<<endl;
        	break;
        }
        if(p.EliminarProfesor(aux2))
          cout<<aux2<<" borrado con exito"<<endl;
        break;  
      
      case 11:{
      
              
        if(!p.getCoordinador()){
            cout<<"Solo el coordinador puede ejecutar esta accion"<<endl;
            break;
          }
          string fich;
          int puerta=0;
  
          while(puerta==0){
            puerta=1;
            cout<<"Introduzca el nombre deseado para la copia de seguridad: ";
            getline(cin,fich);
            strcpy(aux,aux2.c_str());
        p.GuardarCopia(fich,ag);
                
            
        }  
        cout<<"Copia "<<fich<<" guardada con exito"<<endl<<endl;  
 
          break;
      }

      case 12:{
      
              
        if(!p.getCoordinador()){
            cout<<"Solo el coordinador puede ejecutar esta accion"<<endl;
            break;
          }
          string fich;
          
        
        cout<<"Introduzca el nombre de la copia de seguridad que desea cargar: ";
        getline(cin,fich);
        strcpy(aux,fich.c_str());
        if(!p.RestaurarCopia(fich,ag)){
          cout<<"No existe ninguna copia de seguridad con ese nombre"<<endl;
        }
        else{
          cout<<"Trabajando con "<<fich<<endl<<endl;
        }
        break;
    
      }         
            
    
        break;

      case 13:

          cout<<"\n\t\tFIN DEL PROGRAMA\n\n"<<endl;
          break;
      default:
          cout<<"Opcion introducida no valida"<<endl;
          break;    


    } 
  }

}