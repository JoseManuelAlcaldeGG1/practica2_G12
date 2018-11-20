# Caso de uso

## Buscar Alumno

**ID:** 02

**Breve descripcion:** El usuario buscará un alumno dentro de la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Flujo principal:**
1. El caso de uso empieza cuando el usuario necesita buscar un alumno de la base de datos.
2. El programa pedirá al usuario el tipo de campo clave por el que se realizará la búsqueda, que puede ser DNI o apellidos.
3. El usuario indica el campo.
4. El usuario introduce el dni o los apellidos.
5. Se retornará el alumno.

**Postcondiciones:**
1. El alumno encontrado se pasará a la función correspondiente.

**Flujos alternativos**
1. Si el parámetro usado para buscar no existe en la base de datos se le indicará, y se le rediccionará al menú.
2. Si los apellidos se repiten, entonces se pedirá el DNI del alumno.
