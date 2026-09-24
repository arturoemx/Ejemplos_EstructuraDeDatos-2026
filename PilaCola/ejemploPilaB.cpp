#include <iostream>
#include "PilaB.h"

using namespace std;

int main(int argc, char **argv)
{
	uint i;
	uint tama, tama2;

	if (argc > 1)
		tama = stoi(argv[1]);
	else
		tama = 10;

	pilaB<int> P(tama);

	tama2 = tama / 2;

	cout << endl << "Asi luce la pila ahora: " << P << endl << endl;

	for (i = 0; i < tama2; ++i)
	{
		int val;

		val = (i+1)*2+5;
		if (P.push(val) == 0)
			cout << "Metemos el valor " << val << " a la pila."<< endl;
		else
			cerr << "ERROR: pila llena." << endl;
	}

	cout << endl << "Asi luce la pila cuando está medio llena: " << P << endl << endl;

	for (; i < tama + 2; ++i)
	{
		int val;

		val = (i+1)*2+5;
		if (P.push(val) == 0)
			cout << "Metemos el valor " << val << " a la pila."<< endl;
		else
			cerr << "ERROR: pila llena." << endl;
	}

	cout << endl << "Asi luce la pila cuando está llena: " << P << endl << endl;

	for (i = 0; i < tama + 2; ++i)
	{
		int val;

		if (P.pop(val) == 0)
			cout << "Sacamos el valor " << val << " de la pila."<< endl;
		else
			cerr << "ERROR: pila vacia." << endl;
	}

	cout << endl << "Asi luce la pila al final, cuando está vacia: " << P << endl << endl;
	

	return 0;
}