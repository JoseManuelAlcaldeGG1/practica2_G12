# Caso de uso

## Mostrar un subconjunto de alumnos

**ID:** 05

**Breve descripcion:** El sistema muestra alumnos con determinadas características comunes

**Actores principales:** Profesor
**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe haber al menos un alumno dentro de la base de datos.
2. Solo se puede buscar por equipo, lider y curso más alto matriculado.

**Flujo principal:**
1. El caso de uso empieza cuando el usuario necesita mostrar por pantalla un conjunto de alumnos con determinadas características en común.
2. Se introducen el campo por el que se quiere buscar.

**Postcondiciones:**
1. Se muestra el conjunto de alumnos en pantalla.

**Flujos alternativos**
1. Si no hay alumnos en la base de datos se mostrar un mensaje de error.
2. Si el campo introducido no es uno de los posibles se mostrará un mensaje de error.
