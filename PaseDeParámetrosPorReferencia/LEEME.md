# Pase de parámetros por referencia.
En este directorio se encuentran ejemplos que ilustran como el paso de parámetros por referencia permite a una función regresar más de un resultado de cómputo sin requerir el uso de estructuras.

Se implementa una función que encuentra la solución de una ecuación de segundo grado, cuya solución se puede representar con hasta 4 números reales. *i.e.* hay hasta dos soluciones diferentes y cada una de ellas puede ser un número complejo que tiene dos componentes, uno real y uno imaginario.

Se presentan dos ejemplos, uno implementado en ```C``` y otro en ```C++```.

El primero hace uso explícito de parámetros que son apuntadores a las variables que donde se guardará la solución. Dentro de la función dichos parámetros siempre se usarán anteponiendo el operador monario ```*```.

En el segundo, se utiliza el operador monario ```&``` al momento de declarar los parámetros de la función que corresponden a parámetros por referencia.

# Contenido

* ```eq2doGrado01.c```: Variante en ```C``` del programa de ejemplo.
* ```eq2doGrado02.cpp```: Variante en ```C++``` del programa de ejemplo.
* ```Makefile```: Archivo que permite automatizar el proceso de compilación de los programas.
* ```LEEME.md```: Este archivo.
