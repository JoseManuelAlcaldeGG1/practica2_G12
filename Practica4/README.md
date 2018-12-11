
	login usuario;
	char frase[50];
	bool coordinador=false;
    cout<<"Introduzca el usuario: ";
    getline(cin,usuario.nombre_usuario);

    cout <<"Introduzca la contraseña: ";
    leerPasw(frase);
    usuario.contrasena=frase;
	Profesor p(usuario, coordinador, "0", "0", "Javier", "0", "0", "0", "0", "0");

	//p.Anadir_Profesor(p);
    int valor=p.Autentificar(usuario);
     if(valor==-3)
    	cout<<"Error al leer el fichero de credenciales"<<endl;

    if(valor==-1)
      cout<<"Error, el usuario no se encuentra en el sistema."<<endl;

    if(valor==0)
      cout<<"Usuario y contraseña introducidos correctamente."<<endl;

    if(valor==-2)
      cout<<"La contraseña introducida para el usuario "<<usuario.nombre_usuario<<" es incorrecta."<<endl;

    return 0;

   }
