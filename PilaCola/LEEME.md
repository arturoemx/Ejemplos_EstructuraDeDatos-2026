# Pilas y Colas
Esta carpeta contiene ejemplos desarrollados en clase para las estructuras Pilas y Colas.

# Organizacion
Esta carpeta contiene la implementación en ```C++``` de **Pilas** y **Colas** usando plantillas o *templates*.

Como tanto las **Pilas** y **Colas** pueden implementarse utilizando arreglos, se muestran tres variantes para la implementación de cada una de ellas:

* Definiendo un estructura que directamente obtiene memoria dinámica para almacenar los valores de la **Pila** o la **Cola**.
* Definiendo un estructura que tiene como atributo un objeto del tipo **arreglo** que vimos en clase.
* * Definiendo un estructura que hereda de la estructura **arreglo** que vimos en clase.

Los algoritmos básicos que definen a las estructuras (```push``` y ```pop``` para **Pilas** y ```enqueue``` y ```dequeue``` para **Colas**) son esencialmente los mismos, pero estos ejemplos sirven de muestrario de tres diferentes formas de llegar al mismo objetivo.

# Contenido de la carpeta

## Archivos de encabezado
Todos los archivos que se mencionan aquí se encuentran dentro del directorio ```include```.

* ```arreglo.h```: Declaración de una plantilla para un arreglo unidimensional.

### Declaraciones de Pilas

* ```Pila.h```: Declaración de una plantilla para una **Pila** que incluye un objeto tipo arreglo como atributo.
* ```PilaH.h```: Declaración de una plantilla para una **Pila** que herede de una estructura tipo arreglo como atributo.
* ```PilaB.h```: Declaración de una plantilla para una **Pila** que directamente obtenga la memoria para almacenar la información de la **Pila**.

### Declaraciones de Colas

* ```Cola.h```: Declaración de una plantilla para una **Cola** que incluye un objeto tipo **arreglo** como atributo.
* ```ColaH.h```: Declaración de una plantilla para una **Cola** que herede de una estructura tipo **arreglo** como atributo.
* ```ColaB.h```: Declaración de una plantilla para una **Cola** que directamente obtenga la memoria para almacenar la información de la **Cola**.
* ```ColaAlt.h```: Esta es una varíante de la estructura ```Cola.h```. En el resto de las implementaciónes se comparan los índices ```H``` y ```T``` para determinar si una cola esta vacía o llena. Esto es, si ```H == T``` entonces la cola está vacía y si ```T+1 == H``` la cola está llena. La desventaja de este método es que se desperdicia un espacio del arreglo. La variante ```ColaAlt.h``` agrega un atributo que almacena cuantos elementos se han almacenado en la cola. Esto permite utilizar todos los espacios en el arreglo, con la desventaja de que hay un atributo extra que se tiene que modificar al meter o sacar elementos en la cola.

### Ejemplos

* ```ejemploPila.cpp```, ```ejemploPilaH.cpp```, ```ejemploPilaB.cpp```:

	Estos ejemplos son iguales, únicamente difieren en que implementación de la **Pila** utilizan y hacen lo siguiente para demostrar el funcionamiento de la estructura:

	1. Imprimen la pila, que se encuentra vacía.
 	2. Llena la cola hasta la mitad y la imprimen.
	3. Trata de meter más elementos de los que caben en la pila y la imprime.
	4. Trata de sacar más elementos de los que caben en la pila y la imprime.

* ```ejemploCola.cpp```, ```ejemploColaH.cpp```, ```ejemploColaB.cpp```, ```ejemploColaAlt.cpp```:
* 
	Estos ejemplos son iguales, únicamente difieren en que implementación de la **Cola** utilizan y hacen lo siguiente para demostrar el funcionamiento de la estructura:

	1. Imprime la cola vacia.
	2. Repiten ```vueltas``` veces los siguiente:
		1. Meten un cierto número de valores en la cola y la imprime.
		2. Saca un cierto número de valores de la cola y la imprime.
	3. Vacía la cola y la imprime.

* ```Makefile```: Archivo que permite automatizar el proceso de compilación de los programas.
* ```LEEME.md```: Este documento.