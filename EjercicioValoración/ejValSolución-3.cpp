#include <iostream>
#include <string>

using namespace std;

void imprimeArregloInt(int *A, int n, string varName)
{
	int i;

	cout << varName << "[";
	for (i = 0; i < n-1; ++i)
		cout << A[i] << ", ";
	cout << A[i] << "]" << endl;
}

int main()
{
	int i, j, n = 20;
	int A[n];

	for (i = 0; i < n; ++i)
	{
		int val;

		val = lrand48() % 100;
		A[i] = val;
	}

	cout << endl;
	cout << "Se definió un arreglo \"A\" que contiene " << n << " elementos." << endl << endl;
	imprimeArregloInt(A, n, string("A"));
	
	/* Escribe un fragmento de código que invierta el orden de los elementos de la matriz A*/

	// AQUI VA SU CÓDIGO.	

	// Solucion básica II

	int tmp, m = n/2;
	for (i = 0, j = n-1; i < m; ++i, --j)
	{
		//Swap utilizando XOR
		A[i] = A[i] ^ A[j];
		A[j] = A[j] ^ A[i];
		A[i] = A[i] ^ A[j];
	}

	cout << endl << "---------------------"<< endl << endl;
	imprimeArregloInt(A, n, string("A"));
	cout << endl;	

	return 0;
}