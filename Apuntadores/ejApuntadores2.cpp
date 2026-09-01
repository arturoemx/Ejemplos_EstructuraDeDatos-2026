#include <iostream>

using namespace std;

int main ()
{
   long double A[5] = { 10, 8, 6, 4, 7 };
   int i;

   cout << "A = " << A << endl;

   cout << "*A = " << *A << endl << endl;

   for (i = 0; i < 5; ++i)
   {
      cout << "A[" << i << "]    = " << A[i] << endl;
      cout << "&(A[" << i << "]) = " << &(A[i]) << endl;
      cout << "*(&(A[" << i << "])) = " << *(&(A[i])) << endl;
      cout << "A + " << i << "   = " << A + i << endl;
      cout << "*(A + " << i << ")   = " << *(A + i) << endl;
      cout << endl;
   }

   return 0;
}
