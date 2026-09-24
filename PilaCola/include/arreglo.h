#ifndef __ARREGLO__
#define __ARREGLO__

#include <iostream>
#include <cstring>

using namespace std;

template <typename E>
struct arreglo
{
	E *data;
	uint n;

	// constructor por defecto.
	arreglo()
	{
		data = nullptr;
		n = 0;
	}

	// Constructor que inicializa un arreglo de
	// _n objetos de tipo E.
	arreglo(uint _n)
	{
		data = nullptr;
		n = 0;
		asignaMemoria(_n);
	}

	// Constructor de copia.
	arreglo(arreglo &b)
	{
		data = nullptr;
		n = 0;
		*this = b;
	}

	// Destructor del objeto: libera la memoria.
	~arreglo()
	{
		if (data != nullptr)
			delete[] data;
	}

	// Sobrecarga del operador de asignación.
	arreglo &operator= (const arreglo &b)
	{
		asignaMemoria(b.n);
		memcpy (data, b.data, n * sizeof(E));//Esta función depende de la biblioteca cstring
		return *this;
	}

	// Esta función asigna memoría al arreglo.
	// Si el objeto tiene memoria asociada y su tamaño es
	// diferente al nuevo tamaño de memoria (_n), esta se libera
	// y se obtiene un nuevo tamaño de memoria.
	void asignaMemoria(uint _n)
	{
		if (n == _n)
			return;

		//Si el objeto no está vacio, libera la memoria.
		if (n > 0)
		{
			delete[] data;
			n = 0;
			data = nullptr;
		}
			
		if (_n > 0) //Si _n > 0, obten memoria para el arreglo.
		{
			data = new E[_n];
			if (data == nullptr)
			{
				cerr << "Error en operador de asignación: no se pudo obtener memoria" << endl;
				cerr.flush();
				exit(1);
			}
			else
				n = _n;
		}
	}

	// Regresa la sumatoria de todos los elementos del arreglo.
	float suma()
	{
		float acum = 0;
		uint i;

		for (i=0;i<n;++i)
			acum += data[i];
		return acum;
	}

	// Regresa el promedio de todos los elementos del arreglo.
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

	// Regresa la varianza de todos los elementos del arreglo.
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

	// Sobrecarga del operador [].
	// Permite acceder a los elementos del arreglo sin necesidad de acceder
	// directamente al atributo data.
	// Además, como en este ejemplo, permite validar que el índice esté dentro
	// de los límites del arreglo.
	E &operator[](int idx)
	{
		if (idx < 0 || idx >= (int)n)
		{
			cerr << "Error en el operador [] en arreglo: indice fuera de límite;" << endl;
			return data[0];
		}
		return data[idx];
	}

	// Funcion que imprime el contenido del arreglo.
	void imprime()
	{
		uint i;

		cout << "{";
		if (n > 0)
		{
			for (i = 0; i < n-1; ++i)
				cout << data[i] << ", ";
			cout << data[i] << "}";
		}
		else
			cout << "}";
	}
};

// Sobrecarga del operador '<<' para arreglos.
// Se declara afuera de la estructura arreglo pues el operador
// '<<' es un operador de la clase ostream. la función de sobrecarga
// recibe dos parámetros:
//
// os : el objeto asociado a un flujo de salida pasado por referencia
//      en donde vamos a escribir el arreglo.
// a  : el objeto de tipo arreglo cuyo contenido vamos a escribir en os.
template <typename X>
ostream &operator<<(ostream &os, arreglo<X> &a)
{
	uint i;

	os << "{";
	if (a.n > 0)
	{
		for (i = 0; i < a.n-1; ++i)
			os << a.data[i] << ", ";
		os << a.data[i] << "}";
	}
	else
		os << "}";
	return os;
}

#endif