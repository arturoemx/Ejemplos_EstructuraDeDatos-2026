#ifndef __LISTA_CIRCULAR__
#define __LISTA_CIRCULAR__
#include <iostream>
#include "nodoC.h"

using namespace std;


template < typename X > struct listaC
{
   nodoC < X > *raiz;
   uint tama;

   // Constructor por defecto
     listaC ()
   {
      raiz = nullptr;
      tama = 0;
   }

   // Destructor
    ~listaC ()
   {
      borraLista ();
   }

   nodoC < X > *creaNodo (X & val)
   {
      
   }

   void copia (const listaC < X > &L)
   {
      
   }

   void pushFront (X & val)
   {
      pushBack(val);
      raiz = raiz->ant;
   }

   void pushBack (X & val)
   {
   	nodoC<X> *n;

   	n = creaNodo(val);
   	if (n)// equivalente a n != nullptr
   	{
   		if (!raiz) // equivalente a raiz != nullptr
   			raiz = n;
   		else
   		{
   			raiz->ant->sig = n;
   			n->ant = raiz->ant;
   			n->sig = raiz;
   			raiz->ant = n;
   		}
   		tama++;
   	}
      
   }

   void pushFront (nodoC < X > *n)
   {
      
   }

   void pushBack (nodoC < X > *n)
   {
      
   }


   void inserta (nodoC < X > *p, X & val)
   {
      
   }

   void extrae (nodoC < X > *p)
   {
     
   }

   void borraLista ()
   {
      
   }

   listaC < X > &operator = (const listaC < X > &L)
   {
      
   }

   nodoC<X> *busca(X &val)
   {
 
   }

   nodoC < X > *nElemento (int n)
   {
      
   }

   X & operator[](int idx)
   {
      
   }

   uint Size ()
   {
      return tama;
   }

};

template < typename X > ostream & operator<< (ostream & s, listaC < X > &l)
{
   
   return s;
}

#endif