# Caso de uso

## Mostrar todos los alumnos

**ID:** 04

**Breve descripcion:** Al usuario se le mostrarán todos los alumnos introducidos en la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe haber al menos un alumno dentro de la base de datos.

**Flujo principal:**
1. El caso de uso empieza cuando el usuario quiere visualizar todos los alumnos de la base de datos.
2. El programa pregunta al usuario si quiere realizar algún subconjunto (equipo, líder, curso más alto matriculado) o mostrarlos todos.
3. Se mostrarán todos los alumnos odernados alfabeticamente por apellidos o nombre, por número de DNI, o por el curso más alto de matriculación en orden ascendente o descendente. Se mostrarán los siguientes campos:
    1. DNI
    2. Nombre
    3. Apellido
    4. Teléfono
    5. Email-corporativo
    6. Direccion postal
    7. Curso más alto matriculado
    8. Equipo del que forma parte
    9. Líder/ No Líder

**Postcondiciones:**
1. Mostrar todos los alumnos por pantalla.

**Flujos alternativos**
1. En caso de que no exista ningún alumno en la base de datos, se mostrará un mensaje de error al usuario y se volverá al menú.
