# Caso de uso

## Insertar alumno

**ID:** 01
**Breve descripcion:** El usuario introduce un nuevo alumno a la base de datos.

**Actores principales:** Profesor
**Actores secundarios:** Alumnos

**Precondiciones:**
1. El DNI introducido debe ser correcto

**Flujo principal:**
1. El caso de uso empieza cuando el usuario necesita introducir un usuario.
2. Se introducen los campos con un determinado orden:
  1. DNI
  b. Nombre
  c. Apellido
  d. Telefono
  e. Email-corporativo
  f. Direccion postal
  g. Curso más alto matriculado
  h. Equipo del que forma parte
  i. Lider/ No Líder

**Postcondiciones:**
1. Los datos se escriben en la base de datos
2. Se muestra por pantalla un mensaje informando del proceso correcto

**Flujos alternativos**
1. Si el DNI no es correcto, se muestra un mensaje de error
2. Si el DNI o los apellidos se repiten con los de otro alumno, se para el proceso y se muestra un mensaje de error
