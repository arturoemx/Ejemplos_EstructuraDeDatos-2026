#include <iostream>
#include <fstream>
#include <chrono>
#include <math.h>
#include <vector>


using namespace std;
using namespace std::chrono;

// Implementación de una funcion iterativa que regresa el
// elemento n de la seriede Fibonacci.
long unsigned int fiboI(int k)
{
	int i, a, b, c;

	if (k < 3)
		return 1;
	else
	{
		a = b = 1;
		for (i = 3;i <= k; ++i)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

// Implementación de una funcion recursiva que regresa el
// elemento n de la seriede Fibonacci.
long unsigned int fiboR(int k)
{
	if (k < 3)
		return 1;
	else
		return fiboR(k-1) + fiboR(k-2);
}

// Implementación de una funcion que regresa el
// elemento n de la seriede Fibonacci usando una formula.
long unsigned int fiboF(int k)
{
	if (k < 3)
		return 1;
	else
	{
		double phiA, phiB, sq5;

		sq5 = sqrt(5);
		phiA = (1+sq5)/2;
		phiB = (1-sq5)/2;

		return (long unsigned int)rint((pow(phiA,k)-pow(phiB,k))/sq5);
	}
}

// Esta estructura contiene una medición del tiempo
// que tarda en ejecutarse un programa.
struct tiempos
{
	long n;  //El numero de operaciones que se calculan.
	float tI; //El tiempo que tardan n operaciones en realizarse iterativamente.
	float tR; //El tiempo que tardan n operaciones en realizarse recursivamente.
	float tF; //El tiempo que tardan n operaciones a través de una fórmula.
	//Constructor de la estructura.
	tiempos()
	{
		n=0;
		tI = tR = tF = 0.;
	}
};

int main(int argc, char **argv)
{
	int nMax;       //Número maximo de operaciones a evaluar. 
	int Intervalo; // Intervalos entre numeros de operaciones a realizar.
	int nMuestras;  // Numero de veces que se va a repetir una medicion para
	                // obtener un promedio.
	int n;          // número de evaluaciones a realizar.
	int h, i, j;//I=Índices
	long unsigned int FI, FR, FF;
	auto start = high_resolution_clock::now();
	auto end   = high_resolution_clock::now();

	//Leemos el numero de valores que se probaran.
	
	nMax = 44;
	Intervalo = 1;
	nMuestras = 5;
	if (argc > 1)
	{
		nMax = stoi(argv[1]);
		if (argc > 2)
		{
			Intervalo = stoi(argv[2]);
			if (argc > 3)
				nMuestras = stoi(argv[3]);
		}
	}

	//Ajustamos n a los datos que pueden ser medidos
	n = nMax / Intervalo;
	nMax = n * Intervalo;


	//Declaramos un vector de objetos 'tiempos'.
	//Aquí almacenamos los resultados.
	vector<tiempos> T(n);

	cout << endl 
	     << "Ejecutando las funciones de Fibonacci en forma iterativa"
	     << ", recursiva y con una fórumla, para valores en el intervalo [1, "
	     << Intervalo + 1 << ", " << 2 * Intervalo + 1 << ", ..., " << nMax 
	     << "], promediando las mediciones de tiempo " << nMuestras << " veces."
	     << endl << endl;

	auto startT = high_resolution_clock::now();
	for (i = 1, j = 0; i <= nMax; i+=Intervalo, j++)
	{
		for (h = 0; h < nMuestras; ++h)
		{
			T[j].n = i;

			start = high_resolution_clock::now();
			FI = fiboI(i);
			end   = high_resolution_clock::now();
			auto time = duration_cast<nanoseconds>(end - start).count();
				
			T[j].tI += time;

			start = high_resolution_clock::now();
			FR = fiboR(i);
			end   = high_resolution_clock::now();
			time = duration_cast<nanoseconds>(end - start).count();

			T[j].tR += time;

			start = high_resolution_clock::now();
			FF = fiboF(i);
			end   = high_resolution_clock::now();
			time = duration_cast<nanoseconds>(end - start).count();

			T[j].tF += time;
		}
		cout << "fiboI(" << i << ") = " << FI <<" requirió " << T[j].tI/nMuestras  << " nanosegundos para ejecutarse." << endl 
		     << "fiboR(" << i << ") = " << FR <<" requirió " << T[j].tR/nMuestras  << " nanosegundos para ejecutarse." << endl 
		     << "fiboF(" << i << ") = " << FF <<" requirió " << T[j].tF/nMuestras  << " nanosegundos para ejecutarse." << endl 
		     << endl;
	}
	auto endT   = high_resolution_clock::now();
	auto timeT = duration_cast<nanoseconds>(endT - startT).count();
	cout << "Se requirieron " << timeT * 1e-9 << " segundos para calcular los resultados."
	     << endl;


	//Guardando tiempos en un archivo CSV.
	ofstream tout("tiemposFibonacci.csv");

	tout << "n,Iterativo,Recursivo,Formula"<<endl;
	for (i=0;i<n;++i)
		tout << T[i].n << "," << T[i].tI/nMuestras << "," 
	         << T[i].tR/nMuestras << ","<< T[i].tF/nMuestras << endl;
	tout.close();
	cout << endl 
	     << "La tabla de tiempos se almacenó en el archivo tiemposFibonacci.csv"
         << endl << endl;

	return 0;
}