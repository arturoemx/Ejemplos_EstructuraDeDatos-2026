#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

int main()
{
	lista<int> L, M;
	uint i, n=10;

	cout << endl;
	for (i = 0; i<n; ++i)
	{
		int val;

		val = rand() % 1000;
		cout << "Metemos el valor " <<  val  << " la lista." << endl;
		L.pushBack(val);
		cout << "La lista 'L' luce asi:" << L << endl;
	}
	cout << endl;

	cout << "La lista 'L' luce asi: " << endl << L << endl;

	M.copia(L);

	cout << "La lista 'M' luce asi: " << endl << M << endl;

	cout << endl;

	return 0;
}