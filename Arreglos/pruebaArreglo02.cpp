#include <iostream>
#include <math.h>
#include "arreglo.h"

using namespace std;

int main(int argc, char **argv)
{
	uint tama;
	int i;

	if (argc > 1)
		tama = (uint)atoi(argv[1]);
	else
		tama = 10;

	arreglo<int> A(tama), B;

	for (i=-3;i<(int)A.n+3;++i)
		A[i] = pow(i,2) - 14 * i + 49;

	cout << endl << "El arreglo A = " << A << endl << endl;
	cout <<  "El arreglo B = " << B << endl << endl;

	cout << "Copiamos el arreglo A en el arreglo B..." << endl << endl;

	B = A;

	cout <<  "El arreglo ahora luce así B = " << B << endl << endl;


	// Para probar el constructor de copia.
	// el arreglo C, se debe inicializa con el contenido del arreglo A
	arreglo<int> C(A);

	cout << "Declaramos un arreglo C, pasando como referencia el arreglo A para probar" 
	     << endl << "el constructor de copia." << endl << endl;

	cout << endl << "El arreglo C = " << C << endl << endl;
	
	return 0;
}