# Caso de uso

## Mostrar todos los alumnos

**ID:** 04
**Breve descripcion:** Al usuario se le mostraran todos los alumnos introducidos en la base de datos

**Actores principales:** Profesor
**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe existir al menos un alumno en la base de datos

**Flujo principal:**
1. El caso de uso empieza cuando el usuario quiere visualizar todos los alumnos de la base de datos.
2. Se mostrarán todos los alumnos odernados alfabeticamente por apellidos o nombre, por numero de DNI, o por el curso mas alto de matriculación en orden ascendente o descendente. Se mostrarán los siguientes campos:
    1. DNI
    2. Nombre
    3. Apellido
    4. Telefono
    5. Email-corporativo
    6. Direccion postal
    7. Curso más alto matriculado
    8. Equipo del que forma parte
    9. Lider/ No Líder

**Postcondiciones:**
1. Los datos se escriben en la base de datos
2. Se muestra por pantalla un mensaje informando del proceso correcto

**Flujos alternativos**
1. Si el DNI no es correcto, se muestra un mensaje de error
2. Si el DNI o los apellidos se repiten con los de otro alumno, se para el proceso y se muestra un mensaje de error
