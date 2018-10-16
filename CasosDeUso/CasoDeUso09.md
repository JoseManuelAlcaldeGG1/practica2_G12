# Caso de uso

## Guardar y cargar la base de datos

**ID:** 04

**Breve descripcion:** Al iniciar el programa, se carga la base de datos. Al acabar una operacion, se guardan los datos en el fichero binario

**Actores principales:** Profesor
**Actores secundarios:** Alumnos

**Precondiciones**
1. Existe un fichero binario sobre el que crearemos la base de datos, en el caso de que no exista

**Flujo principal:**
1. El caso de uso empieza cuando el usuario accede al programa.
2. Se cargará el fichero para su uso por el usuario


**Postcondiciones:**
1. Una vez realizada cada operación, se volcarán los cambios en el fichero. 

**Flujos alternativos**
1. En caso de que no se pueda abrir o no exista el fichero, se mostrará un mensaje de error.
