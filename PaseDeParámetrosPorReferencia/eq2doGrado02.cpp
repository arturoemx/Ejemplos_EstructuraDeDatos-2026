#include <iostream>
#include <math.h>

using namespace std;

// Ejemplo del uso del paso de parámetros por referencia en C++.

void solEqGen2doGrado (float a, float b, float c, float &re1, float &im1,
                       float &re2, float &im2)
{
   float disc;

   disc = b * b - 4 * a * c;

   if (disc == 0)               //La dos soluciones son reales e iguales
   {
      im1 = im2 = 0;
      re1 = re2 = -b / (2 * a);
   }
   else if (disc > 0)           //Las dos soluciones son reales y diferentes
   {
      disc = sqrt (disc);
      im1 = im2 = 0;
      re1 = (-b + disc) / (2 * a);
      re2 = (-b - disc) / (2 * a);
   }
   else                         //Las dos soluciones son un complejo conjugado
   {
      disc = sqrt (-disc);

      re1 = re2 = -b / (2 * a);
      im1 = disc / (2 * a);
      im2 = -im1;
   }

}

int main (int argc, char **argv)
{
   float A, B, C;
   float x1r, x1i, x2r, x2i;

   if (argc < 3)
      exit (1);
   A = atof (argv[1]);
   B = atof (argv[2]);
   C = atof (argv[3]);

   if (A == 0.)
   {
      cerr << endl << "Error: los parametros no corresponden a una ecuación de 2do grado."
           << endl;
      exit(1);
   }

   solEqGen2doGrado (A, B, C, x1r, x1i, x2r, x2i);

   cout << endl << "Las soluciones a la ecuación "
      << A << " * x^2 + " << B << " * x";
   if (C > 0.)
      cout << " + " << C; 
   else if (C < 0.)
      cout << " - " << -C;
   cout << " = 0 son:" << endl << endl;

   if (x1i != 0.)
      if (x1i > 0.)
         cout << "x1 = " << x1r << " + " << x1i << "i" << endl
              << "x2 = " << x2r << " - " << -x2i << "i" << endl << endl;
      else
         cout << "x1 = " << x1r << " - " << -x1i << "i" << endl
              << "x2 = " << x2r << " + " << x2i << "i" << endl << endl;
   else
      cout << "x1 = " << x1r << endl
           << "x2 = " << x2r << endl << endl;

   return 0;
}
