# Metodología de la Programación:  proyecto final, parte 2

###### Leire Requena Garcia, 48258823Q

###### Clara María Romero Lara, 05985367P

## 1. Extensión de las clases existentes

### 1.1. Extensión de la clase Partícula

#### Sobrecarga de operadores

Se han sobrecargado los siguientes operadores:

- Operador >> 
- Operador << 
- Operador == 

#### Nuevos métodos y atributos

- **Atributo `Tipo`: **se ha añadido un atributo Tipo, que es un enum con tres posibles valores: Bola, Base, Ladrillo. El valor por defecto de Tipo es Bola. 

  Hemos considerado que este atributo era la mejor forma de resolver redundancias en el código, ya que las colisiones, o el pintar la partícula requerían de una función específica cuando estabamos tratando con una Partícula que no era un círculo.

### 1.2. Extensión de la clase ConjuntoPartículas

#### Sobrecarga de operadores

- Operador =
- Operador ==
- Operador <<
- Operador []
- Operador + (agrega una partícula al conjunto)
- Operador < (basado en la distancia media del conjunto hasta el punto (0,0))

#### Nuevos métodos y atributos

- distanciaPromedio(const Particula &otra) - Dado un conjunto de partículas y otra partícula, calcula la distancia media del conjunto a ésta.
- hacerFila(int ancho, int alto) - Genera una fila de ladrillos

### 1.3. TestConjuntoFinal

Adjuntamos una tabla resumen con los resultados de los test de pruebaConjuntoFinal:

| Test                           | Salida esperada | Salida correcta | Valgrind correcto |
| ------------------------------ | --------------- | --------------- | ----------------- |
| 0 - Partículas                 | ✓               | ✓               | ✓                 |
| 1 - Constructores y destructor | ✓               | ✓               | ✓                 |
| 2 - Sobrecarga + y <<          | ✓               | ✓               | ✓                 |
| 3 - Sobrecarga =               | ✓               | ✓               | ✓                 |
| 4 - Sobrecarga ==              | ✓               | ✓               | ✓                 |
| 5 - DistanciaPromedio          | ✓               | ✓               | ✓                 |
| 6 - Sobrecarga <               | ✓               | ✓               | ✓                 |
| 7 - Ordenar ConjuntoParticulas | ✘               | ✓               | ✓                 |
| 8 - Sobrecarga[] 1             | ✓               | ✓               | ✓                 |
| 9 - Sobrecarga[] 2             | ✓               | ✓               | ✓                 |

La salida del test 7 no coincide con la proporcionada, pero esto se debe a que estamos operando en dimensiones distintas (la salida esperada incluye elementos mayores de 600, que es nuestro límite). Sin embargo, su funcionamiento es correcto: ordena según su DistanciaPromedio un ConjuntoParticulas

## 2. Breakout

La versión final del juego cuenta con los siguientes elementos

- Una partícula `Bola`, que se genera a media altura de la pantalla y se mantiene en constante movimiento. En pantalla se representa con un círculo de raylib.

  Rebota con los límites de la pantalla, con la `Base` y con los ladrillos de la `Pared`, a los que además destruye al contacto. Tras eliminar el último ladrillo, el juego finaliza. También finalizará el juego si no tenemos bolas en juego, lo cual sucede si tocan el borde inferior de la pantalla (es decir, no rebotan en la base).

  Existe un parámetro que genera una segunda bola, con mismo comportamiento e interacción que la primera. Si se pierde una única bola, se puede continuar jugando con la otra.

- Una partícula `Base`, que se inicializa en el centro de la parte inferior de la pantalla y se mueve mediante las flechas del teclado. Se representa con un rectángulo de raylib, cuyo alto es el radio de la partícula y el ancho es el triple del alto.

  Este elemento no rebota en colisión, es fijo. Su velocidad en Y es 0 para permitir únicamente el movimiento sobre el eje X.

  Existe un parámetro que genera una segunda base, controlada con WASD y ubicada encima de la primera.

