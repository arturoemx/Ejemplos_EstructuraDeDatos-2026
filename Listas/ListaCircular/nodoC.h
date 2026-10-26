#ifndef __NODOC__
#define __NODOC__


template <typename X>
struct nodoC
{
	X dato;
	nodoC *sig, *ant;
	nodoC(X &val)
	{
		dato = val;
		sig = ant = this;
	}
};

#endif