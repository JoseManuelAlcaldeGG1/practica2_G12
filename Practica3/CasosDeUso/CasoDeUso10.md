# Caso de uso

## Autentificar

**ID:** 10

**Breve descripcion:** Comprueba si el usuario tiene acceso al sistema.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe existir un fichero binario en el directorio con los usuarios y las contraseñas de los profesores registrados.

**Flujo principal:**
1. El caso de uso empieza cuando el usuario inicia el programa.
2. El programa pide al usuario su identificador y contraseña.
3. El programa comprueba si el usuario esta en el fichero de credenciales y si la contraseña coincide con la de su usario.
4. El sistema manda un mensaje de bienvenida al usuario.

**Postcondiciones:**
1. Se abre el menu de la base de datos.

**Flujos alternativos**
1. Si el usuario no se encuentra en el fichero de credenciales, no podrá acceder al menu y se le mandará un mensaje de error.
2. Si el usuario se encuentra en el fichero de credenciales pero la contraseña no coincide, se le mandará un mensaje de error y no podrá acceder al sistema.
