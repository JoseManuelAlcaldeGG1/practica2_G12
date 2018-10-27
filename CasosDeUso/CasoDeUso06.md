# Caso de uso

## Borrar el alumno

**ID:** 06

**Breve descripcion:** El usuario borra el alumno que desee de la base de datos.


**Actores principales:** Profesor

**Actores secundarios:** Alumnos


**Precondiciones:**
1. El alumno que el usario desee borrar debe de existir.

**Flujo principal:**
1. El alumno que se quiera borrar se buscará dentro de la base de datos.
2. Se eliminará el alumno del programa.

**Flujos alternativos**
1. En caso de que el alumno no exista dentro de la base de datos, se le mostarará al usuario un mensaje de error. Se repetirá el proceso.
