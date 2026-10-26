#ifndef __ARREGLO__
#define __ARREGLO__

#include <iostream>
#include <cstring>

using namespace std;

template <typename E>
struct arregloIdx
{
	E *data;
	uint *index;
	uint n;

	// constructor por defecto.
	arregloIdx()
	{
		data = nullptr;
		index = nullptr;
		n = 0;
	}

	// Constructor que inicializa un arreglo de
	// _n objetos de tipo E.
	arregloIdx(uint _n)
	{
		data = nullptr;
		index = nullptr;
		n = 0;
		asignaMemoria(_n);
	}

	// Constructor de copia.
	arregloIdx(arregloIdx &b)
	{
		data = nullptr;
		index = nullptr;
		n = 0;
		*this = b;
	}

	// Destructor del objeto: libera la memoria.
	~arregloIdx()
	{
		if (data != nullptr)
		{
			delete[] data;
			delete[] index;
		}
	}

	// Sobrecarga del operador de asignación.
	arregloIdx &operator= (const arregloIdx &b)
	{
		asignaMemoria(b.n);
		memcpy (data, b.data, n * sizeof(E));//Esta función depende de la biblioteca cstring
		memcpy (index, b.index, n * sizeof(uint));
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
			delete[] index;
			n = 0;
			data = nullptr;
			index = nullptr;
		}
			
		if (_n > 0) //Si _n > 0, obten memoria para el arreglo.
		{
			data = new E[_n];
			index = new uint[_n];
			if (data == nullptr || index == nullptr)
			{
				cerr << "Error en operador de asignación: no se pudo obtener memoria" << endl;
				cerr.flush();
				exit(1);
			}
			else
			{
				n = _n;
				for (uint i=0; i < n;++i)
					index[i] = i;
			}
		}
	}

	// Regresa la sumatoria de todos los elementos del arreglo.
	float suma()
	{
		float acum = 0;
		uint i;

		for (i=0;i<n;++i)
			acum += data[index[i]];
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
				acum += pow(data[index[i]]-pm,2);
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
				if (data[index[i]] < m)
					m = data[index[i]];
				else if (data[index[i]] > M)
					M = data[index[i]];	
		}
		else
			m = M = 0;
	}

	void swap(int i, int j)
	{
		if (i < 0 || i >= n || j < 0 || j >= n)
		{
			cerr << "Error en arreglo;:swap. Indices fuera del rango válido."
			     << endl;
			return;
		}
		else
		{
			uint tmp;

			tmp = index[i];
			index[i] = index[j];
			index[j] = tmp;
		}
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
			cerr << "Error en el operador [] en arreglo: indice "
			     << idx << " fuera de límite;" << endl;
			return data[index[0]];
		}
		return data[index[idx]];
	}

	// Funcion que imprime el contenido del arreglo.
	void imprime()
	{
		uint i;

		cout << "{";
		if (n > 0)
		{
			for (i = 0; i < n-1; ++i)
				cout << data[index[i]] << ", ";
			cout << data[index[i]] << "}" << endl;
		}
		else
			cout << "}" << endl;
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
ostream &operator<<(ostream &os, arregloIdx<X> &a)
{
	uint i;

	os << "{";
	if (a.n > 0)
	{
		for (i = 0; i < a.n-1; ++i)
			os << a.data[a.index[i]] << ", ";
		os << a.data[a.index[i]] << "}" << endl;
	}
	else
		os << "}" << endl;
	return os;
}

#endif