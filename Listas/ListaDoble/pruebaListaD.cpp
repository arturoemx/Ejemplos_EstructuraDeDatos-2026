#include <iostream>
#include <cstdlib>
#include "listaD.h"

using namespace std;

int main()
{
	listaD<int> L, M;
	uint i, n=10;

	cout << endl;
	for (i = 0; i<n; ++i)
	{
		int val;

		val = rand() % 1000;
		cout << "Metemos el valor " <<  val  << " al inicio la lista L" << endl;
		L.pushFront(val);
		cout << "La lista 'L' luce asi:" << L << endl;
		cout << "El último elemento de la lista L es " << L.final->dato << endl << endl;

		cout << "Metemos el valor " <<  val  << " al final de la lista M" << endl;
		M.pushBack(val);
		cout << "La lista 'M' luce asi:" << M << endl;
		cout << "El último elemento de la lista M es " << M.final->dato << endl << endl;
	}
	cout << endl;

	cout << "La lista 'L' luce asi: " << endl << L << endl;
    cout << "El último elemento de la lista 'L' es " << L.final->dato << endl;
	cout << endl;

	cout << "La lista 'M' luce asi: " << endl << M << endl;
    cout << "El último elemento de la lista 'M' es " << M.final->dato << endl;
	cout << endl;

	return 0;
}