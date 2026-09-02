# Arreglos
Esta carpeta contiene ejemplos desarrollados en clase para ilustrar la creación de arreglos.

# Organizacion
El contenido de la carpeta se organizará conforme vayamos avanzando en el tema.

## Programa Monolitico.
En este ejemplo tanto la definición de la estructura del arreglo como el código que usa dicha estructura.

## Programa Multi-archivo
En este ejemplo la definición de la estructura se almacena en un archivo de encabezado (```arrInt.h```), mientras que el código que utiliza la estructura se escribe en un archivo aparte (```pruebaArrInt02.cpp```).

Usualmente cuando se separa el código así, en el archivo de encabezado están únicamente las definiciones y el código asociado a la clase definida ahí se almacena en otro archivo. Esto es debiera haber un archivo ```arrInt.h```, un archivo ```arrInt.cpp``` y un archivo ```pruebaArrInt02.cpp```, pero como nuestra intención es eventualmente explicar el uso de plantillas (```templates```), no avanzaremos más en esa dirección.

# Contenido
* ```pruebaArrInt01.cpp```: Ejemplo Monolítico del Programa. Primer ejemplo visto en clase. En el archivo de prueba se incluye la definición de la estructura de un arreglo de enteros, así como el código que utiliza la estructura
* ```arrInt.h```: Parte el ejemplo multi-archivo. En este archivo esta el código que concierne a la estructura ```arrInt```.
* ```pruebaArrInt02.cpp```: Parte el ejemplo multi-archivo. En este archivo esta el codigo que demuestra el uso de la estructura ```arrInt```.
* ```Makefile```:Archivo que permite automatizar el proceso de compilación de los programas.
* ```LEEME.md```: Este documento.


