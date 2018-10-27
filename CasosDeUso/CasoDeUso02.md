# Caso de uso

## Buscar Alumno

**ID:** 02

**Breve descripcion:** El usuario buscará un alumno dentro de la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Flujo principal:**
1. El caso de uso empieza cuando el usuario necesita buscar un alumno de la base de datos.
2. El alumno será buscado por DNI, apellidos o equipo al que pertenece.

**Postcondiciones:**
1. El alumno encontrado se pasará a la función correspondiente.

**Flujos alternativos**
1. Si el DNI no es correcto se muestra un mensaje de error, y vuelve a pedir el DNI.
2. Si el parámetro usado para buscar no existe en la base de datos se volverá a pedir.
3. Si los apellidos se repiten, entonces se pedirá el DNI del alumno.
