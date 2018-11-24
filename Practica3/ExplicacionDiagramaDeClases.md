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
En esta clase, la cual hereda de la clase persona y se asocia con la clase agenda, definimos una serie de atributos propios de los profesores que accederán a la base de datos.
Dichos atributos serán:
1. Login
2. Coordinador
3. Puntero Agenda

En esta clase al igual que en las demás, se empleará una función get y otra set para obtener el nombre de usuario del profesor que acceda a la base de datos, una función de autetificación para ingresar el login al inciar el programa; dos funciones tan solo realizables por el profesor coordinador, las cuales serán realizar una copia de seguridad de la base de datos y la de restaurarla, y por último, una función de guardar y a cargar en la agenda de alumnos las cuales podrán ser realizadas por cualquier profesor.

### Agenda
En esta clase definimos unicamente un solo atributo que será nuestra lista de alumnos, el cual será el fichero binario en el cual almacenaremos todos los alumnos que tengamos en nuestra base de datos.
En dicha clase implementamos una serie de funciones las cuales serán la de introducir y borrar un alumno de nuestro fichero, buscar un alumno, modificarlo, mostrar uno o mostrarlos todos y borrar todo el fichero binario.
Además definimos una agregación entre esta clase y la clase alumno, ya que la clase agenda forma parte de la clase alumno.
