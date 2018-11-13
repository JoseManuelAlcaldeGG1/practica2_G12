# Caso de uso

## Borrar profesor

**ID:** 12

**Breve descripcion:** Elimina un profesor de los que pueden acceder a la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones:**
1. Debe existir un fichero binario en el directorio con los usuarios y las contraseñas de los profesores registrados.
2. El usuario debe estar registrado como coordinador para ejecutar esta funcionalidad.

**Flujo principal:**
1. El caso de uso empieza cuando el usuario quiere dejar de permitir el acceso al sistema a un profesor registrado.
2. El programa pide al coordinador el nombre de usuario que quiere borrar.
3. El programa comprueba si el usuario esta en el fichero de credenciales.
4. El sistema elimina el profesor del fichero de credenciales.

**Postcondiciones:**
1. Se modifica el fichero de credenciales, dejándolo igual pero sin incluir el profesor eliminado y la contraseña de este.

**Flujos alternativos**
1. Si el nombre de usuario a eliminar pertenece al coordinador, se mandará un mensaje de error y no se eliminará.
2. Si el usuario no se encuentra en el fichero de credenciales, este no se verá modificado.
