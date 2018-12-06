# Caso de uso

## Restaurar copia de seguridad

**ID:** 14

**Breve descripcion:** Restaura una copia de seguridad realizada con anterioridad.

**Actores principales:** Profesor coordinador

**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe existir una copia de seguridad para que podamos restaurarla.

**Flujo principal:**
1. El caso de uso empieza cuando el coordinador necesita restaurar una copia de seguridad que haya realizado sobre la agenda de alumnos con anterioridad.
2. Se pide el nombre del fichero por el que restauraremos la base de datos.
3. Se restaura la copia seleccionada.

**Postcondiciones:**
1. La agenda de alumnos queda restaurada según una copia de seguridad previa.

**Flujos alternativos**
1. En caso de no exitir una copia de seguridad previa se mostrará un mensaje de error al coordinador.
2. Si el nombre no coincide con ningun archivo, se muestra un mensaje de error y se vuelve al menu.
