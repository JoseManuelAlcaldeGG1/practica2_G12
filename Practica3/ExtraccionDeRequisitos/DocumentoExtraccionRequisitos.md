# DOCUMENTO DE EXTRACCIÓN DE REQUISITOS

## PARTES INTERESADAS:
1. Profesores de la asignatura de IS.
2. Alumnos de la asignatura de IS.


## DATOS PERSONA:
1. DNI (identificador)
2. Nombre
3. Apellido 1
4. Apellido 2
5. Teléfono
6. E-mail corporativo
7. Dirección postal
8. Fecha de nacimiento

### DATOS PROFESOR:
Hereda los datos de persona y además contiene:
1. NombreUsuario
2. Coordinador

### DATDOS ALUMNO:
Hereda los datos de persona y además contiene:
1. Curso más alto en el que está matriculado
2. Equipo
3. Líder o no líder

## REQUERIMIENTOS FUNCIONALES:
1. Insertar un alumno, en el caso de que el DNI o e-mail corporativo del alumno no esté ya en la base de datos. Se pueden introducir alumnos con el resto de datos repetidos.
2. Mostrar un alumno existente en la base de datos, con todos sus campos.
3. Mostrar el listado de los alumnos ordenado por apellidos, nombre, DNI, por curso más alto que esté matriculado y en orden ascendente o descendente. Si la base de datos está vacía se indicará al cliente. El listado mostrará todos los campos. Se podrá filtrar el listado para que solo aparezcan alumnos con características comunes. Estas características podrán ser equipo, líder o curso más alto matriculado, y serán especificadas por el usuario a la hora de mostrarlos.
4. Buscar alumno por apellido 1 o ambos, equipo o DNI.
5. Modificar los datos de un alumno.
6. Borrar un alumno, en caso de que el alumno borrado sea el líder de un equipo indicar una advertencia.
7. Borrar toda la base de datos, enviando previamente una advertencia de que no se podrán recuperar los datos.
8. Guardar la nueva información y la modificada.
9. Cargar la información ya existente.

1. Los datos estarán almacenados en un fichero binario.
2. No puede haber dos líderes para un mismo equipo.
3. No se pueden repetir DNIs.
4. No se pueden repetir los e-mails corporativos.
5. El teléfono tiene que tener nueve dígitos.
6. DNI deberá ser comprobado mediante un algoritmo.
7. El curso más alto de matriculación estará entre segundo y cuarto.
8. Todos los campos son obligatorios, excepto el equipo y el líder. El equipo puede tomar el valor cero, que indica que el alumno no pertenece a un equipo. El lider, por defecto, tomará el valor no.

## REQUERIMIENTOS NO FUNCIONALES:
1. El tipo de formato de los ficheros será binario, tanto para el de las credenciales como el de los alumnos.
2. La salida será mostrada por pantalla.
3. El número máximo de alumnos será de 150.
4. El cliente preestablece quién será el profesor coordinador, el cual estará ya registrado en la base de datos.

## PRIORIDADES
1. **Prioridad 1:** Inserción aluimno
2. **Prioridad 1:** Inserción profesor ayudante
3. **Prioridad 2:** Identificación
4. **Prioridad 2:** Cargar
5. **Prioridad 2:** Guardar
6. **Prioridad 2:** Buscar
7. **Prioridad 3:** Hacer copia seguridad
8. **Prioridad 3:** Restaurar copia seguridad
7. **Prioridad 3:** Mostrar un alumno
8. **Prioridad 4:** Mostrar todos los alumnos 
9. **Prioridad 5:** Modificar
10. **Prioridad 5:** Borrar alumno
11. **Prioridad 5:** Borrar profesor ayudante
12. **Prioridad 6:** Borrar toda la base de datos
