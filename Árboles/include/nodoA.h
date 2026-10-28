#ifndef __NODO_ARBOL__
#define __NODO_ARBOL__

template <typename X>
struct nodoA
{
	X dato;
	nodoA *izq, *der, *padre;
	nodoA(X &val)
	{
		dato = val;
		izq = der = padre = nullptr;
	}
};
#endif