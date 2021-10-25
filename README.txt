Nombre: Camilo Vera
ROL: 202073012-1

Detalles importantes:
    Se implementaron las funciones auxiliares swap y Mover, ya que facilitarán al momento de tener que intercambiar dos animales y para controlar de una forma más ordenada un animal, respectivamente.
    Se editó el struct animal para implementar un control de coordenadas (agregados int i, j)
    Se añadió int movido a struct para evitar mover más de una vez un animal gracias a la ciclicidad de la matriz.
    Se añadió int creado a struct para obtener control sobre si el animal fue creado o está vacío, facilitaba el check en algunos casos.

Instrucciones:
    - Para compilar, escribir en consola: make
    - Para compilar y ejecutar, escribir en consola: make run
    - Para limpiar (borrar el ejecutable), escribir en consola: make clean
    - Para compilar y ejecutar con valgrind, escribir en consola: make memory

El programa le preguntará lo que desea hacer, entre las opciones estan:
    [1] Crear animal. (Inicia proceso de creación de animal individual)
    [2] Avanzar una iteración de tiempo. (Se mueven una casilla todos los animales)
    [3] Mostrar mundo. (Muestra los atributos de cada animal en el mundo)
    [4] Terminar simulación. (Borra el mundo y termina ejecución)
