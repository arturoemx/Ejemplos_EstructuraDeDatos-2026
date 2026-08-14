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

	imprimeArregloInt(A, n, string("A"));
	cout << endl << "---------------------"<< endl;
	
	/* Escribe un fragmento de código que invierta el orden de los elementos de la matriz A*/


	cout << endl << "---------------------"<< endl;
	imprimeArregloInt(A, n, string("A"));
	

	

	return 0;
}