# Metodología de la Programación:  proyecto final, parte 1

###### Leire Requena Garcia, 48258823Q

###### Clara María Romero Lara, 05985367P

## 1. Clase ConjuntoParticulas

| Test    | Ejecuta | Salida Correcta | Valgrind |
| ------- | ------- | --------------- | -------- |
| $$t_1$$ | SI      | SI              | BIEN     |
| $$t_2$$ | SI      | SI              | BIEN     |
| $$t_3$$ | SI      | SI              | BIEN     |
| $$t_4$$ | SI      | SI              | BIEN     |
| $$t_5$$ | SI      | SI              | BIEN     |

#### 1.2. Salida test 6 PruebaConjuntos

![image-20220524183558182](/home/clara/.config/Typora/typora-user-images/image-20220524183558182.png)

## 2. Desafíos

La **instalación de `raylib`** ha sido sencilla, pero por problemas con la versión de Linux y los drivers de la gráfica de uno de nuestros dispositivos, hay que reinstalarlo cada vez que se reinicia el ordenador. Insistimos en que es un problema específico a nuestro sistema, y su resolución es fácilmente automatizable mediante el siguiente script, que ubicamos en `raylib/src` y ejecutamos con `sudo ./install.sh` :

```bash
!#/bin/sh

make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED
make install RAYLIB_LIBTYPE=SHARED
```

La **programación de los desafíos** ha sido sencilla. No ha habido dificultades a destacar.

Estamos **conformes** con el resultado final de esta primera parte.

#### 2.1. Desafío uno: gas

En este desafío hemos generado un `conjuntoParticulas` de N elementos, que se representan en pantalla con círculos. Estos rebotan entre sí y pierden velocidad en el eje Y con el tiempo.

Lo que sucede al decrementar sólo la velocidad en Y es que las partículas acaban quedando fijas en una altura, en la que rebotan entre sí y con las paredes a lo largo del eje X.

#### 2.2. Desafío dos: pared

Este desafío genera una `Particula Bola` y un `conjuntoParticulas Pared` de N elementos. Ambos objetos se generan de forma aleatoria, si bien los ladrillos de la pared se dibujan con una función específica que representa un rectángulo de alto igual al radio de la partícula y ancho doble del alto.

Durante la ejecución, la bola se mueve constantemente y colisiona y rebota con los ladrillos, eliminándolos al toque. Cuando no quedan ladrillos finaliza la ejecución.

## 3. Versión preliminar de *Breakout*

En esta versión preliminar del juego (que es una serie de mejoras sobre el desafío 2) contamos con los siguientes elementos:

- Una partícula `Bola`, que se inicializa de forma aleatoria y se mantiene en constante movimiento. En pantalla se representa con un círculo de raylib. 

  Rebota con los límites de la pantalla, con la `Base` y con los ladrillos de la `Pared`, a los que también destruye al contacto. Tras eliminar el último ladrillo, el juego finaliza.

- Una partícula `Base`, que se inicializa en el centro de la parte inferior de la pantalla y se mueve mediante las flechas del teclado. Se representa con un rectángulo de raylib, cuyo alto es el radio de la partícula y el ancho es el triple del alto.

  Este elemento no rebota en colisión, es fijo. Su velocidad en Y es 0 para permitir únicamente el movimiento sobre el eje X.

- Un conjunto de partículas `Pared`, que se inicializa de forma aleatoria y luego se procesa para colocar los ladrillos en filas en la parte superior de la pantalla. Su representación es un rectángulo de raylib, cuyo alto es el radio de la partícula y el ancho es el doble del alto.

  Los elementos de la `Pared` desaparecen tras una colisión y, a pesar de poseer atributos de velocidad, son inmóviles porque no les aplicaremos el método `mover()`.

#### 3.1. Mejoras futuras sobre lo implementado

- La `Bola` se inicializará en una posición central, con una velocidad preestablecida. Actualmente puede inicializar en lugares inapropiados, y su velocidad es aleatoria dentro de un rango.
- La generación de ladrillos de la `Pared` se adaptará para encajar correctamente en la pantalla. Actualmente la generación sobrepasa ligeramente los límites de la pantalla.
- El juego finalizará si la `Bola` colisiona con el límite inferior de la pantalla (es decir, si no la hacemos rebotar sobre la `Base`). Actualmente la `Bola` rebota sobre todos los elementos, haciendo redundante el elemento de la `Base`.
- La `Base` se moverá correctamente en su eje X. Actualmente existe un punto a la izquierda que no sobrepasa.

#### 3.2. Características extra

El guión de prácticas sugiere una serie de añadidos que implementar en el juego, previa consulta con el profesor. Nos interesan los siguientes aspectos:

- Encapsular los objetos y lógica del juego en una clase `Game` que tenga como métodos, por ejemplo, `Init()` y `Update()`.
- Posibilidad de tener varias “vidas”, ladrillos especiales que si se destruyen dan puntos extra, ladrillos que “caen” y si se capturan dan vida extra, etc...
- Modo dos jugadores, con dos bases controladas por las flechas de dirección y WASD.
- Gestión en ficheros de las mejores puntuaciones
