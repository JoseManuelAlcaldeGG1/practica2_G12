# Caso de uso

## Cargar la base de datos

**ID:** 09

**Breve descripcion:** Al iniciar el programa, se carga la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones**
1. Existe un fichero binario sobre el que cargaremos la base de datos, en el caso de que no exista, se creará un fichero para dicha base de datos.

**Flujo principal:**
1. El caso de uso empieza cuando el usuario accede al programa.
2. Se cargará el fichero para su uso por el usuario. 

**Flujos alternativos**
1. En caso de que no se pueda abrir el fichero, se mostrará un mensaje de error, y se terminará el programa.
2. En caso de que el fichero binario no exista, se crea uno.
