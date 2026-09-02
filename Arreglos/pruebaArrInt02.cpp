#include <iostream>
#include <math.h>
#include "arrInt.h"

using namespace std;

int main(int argc, char **argv)
{
	uint tama, i;

	if (argc > 1)
		tama = (uint)atoi(argv[1]);
	else
		tama = 10;

	arrInt A(tama);

	for (i=0;i<A.n;++i)
		A.data[i] = 5 * pow(i,2) + 3*i - 12;

	cout << endl << "El arreglo contiene los siguientes valores ";
	A.imprime();
	cout << endl << endl;

	cout << "La suma de los elementos del arreglo es igual a " << A.suma() << endl << endl;
	cout << "El promedio de los elementos del arreglo es igual a " << A.promedio() << endl << endl;
	cout << "La varianza de los elementos del arreglo es igual a " << A.varianza() << endl << endl;
	return 0;
}