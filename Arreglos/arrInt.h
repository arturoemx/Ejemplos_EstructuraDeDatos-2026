#ifndef __ARRINT__
#define __ARRINT__

#include <iostream>

using namespace std;

struct arrInt
{
	int *data;
	uint n;

	arrInt(uint _n)
	{
		if (_n != 0)
		{
			data = new int[_n];
			if (data == nullptr)
				n = 0;
			else
				n = _n;
		}
		else
		{
			n = 0;
			data = nullptr;
		}
	}

	~arrInt()
	{
		if (data != nullptr)
			delete[] data;
	}

	float suma()
	{
		float acum = 0;
		uint i;

		for (i=0;i<n;++i)
			acum += data[i];
		return acum;
	}

	float promedio()
	{
		if (n > 0)
			return suma() / n;
		else
		{
			cerr << "Error en arrInt.promedio: el tamaño del arreglo debe ser mayor que 0."
			     << endl;
			return 0;
		}
	}

	float varianza()
	{
		if (n > 1)
		{
			float pm, acum = 0;
			uint i;

			pm = promedio();
			for (i=0;i<n;++i)
				acum += pow(data[i]-pm,2);
			return acum / (n-1);
		}
		else
		{
			cerr << "Error en arrInt.varianza: el tamaño del arreglo debe ser mayor que 1."
			     << endl;
			return 0;
		}
	}

	void imprime()
	{
		uint i;

		cout << "{";
		if (n > 0)
		{
			for (i = 0; i < n-1; ++i)
				cout << data[i] << ", ";
			cout << data[i] << "}" << endl;
		}
		else
			cout << "}" << endl;
	}
};

#endif