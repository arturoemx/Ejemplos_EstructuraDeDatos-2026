#ifndef __PILAB__
#define __PILAB__

#include <iostream>

template <typename X>
struct pilaB
{
	X *P;
	uint n;
	uint sp;

	pilaB(uint _n)
	{
		if (_n > 0)
		{
			P = new X[_n];
			if (!P)
			{
				std::cerr << "Error en constructor pilaB: no se pudo obtener memoria." << std::endl;
				std::cerr.flush();
				exit(1);
			}
			n = _n;
		}
		else
			n = 0;
		sp =0;
	}
	~pilaB()
	{
		if (P != nullptr)
			delete[] P;
	}
	int push(X val)
	{
		if (sp < n)
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
std::ostream &operator<<(std::ostream &os, pilaB<X> &P)
{
	os << "[ sp = " << P.sp << " | ";
	os << "{";
	if (P.n > 0)
	{
		uint i;

		for (i = 0; i < P.n-1; ++i)
			os << P.P[i] << ", ";
		os << P.P[i] << "}]";
	}
	else
		os << "}";
	return os;
}


#endif
