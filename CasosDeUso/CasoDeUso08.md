# Caso de uso

## Borrar todos los alumnos

**ID:** 08
**Breve descripcion:** El usario borra todos los alumnos que estan contenidos en la base de datos

**Actores principales:** Profesor
**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe haber al menos un alumno en la base de datos.

**Flujo principal:**
1. Se borra el archivo binario en el que estan contenidos todos los alumnos de la base de datos.

**Postcondiciones:**
1. Se muestra un mensaje al usario de que ha sido borrada la base de datos. 

**Flujos alternativos**
1. En caso de que se deseen borrar mas alumnos, estando la base de datos vacia, se mostrará un mensaje de que ya no quedan alumnos que borrar.
