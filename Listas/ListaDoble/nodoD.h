#ifndef __NODO_DOBLE__
#define __NODO_DOBLE__

template <typename X>
struct nodoD
{
	X dato;
	nodoD<X> *sig, *ant;
	nodoD(X &val)
	{
		dato = val;
		sig = ant = nullptr;
	}
};

#endif