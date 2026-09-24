#ifndef __COLA_ALT__
#define __COLA_ALT__

#include "arreglo.h"

template <typename X>
struct colaAlt
{
	arreglo<X> C;
	uint T; //Final de la cola (Tail).
	uint H; //Cabeza de la cola (Head)
	uint cuantos; // Cuantos elementos hay en la cola


	colaAlt(uint n)
	{
		C.asignaMemoria(n);
		T = H = 0;
		cuantos = 0;
	}

	//Mete el valor val al inicio de la cola
	//Si la cola esta llena regresa -1
	//Si no, regresa 0. 
	int enqueue(X val)
	{
		if (cuantos < C.n)
		{
			C[T] = val;
			T = (T+1) % C.n;
			cuantos++;
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
		if (cuantos > 0)
		{
			val = C[H];
			H =(H+1) % C.n;
			cuantos--;
			return 0; 
		}
		else
			return -1;
	}
};

template <typename X>
ostream &operator<<(ostream &os, colaAlt<X> &cl)
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
