#ifndef __ARREGLO__
#define __ARREGLO__

#include <iostream>

using namespace std;

template <typename E>
struct arreglo
{
	E *data;
	uint n;

	arreglo(uint _n)
	{
		if (_n != 0)
		{
			data = new E[_n];
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

	~arreglo()
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

	// Esta función encuentra los valores minimo y maximo de un arreglo
	// los cuales regresa en los parametros m y M respectivamente que se
	// pasaron por referencia.
	//
	// atributos de clase:
	// n -> tamaño del arreglo
	// data -> el arreglo
	void min_max(E &m, E &M)
	{
		if (n > 0)
		{
			uint i;

			m = M = data[0];
			for (i = 1; i < n; ++i)
				if (data[i] < m)
					m = data[i];
				else if (data[i] > M)
					M = data[i];	
		}
		else
			m = M = 0;
	}

	E &operator[](int idx)
	{
		if (idx < 0 || idx >= (int)n)
		{
			cerr << "Error en el operador [] en arreglo: indice fuera de límite;" << endl;
			return data[0];
		}
		return data[idx];
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

template <typename X>
ostream &operator<<(ostream &os, arreglo<X> &a)
{
	uint i;

	os << "{";
	if (a.n > 0)
	{
		for (i = 0; i < a.n-1; ++i)
			os << a.data[i] << ", ";
		os << a.data[i] << "}" << endl;
	}
	else
		os << "}" << endl;
	return os;
}

#endif