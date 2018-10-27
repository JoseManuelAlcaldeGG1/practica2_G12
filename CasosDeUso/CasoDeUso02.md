# Caso de uso

## Buscar Alumno

**ID:** 02
**Breve descripcion:** El usuario quiere buscar un alumno dentro de la base de datos

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Flujo principal:**
1. El caso de uso empieza cuando el usuario necesita buscar un usuario de la base de datos.
2. El alumno será buscado por DNI, apellidos o equipo al que pertenece.

**Postcondiciones:**
1. El alumno encontrado se pasará a la función correspondiente

**Flujos alternativos**
1. Si el DNI no es correcto o no se encuentra en la base de datos, se muestra un mensaje de error, indicando que el alumno no existe dentro de la base de datos o que el DNI es incorrecto, volviendo al menú de opciones.
2. Si los apellidos se repiten, entonces se pedirá el DNI del alumno.
