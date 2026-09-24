#ifndef __COLA_B__
#define __COLA_B__

#include "arreglo.h"

template <typename X>
struct colaB
{
	X *C;
	uint n;
	uint H, T;

	colaB(uint _n)
	{
		if (_n > 0)
		{
			C = new X[_n];
			if (!C)
			{
				std::cerr << "Error en constructor pilaB: no se pudo obtener memoria." << std::endl;
				std::cerr.flush();
				exit(1);
			}
			n = _n;
		}
		else
			n = 0;
		H = T = 0;
	}
	~colaB()
	{
		if (C != nullptr)
			delete[] C;
	}
	//Mete el valor val al inicio de la cola
	//Si la cola esta llena regresa -1
	//Si no, regresa 0. 
	int enqueue(X val)
	{
		if ((T+1) % n != H)
		{
			C[T] = val;
			T = (T+1) % n;
			return 0;
		}
		else
			return -1;
	}
	//Saca a traves del parametro val lo que está al final de la cola.
	//Si la cola esta vacia regresa -1
	//Si no, regresa 0.
	int dequeue(X &val)
	{
		if (T != H)
		{
			val = C[H];
			H =(H+1) % n;
			return 0; 
		}
		else
			return -1;
	}
};

template <typename X>
ostream &operator<<(ostream &os, colaB<X> &cl)
{
	uint i;

	os << "[ H = " << cl.H << ", T = " << cl.T << " | {";
	for (i = 0; i < cl.n-1; ++ i)
	{
		if (i == cl.H || i == cl.T)
		{
			if (i == cl.H)
				os << "H";
			if (i == cl.T)
				os << "T";
			os << ":";
		}
		os << cl.C[i] << ", ";
	}
	if (cl.n > 0)
		os << cl.C[i];
	os << "}]";
	return os;
}
#endif