- Un array de  ConjuntoParticulas `Pared`, que se inicializa de forma aleatoria y luego se procesa para colocar los ladrillos en filas en la parte superior de la pantalla. Su representación es un rectángulo de raylib, cuyo alto es el radio de la partícula y el ancho es el doble del alto.

  Los elementos de la `Pared` desaparecen tras una colisión y, a pesar de poseer atributos de velocidad, son inmóviles porque no les aplicaremos el método `mover()`. 

Estos elementos son gestionados por la clase Juego, de la que hablaremos más adelante, y luego son obtenidos y dibujados con raylib desde `breakout.cpp`.

### Cambios y mejoras sobre la parte 1

- La pared antes era un único conjunto de partículas - ahora es un array de ConjuntoParticulas, en el que cada elemento corresponde a una fila de la pared.
- La generación de la pared antes empleaba dos bucles anidados que modificaban (x,y) de cada ladrillo. Ahora, los ladrillos tienen velocidad (dx,dy) y se colocan en su puesto usando el método mover().
- El juego finaliza cuando la bola toca el extremo inferior de la pantalla.
- Funcionalidades extra, en el apartado 3 se explican con mayor detalle

### Problemas encontrados

A continuación se detallarán las tareas opcionales que desarrollamos, pero adelantamos que parte de ellas implican pasar de Particula a ConjuntoParticulas en los elementos Bola y Base. El cambio supuso un cierto esfuerzo hasta que todos los elementos funcionaron correctamente.

Un problema que no pudimos resolver fue la discordancia entre la base en el modelo y la base en la vista. Dado que tomamos inicialmente que el alto del ladrillo fuera el radio (en vez de el diámetro), cuando generamos un ladrillo una parte de Partícula de tipo bola queda fuera de lo que es la representación del rectángulo, que colisiona con la pared izquierda. A pesar de haber desarrollado una colisión específica para los rectángulos, las colisiones con los extremos de la pantalla se siguen basando en la partícula circular, y no hubo tiempo para solucionarlo.

Todos nuestros intentos de ajustar la representación y permitir movimiento hasta el extremo izquierdo han sido en vano, ya que, aunque ahora mismo la base no se mueva en el 100% del ancho, su representación y colisiones como rectángulo son fieles a la realidad. No podemos decir lo mismo cuando la base sí llegaba a los extremos tras ciertos ajustes en el dibujo, en cuyo caso la bola rebotaba en el vacío o no rebotaba a pesar de hacer contacto con la base. Es por ello que hemos decidido dejar la base como está: con colisiones verdaderas, pero con un rango de movimiento limitado.

Algunos otros problemas, menos sustanciales, han sido a la hora de cerrar el juego cuando la pared se quedaba vacía, la entrada de parámetros, o problemas con las colisiones propios de la naturaleza simple de la implementación.

## 3. Tareas opcionales

Tras la consulta con el profesor, se acordó añadir las siguientes funcionalidades:

- Implementación de la clase Juego
- Entrada de parámetros extra a la clase Juego mediante ficheros

### 3.1. Implementación de la clase Juego

Se creó una clase Juego que contiene los elementos y las reglas asociadas al breakout: de esta forma, la lógica de juego queda separada de las llamadas relacionadas con raylib, la vista.

La clase Juego, de base, contiene los siguientes atributos:

- Un array de `ConjuntoParticulas Pared`, en el cual cada elemento del array representa una fila de ladrillos. La clase Juego contiene los atributos y métodos necesarios para gestionar este array dinámico correctamente (capacidad y útiles; reserva, redimensión y liberación de memoria...)
- Una `Particula Bola`
- Una `Particula Base`

En el siguiente apartado veremos las modificaciones realizadas sobre estos atributos para la implementación de partículas extra.

Los métodos más relevantes de la clase son:

