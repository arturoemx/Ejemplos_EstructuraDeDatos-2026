#include <iostream>

using namespace std;

int main()
{
	cout << "El tamaño de una variable tipo bool          es " 
		 << sizeof(bool) << " bytes." << endl;

	cout << "El tamaño de una variable tipo char          es " 
	     << sizeof(char) << " bytes." << endl;

	cout << "El tamaño de una variable tipo short         es "
	     << sizeof(short) << " bytes." << endl;

	cout << "El tamaño de una variable tipo int           es "
	     << sizeof(int) << " bytes." << endl;

	cout << "El tamaño de una variable tipo long int      es "
	     << sizeof(long int) << " bytes." << endl;

	cout << "El tamaño de una variable tipo long long int es "
	     << sizeof(long long int) << " bytes." << endl;

	cout << "El tamaño de una variable tipo float         es "
	     << sizeof(float) << " bytes." << endl;

	cout << "El tamaño de una variable tipo double        es "
	     << sizeof(double) << " bytes." << endl;

	cout << "El tamaño de una variable tipo long double   es "
	     << sizeof(long double) << " bytes." << endl;

	return 0;
}