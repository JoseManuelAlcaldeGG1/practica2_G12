# Caso de uso

## Modificar alumno

**ID:** 06
**Breve descripcion:** El usuario modifica los datos de un usuario existente dentro de la base de datos

**Actores principales:** Profesor
**Actores secundarios:** Alumnos

**Precondiciones:**
1. El alumno cuyos datos se quieren modificar debe existir en la base de datos

**Flujo principal:**
1. El caso de uso empieza cuando el usuario quiere cambiar los datos de un alumno
2. Se pueden cambiar los datos de cada alumno: DNI, Nombre, Apellido,Telefono, Email-corporativo, Direccion postal, Curso más alto matriculado, Equipo del que forma parte, Lider/ No Líder
3. El usuario no puede dejar campos en blanco, excepto el lider y el equipo.

**Postcondiciones:**
1. Los datos modificados se reescriben en la base de datos
2. Se muestra por pantalla un mensaje informando del proceso correcto

**Flujos alternativos**
1. Si el DNI no es correcto, se muestra un mensaje de error
2. Si el DNI o los apellidos se repiten con los de otro alumno, se para el proceso y se muestra un mensaje de error
3. Si el usuario pone como lider a un alumno que esté dentro de un grupo que ya cuente con uno, se mostrará un mensaje de error.
