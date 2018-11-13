# Caso de uso

## Restaurar copia de seguridad

**ID:** 14

**Breve descripcion:** Restaura una copia de seguridad realizada con anterioridad.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe existir una copia de seguridad para que podamos restaurarla.

**Flujo principal:**
1. El caso de uso empieza cuando el coordinador necesita restaurar una copia de sguridad que haya realizado sobre la agenda con anterioridad.
2. El programa pide al usuario el nombre de usuario que quiere añadir junto con la contraseña.
3. El programa comprueba si el usuario está ya en el fichero de credenciales.
4. Se introduce el numevo usuario y su contraseña en el fichero de credenciales.

**Postcondiciones:**
1. En el fichero de credenciales queda modificado con el nuevo usuario y su contraseña.

**Flujos alternativos**
1. Si el nuevo usuario ya existía en la base de datos, no se añadirá y se mandará un mensaje de error.
