# DOCUMENTO DE EXTRACCIÓN DE REQUISITOS

## PARTES INTERESADAS:
1. Profesores de la asignatura de IS.
2. Alumnos de la asignatura de IS.


## DATOS:
1. DNI (identificador)
2. Nombre
3. Apellido 1
4. Apellido 2
5. Teléfono
6. Email corporativo
7. Dirección postal
8. Curso más alto en el que está matriculado
9. Fecha de nacimiento
10. Equipo
11. Líder o no

## REQUERIMIENTOS FUNCIONALES:

1. Inserción de un alumno: en el caso de que el DNI o email corporativo de un alumno ya esté insertado, no se realizará la inserción. Puede introducir alumnos con los datos anteriores repetidos, excepto con el DNI y email corporativo. Además cuando insertemos un nuevo alumno realizaremos la comprobacion de su DNI para ver si es correcto.
2. Mostrar un alumno existente en la base de datos, con todos sus campos.
3. Mostrar el listado de los alumnos ordenado por apellidos, nombre, DNI, por curso más alto que esté matriculado, en orden ascendente o descendente. Si la base de datos esta vacia se indicara al cliente. Cómo utilizamos la funcionalidad de mostrar un alumno, el listado incluirá todos los campos.
4. Mostrar un subconjunto de alumnos por equipo, por líderes. En caso de que no exista dicho subconjunto se mandará un mensaje de error.
5. Buscar alumno por apellido 1 o ambos, DNI. También se podrán filtrar determinados campos. En caso de que no exista ese campo buscado se mandará un mensaje de error.
6. Modificar un alumno (sugerencia de JAVI comprobar el DNI), también podremos establecer si el alumno es líder o no.
7. Borrar un alumno, en caso de que el alumno borrado sea el líder de un equipo indicar una advertencia.
8. Borrar toda la base de datos.
9. Guardar
10. Cargar.

## REQUERIMIENTOS NO FUNCIONALES:

1. Al guardar y cargar los datos estos se almacenarán en un fichero binario.
2. No puede haber dos líderes para un mismo equipo.
3. No se pueden repetir DNIs.
4. No se pueden repetir los emails corporativos.
5. El teléfono tiene que tener nueve dígitos.
6. DNI deberá ser comprobado mediante un algoritmo.
7. El curso más alto de matriculación estará entre segundo y cuarto.
8. Todos los campos son obligatorios, excepto el equipo y el líder. El equipo puede tomar el valor 0, que indica que el alumno no pertenece a un equipo. El lider, por defecto, tomará el valor no.

## PRIORIDADES

1. **Prioridad 1:** Inserción
2. **Prioridad 2:** Cargar
3. **Prioridad 2:** Guardar
4. **Prioridad 2:** Buscar
5. **Prioridad 3:** Mostrar uno
6. **Prioridad 4:** Mostrar todos 
7. **Prioridad 4:** Mostrar subconjunto
8. **Prioridad 5:** Modificar
9. **Prioridad 5:** Borrar
10. **Prioridad 6:** Borrar toda la base de datos

