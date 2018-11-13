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
2. El programa 

**Postcondiciones:**
1. Los datos se escriben en la base de datos.
2. Se muestra por pantalla un mensaje informando del proceso correcto.
3. Los únicos campos que se pueden quedar en blanco son equipo y lider.

**Flujos alternativos**
1. Si el DNI no es correcto, se muestra un mensaje de error, y se vuelve a pedir el DNI.
2. Si el DNI o el e-mail se repiten con los de otro alumno, se para el proceso y se muestra un mensaje de error, volviendo al menú de opciones.
3. En el caso de que ya haya 150 alumnos, se mandará un mensaje de error y se volverá al menú de opciones.
