# Diagrama de clases

## Clases que hemos definido:
1. Persona
2. Alumno
3. Profesor
4. Agenda

### Persona
En esta clase persona hemos definido una serie de atributos que sirven para hacer referencia a unas características generales tanto de los profesores como de los alumnos.
Dichos atributos son:
1. DNI
2. Email
3. Nombre
4. Apellido1
5. Apellido2
6. Teléfono
7. Direccion Postal
8. Fecha de Nacimiento

Para ello en dicha calse hemos definido una serie de funciones (get y set) para obetener y modificar cada uno de los atributos relacionados tanto con los alumnos como con los profesores.

### Alumno
En esta clase definimos una serie de atributos más específicos de cada alumno.
Dichos atributos son:
1. Equipo
2. Líder
3. Curso más alto

Para definir estos atributos, en esta clase hemos implementado una serie de funciones (get y set) con las cuales los obtenemos y modificamos, dependiendo del alumno que queramos obtener o que queramos introducir en nuestra base de datos.
Además, hemos definido que esta clase tiene herencia de la clase persona, ya que nos harán falta las funciones de dicha clase para visualizar el resto de atributos del alumno.

### Profesor
En esta clase, la cual herada de la clase persona y se asocia con la clase agenda, definimos una serie de atributos de los profesores que accederan a la base de datos.
Dichos atributos serán:
1. Login
2. Coordinador
3. Puntero Agenda

En esta clase al igual que en las demás, se empleará una función get y otra set para obtener y modificar el nombre de usuario del profesor que acceda a la base de datos; Una función de autetificación para ingresar el login al inciar el programa; Dos funciones tan solo realizables por el profesor coordinador, que serán la de hacer una copia de seguridad de la base de datos y la de restaurarla; Por último, una funcíon de guardar y a cargar en la agenda de alumnos las cuales podrán ser realizadas por cualquier profesor.

### Agenda
