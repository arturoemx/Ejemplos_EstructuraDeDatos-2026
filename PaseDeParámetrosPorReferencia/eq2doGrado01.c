#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ejemplo del uso del paso de parámetros por referencia en C a través del
//  uso explicitode apuntadores
void solEqGen2doGrado (float a, float b, float c, float *re1, float *im1,
                       float *re2, float *im2)
{
   float disc;

   disc = b * b - 4 * a * c;

   if (disc == 0)               //La dos soluciones son reales e iguales
   {
      *im1 = *im2 = 0;
      *re1 = *re2 = -b / (2 * a);
   }
   else if (disc > 0)           //Las dos soluciones son reales y diferentes
   {
      disc = sqrt (disc);
      *im1 = *im2 = 0;
      *re1 = (-b + disc) / (2 * a);
      *re2 = (-b - disc) / (2 * a);
   }
   else                         //Las dos soluciones son un complejo conjugado
   {
      disc = sqrt (-disc);

      *re1 = *re2 = -b / (2 * a);
      *im1 = disc / (2 * a);
      *im2 = -*im1;
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
      fprintf(stderr,"\nError: los parametros no corresponden a una ecuación de 2do grado.\n\n");
      exit(1);
   }

   solEqGen2doGrado (A, B, C, &x1r, &x1i, &x2r, &x2i);

   printf("\nLas soluciones a la ecuación %4.2f * x^2 + %4.2f * x", A, B);
   if (C > 0.)
      printf(" + %4.2f = 0 son:\n\n", C);
   else if (C<0.)
      printf(" - %4.2f = 0 son:\n\n", -C);
   else
      printf (" = 0 son:\n\n");

   if (x1i != 0.)
   {
      if (x1i > 0)
      {
         printf ("x1 = %04.2f + %04.2fi\n", x1r, x1i);
         printf ("x2 = %04.2f - %04.2fi\n\n", x2r, -x2i);
      }
      else
      {
         printf ("x1 = %04.2f - %04.2fi\n", x1r, -x1i);
         printf ("x2 = %04.2f + %04.2fi\n\n", x2r, x2i);
      }   
   }
   else
   {
      printf ("x1 = %04.2f\n", x1r);
      printf ("x2 = %04.2f\n\n", x2r);
   }

   return 0;
}
