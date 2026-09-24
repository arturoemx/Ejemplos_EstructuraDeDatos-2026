#ifndef __COLA__
#define __COLA__

#include "arreglo.h"

template <typename X>
struct cola
{
	arreglo<X> C;
	uint T; //Final de la cola (Tail).
	uint H; //Cabeza de la cola (Head)


	cola(uint n)
	{
		C.asignaMemoria(n);
		T = H = 0;
	}

	//Mete el valor val al inicio de la cola
	//Si la cola esta llena regresa -1
	//Si no, regresa 0. 
	int enqueue(X val)
	{
		if ((T+1) % C.n != H)
		{
			C[T] = val;
			T = (T+1) % C.n;
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
		if (T!=H)
		{
			val = C[H];
			H =(H+1) % C.n;
			return 0; 
		}
		else
			return -1;
	}
};

template <typename X>
ostream &operator<<(ostream &os, cola<X> &cl)
{
	uint i;

	os << "[ H = " << cl.H << ", T = " << cl.T << " | {";
	for (i = 0; i < cl.C.n-1; ++ i)
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
	if (cl.C.n > 0)
		os << cl.C[i];
	os << "}]";
	return os;
}


#endif
