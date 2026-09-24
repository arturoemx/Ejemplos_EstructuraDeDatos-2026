#ifndef __PILA__
#define __PILA__

#include "arreglo.h"

template <typename X>
struct pila
{
	arreglo<X> P;
	uint sp;

	pila(uint n)
	{
		P.asignaMemoria(n);
		sp =0;
	}
	int push(X val)
	{
		if (sp < P.n)
		{
			P[sp] = val;
			sp++;
			return 0; //Regresamos 0 si la operacion tuvo exito.
		}
		else
			return -1; //Regresamos -1 si la operacion no tuvo exito.
	}
	int pop(X &val)
	{
		if (sp > 0)
		{
			sp--;
			val = P[sp];
			return 0; //Regresamos 0 si la operacion tuvo exito.
		}
		else
			return -1; //Regresamos -1 si no tuvo exito;
	}
};


template <typename X>
ostream &operator<<(ostream &os, pila<X> &P)
{
	os << "[ sp = " << P.sp << " | "<< P.P << "]";
	return os;
}


#endif
