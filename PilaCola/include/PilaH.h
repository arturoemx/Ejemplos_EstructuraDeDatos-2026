#ifndef __PILAH__
#define __PILAH__

#include "arreglo.h"

template <typename X>
struct pilaH:public arreglo<X>
{
	uint sp;

	pilaH(uint _n):arreglo<X>(_n)
	{
		sp =0;
	}
	int push(X val)
	{
		if (sp < arreglo<X>::n)
		{
			arreglo<X>::data[sp] = val;
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
			val = arreglo<X>::data[sp];
			return 0; //Regresamos 0 si la operacion tuvo exito.
		}
		else
			return -1; //Regresamos -1 si no tuvo exito;
	}
};

template <typename X>
ostream &operator<<(ostream &os, pilaH<X> &P)
{
	arreglo<X> *ptr = (arreglo<X> *)&P;
	os << "[ sp = " << P.sp << " | "<< *ptr << "]";
	return os;
}

#endif