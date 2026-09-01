#include <iostream>

using namespace std;

//
// En vez de escribir unsigned int, podemos escribir uint
//


// En este caso la función recibe un apuntador a un arreglo y el tamaño del arreglo.
// Usamos corchetes para acceder a cada elemento del arreglo.
void imprimeArreglo0 (int *A, uint n)
{
   uint i;

   for (i = 0; i < n; ++i)
      cout << "A[" << i << "] = " << A[i] << endl;
}

// En este caso la función recibe un apuntador a un arreglo y el tamaño del arreglo.
// Utilizams apuntadores para acceder de manera incremental a cada elemento del arreglo.
void imprimeArreglo1 (int *A, uint n)
{
   uint i;
   int *pA;

   for (pA = A, i = 0; i < n; ++i, pA++)
      cout << "A[" << i << "] = " << *pA << endl;
}

// En este caso la función recibe un apuntador a un arreglo y el tamaño del arreglo.
// Utilizams apuntadores para acceder de manera incremental a cada elemento del arreglo
// y no requerimos un índice para contar.
void imprimeArreglo2 (int *A, uint n)
{
   int *pA, *fin;

   cout << "A = {";
   pA = A;
   fin = A + n - 1;
   for (; pA < fin; pA++)
      cout << *pA << ", ";
   cout << *pA << "}" << endl;
}

int main ()
{
   int Q[5] = { 10, 8, 6, 4, 7 };


   imprimeArreglo0 (Q, 5);
   cout << endl;
   imprimeArreglo1 (Q, 5);
   cout << endl;
   imprimeArreglo2 (Q, 5);

   return 0;
}
