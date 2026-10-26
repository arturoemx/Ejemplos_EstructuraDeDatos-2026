#include <stdio.h>
#include <stdlib.h>

union multiType
{
	unsigned char e[16];
	unsigned int E[4];
	unsigned long long int L[2];
	
};

int main()
{
	int i;
	union multiType Q;


	//Imprimimos el número de bytes que se requieren para almacenar diferentes tipos de datos.
	printf ("\nEl tamaño de una variable tipo char es de %lu bytes\n", sizeof(char));
	printf ("El tamaño de una variable tipo int es de %lu bytes\n", sizeof(int));
	printf ("El tamaño de una variable tipo long long int es de %lu bytes\n", sizeof(long long unsigned int));
	printf ("El tamaño de una variable tipo long double es de %lu bytes\n", sizeof(long double));
	printf ("\nEl tamaño de una variable tipo apuntador a char es de %lu bytes\n", sizeof(char *));
	printf ("El tamaño de una variable tipo apuntador a int es de %lu bytes\n", sizeof(int *));
	printf ("El tamaño de una variable tipo apuntador a long long int es de %lu bytes\n", sizeof(long long int *));
	printf ("El tamaño de una variable tipo apuntador a long double es de %lu bytes\n\n", sizeof(long double *));

	printf("multiType es una variable tipo 'union', que de manera similar una estructura contiene\n");
	printf("varios atributos. A diferencia de la estructura, donde cada atributo corresponde a una\n");
	printf("variable con un espacio de memoria exclusivo, en una unión todos los atributos comparten\n");
	printf("el mismo espacio de memoria, y el tamaño de la unión es el del atributo más grande en la\n");
	printf("en la unión.\n\nLa unión multiType se define como sigue:\n\n");
	printf("   union multiType\n   {\n      unsigned char e[16];\n      unsigned int E[4];\n");
	printf("      unsigned long long int L[2];\n   };\n\n");
	printf("Los tres atributos o miembros de la unión ocupan el mismo espacio de memoria\n");
	printf("Cada uno de ellos es un arreglo y el tamaño de cada arreglo en número de bytes es el mismo\n");
	printf("(lo cual no necesariamente tiene que ser así).\n\n");
	
	printf ("El tamaño de una variable tipo multiType es de %lu bytes\n\n", sizeof(union multiType));

	printf("Q es una variable de tipo union multiType. Llenamos el arreglo Q.e con los primeros\n");
	printf("16 múltiplos de 16: 0, 16, 32, 48, . . . , 234, 240\n\n");
	printf("En hexadecimal estós números son: 0x00, 0x10, 0x20, 0x30, ... 0xE0, 0xF0\n\n");

	//Llenamos el arreglo Q.e con múltiplos de 16: 0, 16, 32, 48, ... , 234, 240
	//En hexadecimal estós números son: 0x00, 0x10, 0x20, 0x30, ... 0xE0, 0xF0
	for (i=0;i<16;++i)
		Q.e[i]  = i * 16;

	// Imprimimos el contenido de Q a través del componente e.
	for (i=0;i<16;++i)
		printf("Q.e[%02d]\t= 0x%02X,\t\t\t &(Q.e[%02d]) = %p\n", i, Q.e[i], i, &(Q.e[i]));
	printf("\n");

	// Imprimimos el contenido de Q a través del componente E. Como E y e comparten
	// memoria: lo que se imprimirá sera los mísmos digitos de Q.e pero agrupándolos de
	// variables de 4 bytes.
	for (i=0;i<4;++i)
		printf("Q.E[%02d]\t= 0x%08X,\t\t &(Q.E[%02d]) = %p\n", i, Q.E[i], i, &(Q.E[i]));
	printf("\n");

	// Imprimimos el contenido de Q a través del componente L. Como L y e comparten
	// memoria: lo que se imprimirá sera los mísmos digitos de Q.e pero agrupándolos de
	// variables de 8 bytes.
	for (i=0;i<2;++i)
		printf("Q.L[%02d]\t= 0x%016llX,\t &(Q.L[%02d])  = %p\n", i, Q.L[i], i, &Q.L[i]);
	printf("\n\n");

	return 0;
}