- `void Init()` - Inicialización de los elementos necesarios para el juego. Es llamada una vez desde breakout para inicializar la instancia del juego.
- `bool Update()` - Función llamada cada uno de los ciclos en los que la ventana está abierta, antes de dibujar. Gestiona el movimiento de los objetos, las colisiones, condiciones de parada... En caso de alcanzarse la condición de parada, lo devuelve por la salida para detener la ejecución de la vista.

### 3.2. Parámetros opcionales

Para la implementación de parámetros opcionales, se hicieron modificaciones sobre la clase Juego. En sus atributos añadimos un array de booleanos que determinan si un parámetro extra está activo o no. Los parámetros extra son:

- Bola extra, genera dos bolas. Cuando una de las bolas toca el suelo, esta se elimina y se puede continuar el juego con la bola restante.
- Base extra, genera una segunda base encima de la primera. Esta nueva base se controla con WASD, y actúa igual que la base inicial, sólo pudiéndose mover en el eje X.
- Velocidad extra, añade un multiplicador de velocidad a la(s) bola(s) y base(s).

Para poder aplicar esta nueva configuración, las modificaciones sobre clase Juego han sido:

- Se ha hecho un constructor con parámetros `Juego(int N, bool settings[NUM_SETTINGS])` 

- Tanto Bola como Base han pasado a ser un ConjuntoParticulas. En caso de no emplear los parámetros relevantes, simplemente serán un ConjuntoParticulas con un solo elemento. 

  Así pues, ha habido que cambiar las llamadas a las funciones de Particula de estos dos elementos por sus equivalentes en ConjuntoParticulas, o llamarlas mediante bucles.

  - Algunas de las comprobaciones han tenido que hacerse "manualmente" comprobando con un if si había más de 1 elemento. Esto se ha usado, principalmente, para la generación de la bola o de la base secundaria en un punto específico de la pantalla.

- Múltiples comprobaciones durante la inicialización del juego para aplicar o no ciertos cambios según los *settings*.

La entrada de parámetros puede hacerse de forma manual, introduciendo una serie de tres valores booleanos, o mediante un fichero, como veremos a continuación. 

### 3.3. Entrada de parámetros a la clase Juego mediante ficheros

Para la entrada de datos desde un fichero, hemos incluido la biblioteca <fstream> para obtener un flujo de entrada. Cargamos el fichero introduciendo la ruta indicada en argv[2] con la función `open()` y, si se ha podido abrir correctamente, lo recorremos enteramente, obteniendo una línea a cada iteración y asignando su valor al vector de parámetros. Si la ruta no existiera, o no se pudiera abrir el archivo, la ejecución finalizaría. 

Adjuntamos en el directorio txt una serie de ficheros de prueba con distintas combinaciones que dan lugar a modos de juego interesantes:

- `dosjugadores.txt` activa la segunda bola y la segunda base controlada por WASD.
- `mododificil.txt` activa la segunda bola y la velocidad.
- `velocidad.txt` activa la velocidad.
- `todo0.txt` es el juego base.
- `todo1.txt` tiene los tres parámetros activados. Podría tomarse como un modo dos jugadores difícil.

## 4. Compilación e instrucciones de ejecución

Se adjunta un *makefile* con el que compilar la práctica en su totalidad.

Existen dos formas de ejecutar el juego:

1. Manual, en la que introduciremos los parámetros de la siguiente manera:

   ```c
   ./bin/breakout <N> <BOLA> <BASE> <VELOCIDAD>
   ```

   Donde `N` es el número de filas de la pared, y `BOLA`, `BASE`, `VELOCIDAD` son booleanos que activarán los distintos "extras" de configuración

2. Mediante fichero, en la que usaremos un fichero de parámetros:

   ```
   ./bin/breakout <N> <RUTA>
   ```

   Donde `N` es el número de filas de la pared, y `RUTA` es la ruta de uno de los archivos de

   parámetros, adjuntos en el directorio `txt`.

Un comando de ejecución que no contenga los parámetros necesarios, o en el que sean inválidos, nos dará como salida una función de ayuda y no ejecutará el juego.