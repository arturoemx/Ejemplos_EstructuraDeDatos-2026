# Ejercicio Inicial de Valoración - Estructura de Datos - Grupo A

Este directorio contiene varias soluciones al ejercicio de valoración que se aplicó el primer día de clases en la asignatura **Estructura de Datos** que se imparte en la Facultad de Matemáticas de la Universidad Autónoma de Yucatán a los estudiantes de la carrera "Ingeniería en Computación" de la carrera "Ingeniería en Computación".

El ejercicio consistió en lo siguiente: implemente un algoritmo que invierta el orden de los valores enteros almacenados en arreglo. 

Por ejemplo, si el arreglo, llamémoslo ```A```, originalmente contiene los siguientes valores:

```A = [1, 56, 4, 0, 6]```

después de invertirlo deberá lucir como sigue:

```A = [6, 0, 4, 56, 1]```

## Requerimientos

 * Compilador de C++ (C++11).
 * Programa ```make```:
   Véase:
		   * [Pagina Wikipedia Make](https://es.wikipedia.org/wiki/Make)
		   * [Página de GNU-Make](https://www.gnu.org/software/make/)
 * Acceso a una consola o terminal virtual.

## Uso

Para compilar los programas, desde una consola invoque el programa ```make```:

```
 $ make
```

Para eliminar los archivos ejecutables, invoque el programa ```make``` como sigue:
```
$ make clean
```

Para ejecutar los programas, desde una consola invoque los programas como sigue:

   * Para el programa ```ejValSolución-1```:
   ```
    $ ./ejValSolución-1
   ```

   * Para el programa ```ejValSolución-2```:
   ```
    $ ./ejValSolución-2
   ```

   * Para el programa ```ejValSolución-3```:
   ```
    $ ./ejValSolución-3
   ```

   * Para el programa ```ejValSolución-F```:
   ```
    $ ./ejValSolución-F <n> <modo> [o]
   ```
   donde:
* **```n```** es un valor entero positivo que indica el tamaño del arreglo. Este es un parámetro obligatorio.
* **```modo```** es un valor entero positivo en el intervalo ```[1,3]``` que indica el algoritmo que se va a utilizar para invertir el arreglo, por ejemplo ```1``` corresponde a la solución usada en el programa ```ejValSolución-1.cpp```,  ```2``` corresponde a la solución usada en el programa ```ejValSolución-2.cpp``` y ```3``` corresponde a la solución usada en el programa ```ejValSolución-3.cpp```. Este es un parámetro obligatorio.
* **```o```** Este es un parámetro optativo si el tercer parámetro es igual al caracteres '```o```' u '```O```', no se imprimirá el arreglo que se generó. Esto es útil cuando lo único que nos interesa es saber cuanto tarda el algoritmo en ejecutarse.
## Contenido:

 * ```ejValoración.cpp```: Ejercicio de valoración tal como se vio en clase. Todo lo necesario para implementar el programa exceptuando el algoritmo en si.

 * ```ejValSolución-1.cpp```: Primera solución, copia los valores a un segundo arreglo invirtiendo el orden y los copia del segundo arreglo al primero manteniendo el orden.

 * ```ejValSolución-2.cpp```: Recorre el arreglo desde atrás hacia adelante y de adelante hacia atrás, hasta llegar al punto medio, intercambiando los valores visitados. El intercambio se realiza usando una variable temporal.

 * ```ejValSolución-3.cpp```: Recorre el arreglo desde atrás hacia adelante y de adelante hacia atrás, hasta llegar al punto medio, intercambiando los valores visitados. El intercambio se realiza utilizando el operador XOR y no requiere una variable temporal.

 * ```ejValSolución-F.cpp```: Este programa permite ejecutar cada uno de los algoritmos implementados, utilizando argumentos para determinar el tipo de algoritmo a utilizar, el tamaño del arreglo a invertir y si se debe imprimir el arreglo o no. Además imprime el tiempo que se requirió para ejecutar el algoritmo. Utiliza muchas técnicas que no hemos visto en clase aún: memoria dinámica, medición del tiempo, enumeraciones, pase de argumentos a programas.

 * ```Makefile```: Este archivo es leído por el programa  ```make``` para compilar el código. Desde una consola invoque el programa como sigue:
 
 ```
 $ make
 ```

 y los programas fuentes que implementan las soluciones se compilarán. Para eliminar los programas ejecutables desde una consola invoque el programa ```make``` como sigue:

 ```
 $ make clean
 ```

 * ```README.md```: Este archivo que está usted leyendo.
