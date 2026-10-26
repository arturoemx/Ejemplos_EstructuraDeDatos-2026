#ifndef __LISTA_DOBLE__
#define __LISTA_DOBLE__

#include <iostream>
#include "nodoD.h"

using namespace std;


template < typename X > struct listaD
{
   nodoD < X > *raiz, *final;
   uint tama;

   // Constructor por defecto
     listaD ()
   {
      raiz = nullptr;
      final = nullptr;
      tama = 0;
   }

   // Destructor
    ~listaD ()
   {
      borraLista ();
   }

   nodoD < X > *creaNodo (X & val)
   {
      nodoD < X > *n;

      n = new nodoD (val);
      if (n == nullptr)
      {
         cerr << "Error en listaD::creaNodo: no hay memoria." << endl;
         cerr.flush ();
         return nullptr;
      }
      return n;
   }

   void copia (const listaD < X > &L)
   {
      if (raiz != nullptr)
         borraLista ();

      if (L.raiz == nullptr)
         return;

      nodoD < X > *apu = L.raiz;

      while (apu != nullptr)
      {
         pushBack (apu->dato);
         apu = apu->sig;
      }
   }

   void pushFront (X & val)
   {
      nodoD < X > *n;

      n = creaNodo (val);
      if (n != nullptr)
      {
         n->sig = raiz;
         if (raiz != nullptr)
            raiz->ant = n;
         else
            final = n;
         raiz = n;
         tama++;
      }
      else
      {
         cerr << "Error en listaD::pushFront: no se pudo obtener nodo." <<
            endl;
         cerr.flush ();
         exit (1);
      }
   }

   void pushBack (X & val)
   {
      nodoD < X > *n;

      n = creaNodo (val);
      if (n != nullptr)
      {
         if (raiz != nullptr)
         {
            final->sig = n;
            n->ant = final;
            final = n;
         }
         else
            raiz = final = n;
         tama++;
      }
      else
      {
         cerr << "Error en listaD::pushBack: no se pudo obtener nodo." <<
            endl;
         cerr.flush ();
         exit (1);
      }
   }

   void pushFront (nodoD < X > *n)
   {
      if (n != nullptr)
      {
         n->sig = raiz;
         if (raiz != nullptr)
            raiz->ant = n;
         else
            final = n;
         raiz = n;
         tama++;
      }
      else
      {
         cerr << "Error en listaD::pushFront: el nodo a insertar es nulo." <<
            endl;
         cerr.flush ();
         exit (1);
      }
   }

   void pushBack (nodoD < X > *n)
   {
      if (n != nullptr)
      {
         if (raiz != nullptr)
         {
            final->sig = n;
            n->ant = final;
            final = n;
         }
         else
            raiz = final = n;
         tama++;
      }
      else
      {
         cerr << "Error en listaD::pushBack: el nodo a insertar es nulo." <<
            endl;
         cerr.flush ();
         exit (1);
      }
   }


   void inserta (nodoD < X > *p, X & val)
   {
      if (p != nullptr)
      {
         nodoD < X > *n;

         n = creaNodo (val);
         if (n != nullptr)
         {
            n->ant = p;
            n->sig = p->sig;
            p->sig = n;
            if (n->sig != nullptr)
               n->sig->ant = n;
            else
               final = n;
            tama++;
         }
      }
   }

   void extrae (nodoD < X > *p)
   {
      nodoD < X > *apu = raiz;

      if (raiz != nullptr)
      {
         if (p == raiz)
         {
            raiz = raiz->sig;
            if (raiz != nullptr)
            {
               raiz->ant = nullptr;
               p->sig = nullptr;
            }
         }
         else
         {
            p->ant->sig = p->sig;
            if (p->sig != nullptr)
               p->sig->ant = p->ant;
            else
               final = p->ant;
            p->sig = p->ant = nullptr;

         }
         tama--;
      }
   }

   void swap(nodoD *apuA, nodoD *apuB)
   {
      if (i < 0 || i >= n || j < 0 || j >= n)
      {
         cerr << "Error en arreglo;:swap. Indices fuera del rango válido."
              << endl;
         return;
      }
      else
      {
         X tmp;

         X = apuA->data;
         apuA->data = apuB->data;
         apuB->data = tmp;
      }
   }

   void borraLista ()
   {
      nodoD < X > *tmp = raiz;

      while (raiz != nullptr)
      {
         tmp = raiz;
         raiz = raiz->sig;
         delete tmp;
      }
      raiz = final = nullptr;
      tama = 0;
   }

   listaD < X > &operator = (const listaD < X > &L)
   {
      copia (L);
      return *this;
   }

   nodoD<X> *busca(X &val)
   {
      nodoD<X> *apu;

      apu = raiz;
      while (apu != nullptr && apu->dato != val)
         apu = apu->sig;
      //for (apu=raiz;apu != nullptr && apu->dato != val;apu=apu->sig);
      return apu;
   }

   nodoD < X > *nElemento (int n)
   {
      if (n < 0)
         n = tama + n;

      if (n >= (int) tama || n < 0)
         return nullptr;
      else
      {
         int i;
         nodoD < X > *aux;

         if (n <= tama / 2)
         {
            aux = raiz;
            for (i = 0; i < n; ++i)
               aux = aux->sig;
         }
         else
         {
            aux = final;

            for (i = tama - 1; i > n; --i)
               aux = aux->ant;
         }
         return aux;
      }
   }

   X & operator[](int idx)
   {
      nodoD < X > *apu;

      apu = nElemento (idx);
      if (apu != nullptr)
         return apu->dato;
      else
      {
         X out;
         cerr << "Error in lista::operator []: indice fuera de límite." <<
            endl;
         return out;
      }
   }

   uint Size ()
   {
      return tama;
   }

};



template < typename X > ostream & operator<< (ostream & s, listaD < X > &l)
{
   nodoD < X > *apu;

   apu = l.raiz;
   s << "Raiz -> ";
   while (apu != nullptr)
   {
      s << "|" << apu->dato << "| <-> ";
      apu = apu->sig;
   }
   s << "NULLPTR" << endl;
   return s;
}
#endif
