#include <iostream>

using namespace std;


int main ()
{
   int a = 5, b = 16, c = 0;
   int *pa, *pb, *pc;

   pa = &a;
   pb = &b;
   pc = &c;

   cout << endl;
   cout << "La variable 'a' contiene el valor " << a
      << " y su dirección es " << pa << endl << endl;
   cout << "La variable 'b' contiene el valor " << b
      << " y su dirección es " << pb << endl << endl;
   cout << "La variable 'c' contiene el valor " << c
      << " y su dirección es " << pc << endl << endl;

   cout << "-----" << endl << endl;

   cout << "A la variable a la que apunta 'pa' la incrementamos por 5." <<
      endl << endl;
   *pa += 5;

   cout << "A la variable a la que apunta 'pb' la decrementamos por 6." <<
      endl << endl;
   *pb = *pb - 6;

   cout << "A la  variable 'c' le  asignamos  la suma de las variable" << endl
      << "'a' y 'b' y la multiplicamos por 2." << endl << endl;
   c = (a + b) * 2;

   cout << "-----" << endl << endl;

   cout << "La variable 'a' contiene el valor " << *pa
      << " y su dirección es " << pa << endl << endl;
   cout << "La variable 'b' contiene el valor " << *pb
      << " y su dirección es " << pb << endl << endl;
   cout << "La variable 'c' contiene el valor " << *pc
      << " y su dirección es " << pc << endl << endl;
   return 0;
}
