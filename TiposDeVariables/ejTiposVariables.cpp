#include <iostream>
#include <string>

using namespace std;

// L es una variable global: podemos acceder a ella desde cualquier función
// de; programa y su ámbito es la ejecución del programa.
// No es recomendable el uso indiscriminado de variables globales.
float L;

int suma(int a, int b)
{
	// Tanto los parámetros a y b como la variable c definida abajo son variables
	// locales que solo existen mientras la función está ejecutandose.
	// La variable estática cont, definida abajo, por otro lado mantiene su valor
	// entre llamadas. La inicialización con 0 que se define abajo solo se ejecuta
	// la primera vez que se invoca a la función.
	int c;
	static int cont = 0;

	c = a+b;
	cout<<"Esta funcion ha sido llamada " << cont++ << " veces." << endl;
	return c;
}


int main()
{
	// Estas son variables locales.
	// Solo existen en el ámbito en el que fueron definidas.
	// Usualmmente el ámbito se define por las llaves, en este caso las que
	// limitan a la función main.
	int a, b, c;

	{   // Las variables que se definen abajo pertenecen al ámbito de las
		// llaves que la definen y solo podemos acceder a ellas en ese ámbito.
		float v[256];
		uint i;

		for (i=0;i<256;++i)
			v[i] = i*i;
		cout << "v[16] = " << v[16] << endl;
	}

	// La siguiente instrucción está comentada pues si la descomentamos
	// ocurrira un error de compilación, pues la variable v ya no existe
	// pues su ámbito terminó.
	// cout << "v[16] = " << v[16] << endl;

	a=5;

	b=6;
	
	// Invocamos 4 veces la función suma, para demostrar como la variable
	// estática cont definida en ella funciona.
	c=suma(a,b);
	
	c=suma(b,c);
	
	c=suma(c,a);
	
	c=suma(a,b);

	return 0;
}