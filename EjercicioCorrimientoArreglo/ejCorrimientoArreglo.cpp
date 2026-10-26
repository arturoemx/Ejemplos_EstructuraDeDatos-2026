#include <iostream>
#include <cstring>

using namespace std;

void imprimeArregloInt(int *A, int n, string varName)
{
	int i;

	cout << varName << "[";
	for (i = 0; i < n-1; ++i)
		cout << A[i] << ", ";
	cout << A[i] << "]" << endl;
}

// En clase hicimos un ejercicio cuto


int main()
{
	int A[5] = {7, -1, 6, 3, 4}, B[5]={7, -1, 6, 3, 4};
	int Aux, i, j;

	cout << "Este es un ejercicio que vimos en clase." << endl << endl
	     << "El objetivo es implementar un algoritmo que corra a la derecha "
	     << " todos los elementos del arreglo." << endl << endl
	     << "esto es, si A es el arreglo con n elementos, queremo que el valor del"
	     << " elemento A[i]  se asigne al elemento A[i+i] para i en [0,n-2]." << endl
	     << "El último elemento, (A[n-1]) se deberá asignar al primero (A[0])."
	     << endl << endl;


	cout << endl << "Este es el arreglo original:" << endl;
	imprimeArregloInt(A, 5, "A");
	cout << endl << endl;

	// Solucion Victor
	for (i=0;i<4;i++)
	{
		Aux=A[i];
		A[i]=A[4];
		A[4]=Aux;
	}
	cout << endl << "Este es la solución de Victor:" << endl;
	imprimeArregloInt(A, 5, "A");
	cout << endl << endl;
    
    //Restauramos el arreglo A a sus valores iniciales.
    memcpy(A,B,5*sizeof(int));
    
    //Solucion en clase 1
    A[0] = 4; A[1]=7; A[2]=-1; A[3]=6; A[4]=3;
	cout << "Solución en clase 1:" << endl;
	imprimeArregloInt(A, 5, "A");
	cout << endl << endl;

	//Restauramos el arreglo A a sus valores iniciales.
    memcpy(A,B,5*sizeof(int));

    //Solucion en clase 2
    Aux = A[4];
    for (i=3;i>=0;--i)
    	A[i+1] = A[i];
    A[0] = Aux;
	cout << "Solución en clase 2:" << endl;
	imprimeArregloInt(A, 5, "A");
	cout << endl << endl;

	//Restauramos el arreglo A a sus valores iniciales.
    memcpy(A,B,5*sizeof(int));

	//Solucion en clase 3
    Aux = A[4];
    for (i=3, j = 4; i >= 0;--i, --j)
    	A[j] = A[i];
    A[0] = Aux;
	cout << "Solución en clase 3:" << endl;
	imprimeArregloInt(A, 5, "A");
	cout << endl << endl;

	//Restauramos el arreglo A a sus valores iniciales.
    memcpy(A,B,5*sizeof(int));

    //Solucion de Cabra
    Aux = A[4];
    for (i=4;i>0;--i)
    	A[i] = A[i-1];
    A[0] = Aux;
    cout << endl << "Este es la solución de Cabra:" << endl;
	imprimeArregloInt(A, 5, "A");
	cout << endl << endl;

	return 0;
}