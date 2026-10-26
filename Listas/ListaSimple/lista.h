#ifndef __LISTA__
#define __LISTA__

#include <iostream>
#include "nodo.h"

using namespace std;


template<typename X>
struct lista
{
	nodo<X> *raiz;
	uint tama;
	
	//Constructor por defecto.
	lista()
	{
		raiz = nullptr;
		tama = 0;
	}

	//Constructor de copia.
	lista(const lista<X> &L)
	{
		raiz = nullptr;
		tama = 0;
		copia(L);
	}

	nodo<X> *creaNodo(X &val)
	{
		nodo<X> *n;

		n = new nodo(val);
		if (n == nullptr)
		{
			cerr << "Error en lista::creaNodo: no hay memoria." << endl;
			cerr.flush();
			return nullptr;
		}
		return n;
	}
	void pushFront(X &val)
	{
		nodo<X> *n;

		n = creaNodo(val);
		if (n!=nullptr)
		{
			n->sig = raiz;
			raiz = n;
			tama++;
		}
		else
		{
			cerr << "Error en lista::pushFront: no se pudo obtener nodo." << endl;
			cerr.flush();
			exit(1);
		}
	}

	void pushBack(X &val)
	{
		nodo<X> *n;

		n = creaNodo(val);
		if (n != nullptr)
		{
			if (raiz == nullptr)
				raiz = n;
			else
			{
				nodo<X> *apu;

				apu = raiz;
				while (apu->sig != nullptr)
					apu = apu->sig;
				apu->sig = n;
			}
			tama++;
		}
		else
		{
			cerr << "Error en lista::pushBack: no se pudo obtener nodo." << endl;
			cerr.flush();
			exit(1);
		}
	}

	void pushFront(nodo<X> *n)
	{
		if (n == nullptr)
		{
			cerr << "Error en pushFront: el nodo que se quiere meter es nulo." << endl;
			return;
		}
		n->sig = raiz;
		raiz = n;
		tama++;
	}

	void pushBack(nodo<X> *n)
	{
		if (n == nullptr)
		{
			cerr << "Error en pushFront: el nodo que se quiere meter es nulo." << endl;
			return;
		}
		if (raiz == nullptr)
			raiz = n;
		else
		{
			nodo<X> *apu;

			apu = raiz;
			while (apu->sig != nullptr)
				apu = apu->sig;
			apu->sig = n;
		}
		tama++;
	}

	 void pushBackR1 (const X & val)
   {
      if (raiz == nullptr)
      {
         nodo < X > *n;

         n = creaNodo(val);
         raiz = n;
         tama++;
      }
      else
         _pushBackR1 (raiz, val);
   }

   void _pushBackR1 (nodo < X > *r, const X & val)
   {
      if (r->sig != nullptr)
         _pushBackR1 (r->sig, val);
      else
      {
         nodo < X > *n;

         n = creaNodo(val);
         r->sig = n;
         tama++;
      }
   }

   void pushBackR2 (const X & val)
   {
      if (raiz == nullptr)
      {
         nodo < X > *n;

         n = creaNodo(val);
         raiz = n;
         tama++;
      }
      else
         raiz = _pushBackR2 (raiz, val);
   }

   nodo < X > *_pushBackR2 (nodo < X > *r, const X & val)
   {
      if (r == nullptr)
      {
         nodo < X > *n;

         n = creaNodo(val);
         tama++;
         return n;
      }
      else
      {
         r->sig = _pushBackR2 (r->sig, val);
         return r;
      }
   }

   void copia(const lista<X> &L)
   {
   	if (raiz != nullptr)
   		borraLista();
   	if (L.raiz == nullptr)
   		return;
   	nodo<X> *apu, *fin;
   	pushFront(L.raiz->dato);
   	apu = L.raiz->sig;
   	fin = raiz;
   	while (apu != nullptr)
   	{
   		nodo<X> *n;

   		n = creaNodo(apu->dato);
   		fin->sig = n;
   		apu = apu->sig;
   		fin = n;
   	}
   	tama = L.tama;
   }

	void imprime()
	{
		nodo<X> *apu;

		apu = raiz;
		cout << "lista[" << tama << "].raiz -> ";
		while(apu != nullptr)
		{
			cout << "|" << apu->dato << "| -> ";
			apu = apu->sig; 
		}
		cout << "NULLPTR" << endl;
	}

	nodo<X> *nElemento(int n)
	{
		nodo<X> *aux = raiz;

		if (n < 0)
			n = tama + n;
		if (n >= (int)tama || n < 0)
			return nullptr;
		else
			for (int i=0;i<n;++i)
				aux = aux->sig;
		return aux;
	}

	lista<X> &operator = (const lista<X> &L)
	{
		copia(L);
		return *this;
	}

	X & operator[](int idx)
   {
      nodo < X > *apu;

      apu = nElemento (idx);
      if (apu != nullptr)
      	return apu->dato;
      else
      {
      	X out;
     		cerr << "Error in lista::operator []: indice fuera de límite." << endl;
     		return out;
     	}
   }

	uint Size()
	{
		return tama;
	}

	nodo<X> *busca(X &val)
	{
		nodo<X> *apu;

		apu = raiz;
		while (apu != nullptr && apu->dato != val)
			apu = apu->sig;
		//for (apu=raiz;apu != nullptr && apu->dato != val;apu=apu->sig);
		return apu;
	}

	void inserta(nodo<X> *p, X &val)
	{
		if (p != nullptr)
		{
			nodo<X> *n;

			n = creaNodo(val);
			if ( n != nullptr)
			{
				n->sig = p->sig;
				p->sig = n;
			}
		}
	}

	void extrae(nodo<X> *p)
	{
		nodo<X> *apu = raiz;

		if (raiz != nullptr)
		{
			if (p == raiz)
			{
				raiz = raiz->sig;
				p->sig = nullptr;
			}
			else
			{
				while (apu != nullptr && apu->sig != p)
					apu = apu->sig;
				if (apu != nullptr)
				{
					apu->sig = p->sig;
					p->sig = nullptr;
				}
				else
				{
					cerr << "Error en lista::extrae: el apuntador p no pertenece a la lista.s"
					     << endl;
					exit (1);
				}
				tama--;
			}
		}
	}

	void borraLista()
	{
		nodo<X> *tmp = raiz;
		while (raiz != nullptr)
		{
			tmp = raiz;
			raiz = raiz->sig;
			delete tmp;
		}
		raiz = nullptr;
		tama = 0;
	}

	~lista()
	{
		borraLista();
	}

};

template <typename X>
ostream &operator<<(ostream &s, lista<X> &l)
{
	nodo<X> *apu;

	apu = l.raiz;
	s << "lista[" << l.tama << "].raiz -> ";
	while(apu != nullptr)
	{
		s << "|" << apu->dato << "| -> ";
		apu = apu->sig; 
	}
	s << "NULLPTR" << endl;
	return s;
}

#endif
