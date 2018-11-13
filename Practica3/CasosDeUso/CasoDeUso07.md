# Caso de uso

## Borrar todos los alumnos

**ID:** 07

**Breve descripcion:** El usuario borra todos los alumnos de la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe haber al menos un alumno en la base de datos.

**Flujo principal:**
1. El programa muestra una advertencia de que no se podrán recuperar los datos.
2. El usuario confirma o no la acción.
3. Se borra el contenido del fichero binario en el que están contenidos los alumnos de la base de datos.

**Postcondiciones:**
1. Se muestra un mensaje al usario de que ha sido borrada la base de datos. 

**Flujos alternativos**
1. En caso de que no haya alumnos en la base de datos, se mostrará un mensaje de error, y se volverá al menú de opciones.
