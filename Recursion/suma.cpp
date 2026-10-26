#include <iostream>
#include <fstream>
#include <chrono>
#include <math.h>
#include <vector>


using namespace std;
using namespace std::chrono;

//Implementación de una sumatoria iterativa.
int sumaI(int k)
{
	int i, acum=0;

	for (i=1;i<=k;++i)
		acum += i;
	return acum;
}

//Implementación de una sumatoria Recursiva.
int sumaR(int k)
{
	if (k == 1)
		return 1;
	return sumaR(k-1)+k;
}

//Implementación de una sumatoria por Fórmula.
int sumaF(int k)
{
	return (k*k+k)/2;
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
	                // obtener un promedio de tiempo.
	int n;          // número de evaluaciones a realizar.
	int h, i, j;//I=Índices
	auto start = high_resolution_clock::now();
	auto end   = high_resolution_clock::now();

	//Leemos el numero de valores que se probaran.
	
	nMax = 40000;
	Intervalo = 1;
	nMuestras = 30;
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
	     << "Ejecutando las funciones de sumatoria en forma iterativa"
	     << ", recursiva y con una formla, para valores en el intervalo [1, "
	     << Intervalo + 1 << ", " << 2 * Intervalo + 1 << ", ..., " << nMax 
	     << "], promediando las mediciones de tiempo " << nMuestras << " veces."
	     << endl << endl;

	auto startT = high_resolution_clock::now();
	for (h = 0; h < nMuestras; ++h)
		for (i = 1, j = 0; i <= nMax; i+=Intervalo, j++)
		{
			T[j].n = i;

			start = high_resolution_clock::now();
			sumaI(i);
			end   = high_resolution_clock::now();
			auto time = duration_cast<nanoseconds>(end - start).count();
			//out << "SumaI(" << i << ") = " << sum <<" requirió " << time  << " nanosegundos para ejecutarse." << endl;
			
			T[j].tI += time;

			start = high_resolution_clock::now();
			sumaR(i);
			end   = high_resolution_clock::now();
			time = duration_cast<nanoseconds>(end - start).count();
			//cout << "SumaR(" << i << ") = " << sum <<" requirió " << time  << " nanosegundos para ejecutarse." << endl;

			T[j].tR += time;

			start = high_resolution_clock::now();
			sumaF(i);
			end   = high_resolution_clock::now();
			time = duration_cast<nanoseconds>(end - start).count();
			//cout << "SumaF(" << i << ") = " << sum <<" requirió " << time  << " nanosegundos para ejecutarse." << endl;

			T[j].tF += time;
		}
	auto endT   = high_resolution_clock::now();
	auto timeT = duration_cast<nanoseconds>(endT - startT).count();
	cout << "Se requirieron " << timeT * 1e-9 << " segundos para calcular los resultados."
	     << endl;


	//Guardando tiempos en un archivo CSV.
	ofstream tout("tiemposSuma.csv");

	tout << "n,Iterativo,Recursivo,Formula"<<endl;
	for (i=0;i<n;++i)
		tout << T[i].n << "," << T[i].tI/nMuestras << "," 
	         << T[i].tR/nMuestras << ","<< T[i].tF/nMuestras << endl;
	tout.close();
	cout << endl 
	     << "La tabla de tiempos se almacenó en el archivo tiemposSuma.csv"
         << endl << endl;

	return 0;
}