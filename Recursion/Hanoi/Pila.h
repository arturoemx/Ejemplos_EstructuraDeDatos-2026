#ifndef __PILA__
#define __PILA__

#include <iostream>

template <typename X>
struct Pila
{
	int N, SP;
	X *P;

	Pila(int n)
	{
		N=SP=0;
		P=0;
		if (n>0)
		{
			P = new X[n];
			if (P != 0)
				N = n;
		}
	}
	~Pila()
	{
		if (P) // 'if (P)' es equivalente a 'if (P != 0)'
			delete[] P;
	}
	void push(const X &val)
	{
		if (SP < N)
		{
			P[SP] = val;
			SP++;
		}
		else
			std::cerr << "Error: Pila llena" << std::endl;
 	}
 	X pop()
	{
		if (SP > 0)
			return P[--SP];
		else
		{
			X val;

			std::cerr << "Error: Pila vacia" << std::endl;
			return val;
		}
 	}
 	bool vacia()
 	{
 		if (SP == 0)
 			return true;
 		return false;
 	}
 	bool llena()
 	{
 		if (SP >= N)
 			return true;
 		return false;
 	}
 	Pila<X> operator= (Pila<X> &C)
 	{
 		if (P != 0)
 		{
 			delete[] P;
 			SP=N=0;
  		}
  		if (C.N > 0)
  		{
  			P = new X[C.N];
  			if (P)
  			{
  				N = C.N;
  				SP = C.SP;
  				for (int i=0;i<N;++i)
  					P[i] = C.P[i];
  			}
  			else
  			{
  				std::cerr << "Pila:No se pudo obtener memoria en operador de asignación."
  				          << std::endl;
  				N = SP = 0;
  			}
  		}
  	}
};

#endif