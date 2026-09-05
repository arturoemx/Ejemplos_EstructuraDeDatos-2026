#include <iostream>
#include <math.h>
#include "arreglo.h"

using namespace std;

int main(int argc, char **argv)
{
	uint tama;
	int i;
	int minI, maxI;
	double minD, maxD;

	if (argc > 1)
		tama = (uint)atoi(argv[1]);
	else
		tama = 10;

	arreglo<int> AI(tama);
	arreglo<double> AD(tama);

	for (i=-3;i<(int)AI.n+3;++i)
		AI[i] = pow(i,2) - 14 * i + 49;

	for (i=-4;i<(int)AD.n+3;++i)
		AD[i] = pow(i,2) - 10 * i + 18.75;

	cout << endl << "El arreglo de enteros contiene los siguientes valores:" << endl << endl;
	cout << AI << endl << endl;

	AI.min_max(minI, maxI);

	cout << "El valor mínimo en el arreglo de enteros es " << minI << endl << endl;
	cout << "El valor máximo en el arreglo de enteros es " << maxI << endl << endl;

	cout << "La suma de los elementos del arreglo es igual a " << AI.suma() << endl << endl;
	cout << "El promedio de los elementos del arreglo es igual a " << AI.promedio() << endl << endl;
	cout << "La varianza de los elementos del arreglo es igual a " << AI.varianza() << endl << endl;

	cout << endl << "------------------------------------------------------------------------------" 
	     << endl << endl;

	cout << endl << "El arreglo de doubles contiene los siguientes valores:" << endl << endl;
	
	cout << AD << endl << endl;

	AD.min_max(minD, maxD);

	cout << "El valor mínimo en el arreglo de doubles es " << minD << endl << endl;
	cout << "El valor máximo en el arreglo de doubles es " << maxD << endl << endl;

	cout << "La suma de los elementos del arreglo es igual a " << AD.suma() << endl << endl << endl;
	cout << "El promedio de los elementos del arreglo es igual a " << AD.promedio() << endl << endl;
	cout << "La varianza de los elementos del arreglo es igual a " << AD.varianza() << endl << endl;

	return 0;
}