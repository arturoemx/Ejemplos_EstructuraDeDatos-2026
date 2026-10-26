#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char A[8], *pa;
	int  B[8], *pb;
	long long int C[8], *pc;
	long double D[8], *pd;
	int i;

	printf("\nDefinimos cuatro arreglos diferentes:\n\n");
	printf("  * A: un arreglo que almacena 8 variables tipo char.\n\n");
	printf("  * B: un arreglo que almacena 8 variables tipo int.\n\n");
	printf("  * C: un arreglo que almacena 8 variables tipo long long int.\n\n");
	printf("  * D: un arreglo que almacena 8 variables tipo long double.\n\n\n");


	printf("Para almacenar una variable tipo 'char' requerimos %lu bytes.\n\n",sizeof(char));
	printf("Para almacenar una variable tipo 'int' requerimos %lu bytes.\n\n",sizeof(int));
	printf("Para almacenar una variable tipo 'long long int' requerimos %lu bytes.\n\n",sizeof(long long int));
	printf("Para almacenar una variable tipo 'long double' requerimos %lu bytes.\n\n\n",sizeof(long double));

	
	printf("Llenamos los tres primeros arreglos con multiplos de 10: 10, 20, ..., 70, 80\n\n");
	printf("El cuarto arreglo, el que contiene variables tipos long double lo llenamos\n");
	printf("con potencias de dos en el intervalo [3, -4]: 8, 4, 2, 1, 0.5, 0.25, 0.125, 0.0625]\n\n");

	for (i=0; i<8;++i)
	{
		A[i] = (i+1)*10;
		B[i] = (i+1)*10;
		C[i] = (i+1)*10;
		D[i] = pow(2,3-i);
	}

	printf("pa, pb, pc y pd son apuntadores a cada unos de los arreglos A, B, C y D\n\n");
	printf("Tras inicializar cada apuntador con la dirección de cada uno de los arreglos\n");
	printf("esto es, pa = A, pb = B, y así, en un ciclo imprimiremos cada apuntador así como al valor\n");
	printf("al que hacen referencia, incrementando cada apuntador en cada iteración del ciclo.\n\n");
	
	pa = A;
	pb = B;
	pc = C;
	pd = D;

	for (i=0; i<8; ++i, ++pa, ++pb, ++pc, ++pd)
	{
		printf("Ciclo #%d\n", i);
		printf("pa = %p, *pa = %d\n", pa, *pa);
		printf("pb = %p, *pb = %d\n", pb, *pb);
		printf("pc = %p, *pc = %lld\n", pc, *pc);
		printf("pd = %p, *pd = %Lf\n\n", pd, *pd);
		printf("Incrementamos los apuntadores pa, pb, pc y pd.\n\n");
	}
	printf("\n\n   PREGUNTAS:\n\n");
	printf("\n\t¿Que tanto crece el apuntado pa al  irse incrementando?\n");
	printf("\n\t¿y que tanto los apuntadores pb, pc y pd?\n");
	printf("\n\t¿Como se explica esa variación de acuerdo al tipo de apuntador?\n");
	printf("\n\tEl contenido al que apunta cada apuntador, ¿corresponde con la forma en que lo inicializamos?\n\n");

	return 0;
}