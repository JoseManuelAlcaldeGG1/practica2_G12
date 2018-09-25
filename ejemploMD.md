## Comandos Ramas III

1. **Almacenar cambios temporales:**
`git stash save "Mensaje"`

2. **Listar cambios:**
`git stash list`

3. **Ver contenido de un cambio temporal:**
`git stash show -p nombre_stash`

4. **Eliminar un cambio temporal:**
`git stash drop nombre_stash`

5. **Aplicar cambio del stash:**
   ~~~
   git stash apply nombre_stash
   git stash pop nombre_stash
   ~~~

# GitHub

![Imagen github](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRuW2rqf0Lw3E_kvxt7EFX9Y7C0o6Fba2UNpi_NCQayJ13AC0GI8Q)

## Comandos GitHub I

1. **Añadir repositorio remoto:**
`git remote add origin url`

2. **Ver repositorios remotos:**
`git remote -v`

3. **Eliminar repositorio remoto:**
`git remote rm origin`

4. **Añadir cambios del repositorio local al remoto:**
`git push -u origin master`

5. **Añadir cambios del repositorio remoto al local:**
`git pull`

## Comandos GitHub II

1. **Ver branches remotos:**
`git branch -r`

2. **Ver todos los *branches*:**
`git branch -a`

3. **Clonar un repositorio remoto:**
`git clone url`

# Dar seguimiento a todos los *branches*:

* **LOCAL --> REMOTO**
	* Cambios en el repositorio local.
	* Commit de los cambios.
	* Añadir cambios de un repositorio remoto:
	`git push`

* **REMOTO --> LOCAL**
	* Sincronización y unión:
	~~~
	git fetch origin
	git merge origin/master
	~~~
	* En un solo paso:
	`git pull`

# Operaciones con *branches* remotos

* **Creación**
	1. Crear *branch* local.
	2. Hacer cambios en dicho *branch*.
	3. Hacer commit.
	4. Copiar el *branch* al repositorio remoto:
	`git push -u origin branch_remoto`

* **Copia:**
`git checkout -b local remoto`

* **Eliminación:**
`git push origin --delete branch_remoto`

*Esta es cursiva* 
**Esta es negrita**
1. Esto es una lista
2. segundo elemnto
3. tercer elemento
* lista 1
  * sublista
    * lista
    * lista
* lista 2
# Encabezzado 1
## Encabezado 2
### Encabezado 3
#### Encabezzado 4
##### Encabezado 5
###### Encabezado 6
> Esto es una cita

`Esto es un bloque de codigo`

~~~
Esto es un bloque de
codigo de varias lineas
~~~

![Imagen de google](http://www.colemancbx.com/wp-content/uploads/2015/09/Logo-Google.jpg)
