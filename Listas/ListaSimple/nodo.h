#ifndef __NODO__
#define __NODO__

template<typename X>
struct nodo
{
	X dato;
	nodo<X> *sig;
	nodo(X &val)
	{
		dato = val;
		sig =nullptr;
	}
};
#endif
