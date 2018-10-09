# Historia de Usuario

## Anverso

**ID:** 01 **Insertar alumno**
Como usuario, quiero poder insertar un nuevo alumno para añadirlo a la base de datos

**Prioridad:** 1 

## Reverso

1. Quiero poder introducir un nuevo alumno.
2. Todos los campos son obligatorios excepto el equipo y el lider.
3. **Si el DNI introducido no cumple el algortimo, se mostrará un mensaje de error al usuario.** 
4. No podemos introducir alumnos cuyo DNI o e-mail corporativo esté ya en el programa. Esto implica que no existen dos alumnos iguales en la base de datos.
5. No podemos insertar un alumno como lider en un equipo que ya cuente con uno
