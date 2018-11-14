# Caso de uso

## Guardar la base de datos

**ID:** 08

**Breve descripcion:** Al realizar cualquier operación, los cambios se volcarán sobre la base de datos.

**Actores principales:** Profesor

**Actores secundarios:** Alumnos

**Precondiciones:**
1. La base de datos debe haber sido cargada antes de realizar algún cambio.

**Flujo principal:**
1. El caso de uso empieza cuando el usuario hace alguna operación de modificación o adición, entonces se volcará el contenido nuevo en la base de datos.
2. Se pregunta al usuario si quiere guardar los cambios sobre el mismo fichero o no.
3. Se pide el nombre del fichero al usuario.
4. Se crea el fichero con el nombre especificado.

**Flujos alternativos**
1. En caso de que no se pueda guardar el contenido, se mostrará un mensaje de error y se finalizará el programa.
2. Si el nombre del fichero que pide el usuario coincide con algún fichero en el directorio, se muestra un mensaje al usuario. Puede sobreescribirlo o cambiar el nombre.
