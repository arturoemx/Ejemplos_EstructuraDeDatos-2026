#ifndef __COLAH__
#define __COLAH__

#include "arreglo.h"

template <typename X>
struct colaH:public arreglo<X>
{
	uint H, T;

	colaH(uint _n):arreglo<X>(_n)
	{
		H = T = 0;
	}
	//Mete el valor val al inicio de la cola
	//Si la cola esta llena regresa -1
	//Si no, regresa 0. 
	int enqueue(X val)
	{
		if ((T+1) % arreglo<X>::n != H)
		{
			arreglo<X>::data[T] = val;
			T = (T+1) % arreglo<X>::n;
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
			val = arreglo<X>::data[H];
			H =(H+1) % arreglo<X>::n;
			return 0; 
		}
		else
			return -1;
	}
};

template <typename X>
ostream &operator<<(ostream &os, colaH<X> &cl)
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
		os << cl[i] << ", ";
	}
	if (cl.n > 0)
		os << cl[i];
	os << "}]";
	return os;
}

#endif