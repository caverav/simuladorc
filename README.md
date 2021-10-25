# simuladorc

## Descripción del programa

El mundo en el cual se hará la simulación será representado por una matriz cuadrada de
1000x1000. Cada casilla podrá ser ocupada por un animal. Además, en este mundo se definirán
diferentes tipos de animales con distintas caracterı́sticas que serán ingresados por consola.

### Animales
Cada animal corresponderá a una estructura que contiene tres atributos básicos (fuerza,
velocidad y resistencia) y cada uno tiene asociado a su vez un caracter que le especifica su
tipo, si es un entero se almacenará “e”, si un caracter se almacenará “c” y si es un flotante se
almacenará “f”. También tiene dos punteros a funciones que serán: reproducción y comerHuir.
```
typedef struct Animal {
void *fuerza ;
char tipo_fuerza;
void *velocidad;
char tipo_velocidad;
void *resistencia;
char tipo_resistenca;
void ( *reproduccion ) ( struct Animal* , struct Animal* , struct Animal*);
void ( *comerHuir ) ( struct Animal* , struct Animal* ) ;
} Animal ;
```
### Comparación de dos atributos iguales
Para comparar los diferentes tipos de atributos, se hará una operación que permitirá tener
todos los valores de tipo entero. Si el atributo es entero se considera el valor como tal. Si el
atributo es caracter se considera el valor ASCII del caracter y se aplica división entera por 4.
Si el atributo es flotante se redondea el valor. Y ası́ se pueden comparar todos los tipos como
enteros.

### Programa general
Su programa general debe generar un menú que permita crear animales, tener la opción de
avanzar una iteración en el tiempo y una opción para mostrar el mundo. Cada animal, será
creado en un lugar NO OCUPADO de la matriz, donde se debe pedir por pantalla en cuales
coordenadas será creado. También al crear animal se debe preguntar por cual función usar, para
eso se ingresará un entero por función y tendrá el siguiente entero asignado:


Funciones de reproducción
  1. ReproduccionSimple
  2. ReproduccionCruzada


Funciones de comerHuir
  1. ComerSiempre
  2. HuirSiempre
  3. ComerAleatorio

Avanzar una iteración en el tiempo, provocará que todos los animales se muevan una casilla,
donde puede ser arriba, abajo, izquierda y derecha, siendo estas cuatro opciones equiprobables
(25 % cada una). Si llega la situación donde dos animales aparezcan en la misma casilla se debe
hacer lo siguiente: primero deben reproducirse, el hijo que nazca de esa relación debe situarse
a la izquierda de la casilla actual, si está ocupada se ubicará en la casilla de arriba, si está
ocupada se situará en la casilla de la derecha, si está ocupada le queda la última opción que es
la casilla de abajo, sino hay casilla disponible el hijo se morirá. Luego, de la reproducción los
padres deben combatir entre ellos.
También debe existir una opción para terminar el programa y al seleccionar esta opción debe
liberar toda la memoria pedida.

### Instalación y ejecución:
```
git clone https://github.com/caverav/simuladorc.git
cd simuladorc
make run
```

### Detalles de funciones
  - CrearAnimal: se debe recibir la variable donde se creará el animal (puntero), donde adentro se le deberá pedir los atributos por consola, por ende deben pedir el tipo que voy a ingresar y el valor. Y también que funciones usar (más adelante se detalla al respecto).
  - BorrarAnimal: se debe recibir un animal y eliminarlo.
  - MostrarAnimal: se debe recibir un animal y mostrarlo por pantalla.
  - Reproducir: debe reproducir dos animales entre ellos. Para saber, que función de reproduc-
ción usar deben elegir al azar, donde hay un (50 % de elegir la función del primer animal y
50 % de elegir la función del segundo animal, debe mostrar por pantalla cual fue el animal
que uso la función).
OJO: si se elige la función del primer animal se debe pasar como parámetro primero el
primer animal y segundo el otro animal, si se elige la función del segundo animal se debe
pasar como parámetro primero el segundo animal y segundo el otro animal.
  - ComerOHuir: debe realizar la acción de alguno de los animales. Para saber, que función
de comerHuir usar deben elegir al azar, donde hay un (50 % de elegir la función del primer
animal y 50 % de elegir la función del segundo animal), debe mostrar por pantalla cual fue
el animal que uso la función y resultado de está).
OJO: si se elige la función del primer animal se debe pasar como parámetro primero el
primer animal y segundo el otro animal, si se elige la función del segundo animal se debe
pasar como parámetro primero el segundo animal y segundo el otro animal.
  - Comparar: Debe recibir dos animales. La comparación se hará de la siguiente forma, se
comparará cada atributo de los animales respectivamente (fuerza con fuerza, velocidad
con velocidad, resistencia con resistencia). Luego, si
el primer animal tiene más atributos mayores se retorna 0, sino se retorna 1.
  - BorrarMundo: debe borrar todos los animales del mundo y el mundo mismo.
  - MostrarMundo: debe mostrar cada animal dentro del mundo.
 
Las siguientes funciones corresponden a funciones que los Animales deben tener para reproducirse y comerHuir, como se indicó más arriba. Estas cinco funciones son para que vean que su programa funciona, teóricamente hablando se le podrı́a pasar cualquier otra función para reproducción o comerHuir.
  - ReproduccionSimple: debe recibir dos animales (a1 y a2) y el animal a hijo a crear. La
reproducción se hará de la siguiente forma, se comparará los animales gracias a la función
comparar de más arriba. Luego, si el valor que retorna es 0 entonces el animal hijo recibe
todo del animal a1, sino el animal hijo recibe todo del animal a2.
  - ReproduccionCruzada: debe recibir dos animales (a1 y a2) y el animal a hijo a crear. La
reproducción se hará de la siguiente forma, se comparará los animales gracias a la función
comparar de más arriba. Luego, si el valor que retorna es 0, entonces el animal hijo recibe la
fuerza, velocidad y función de reproducción del animal a1 y recibe la resistencia y función
de comerHuir del animal a2. Si el valor que retorna no es 0, entonces el animal hijo recibe
la resistencia y función de comerHuir del animal a1 y recibe la fuerza, velocidad y función
de reproducción del animal a2.
  - ComerSiempre: debe recibir dos animales (a1 y a2) se debe tomar la fuerza del animal
a1 y compararla con la resistencia del animal a2, si la fuerza es mayor a la resistencia, el
animal a2 se muere, sino el animal a1 se muere.
  - HuirSiempre: debe recibir dos animales (a1 y a2) se debe tomar la velocidad del animal a1
y compararla con la velocidad del animal a2. Si la velocidad de a1 es mayor a la velocidad
de a2, el animal a1 vive y se mueve a la izquierda de la casilla actual, si está ocupada se
ubicará en la casilla de arriba, si está ocupada se situará en la casilla de la derecha, si está
ocupada le queda la última opción que es la casilla de abajo, sino hay casilla disponible el
animal a1 morirá. Si la velocidad del animal a2 es mayor o igual a la velocidad del animal
a1, entonces se muere definitivamente.
  - ComerAleatorio: debe recibir dos animales (a1 y a2) se debe tomar algún atributo del
animal a1 al azar y compararlo con un atributo del animal a2 al azar, luego se comparan
los atributos obtenidos y el que tenga mayor atributo se come al otro animal. En el caso
de empate, el animal a2 se come a1 siempre.

