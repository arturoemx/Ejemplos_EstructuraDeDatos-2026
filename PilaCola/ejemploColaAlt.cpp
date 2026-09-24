#include <iostream>
#include <time.h>
#include "ColaAlt.h"

using namespace std;

int main(int argc, char **argv)
{
	uint i, j;    // Índices.
	int val;      // Donde almacenamos los valores que sacamos o metemos.
	uint tama;    // El tamaño de la cola
	uint nMax;    // El número máximo de valores que trataremos de meter
	              // o sacar de la cola. 
	uint vueltas; // Número de veces que se repetíra el ciclo de metet y sacar.
	long semilla; //La semilla para inicializar el generador de número aleatorios.

	if (argc > 1)
	{
		tama = stoi(argv[1]);
		if (argc > 2)
		{
			semilla = stol(argv[2]);
			if (argc > 3)
				vueltas = (uint)stoi(argv[3]);
			else
				vueltas = 4;
		}
		else
		{
			semilla = time(0);
			vueltas = 4;
		}
	}
	else
	{
		cerr << endl << "Error: faltan argumentos:" << endl
		     << endl << "Uso: " << argv[0] << " tama [semilla] [vueltas]"
		     << endl << "donde:" << endl << endl
		     << endl << "	tama: el tamaño de la cola que se va a usar." << endl 
		     << endl << "	semilla: semilla para inicializar el generador"
		     << " de números aleatorios" << endl
		     << endl << "	vueltas: número de ciclos de prueba a usar." << endl
		     << endl << "Tanto semilla como vueltas son parámetros opcionales. "
		     << "Si no se definenen:" << endl << endl
		     << "	vueltas = 4." << endl << endl
		     << "	semilla = número de segundos desde el epoch (1/1/1970)." 
		     << endl << endl;
		     exit(1);
	}

	//Declaramos la cola.
	colaAlt<int> C(tama);

	// Definimos NMax como 1.25 tama para inducir errores al meter y sacar elementos
	// de la cola.
	nMax = tama + tama/4; 

	

	//Inicializamos el generador de número aleatorios.
	srand(semilla);
	cout << endl << "Inicializamos el generador de número"
	     << " aleatorios con la semilla " << semilla << endl;

	cout << endl << "Asi luce la cola vacia: " << C << endl << endl;

	//Iniciamos el ciclo de prueba.
	for (i=0;i<vueltas;++i)
	{
		uint encolar, dencolar;
		encolar = rand() % nMax;

		cout << "Intentaremos meter " << encolar 
		     << " numeros en la cola." << endl << endl;
		for (j = 0; j < encolar; ++j)
		{
			val = 3 * j * j + 2 * j + 5; // 3j^2+2j+5
			if (C.enqueue(val) == 0)
				cout << j << " : Metemos el valor " << val << " a la cola."
				     << endl;
			else
			{
				cout << "ERROR: cola llena." << endl;
				break;
			}
		}

		cout << endl << "Asi luce la cola ahora: " << C << endl << endl;

		dencolar = rand() % (2 * tama);

		cout << "Intentaremos sacar " << dencolar 
		     << " numeros en la cola." << endl << endl;

		for (j = 0; j < dencolar; ++j)
		{
			if (C.dequeue(val) == 0)
				cout << j << ": Sacamos el valor " << val << " de la cola."
				     << endl;
			else
			{
				cout << "ERROR: cola vacia." << endl;
				break;
			}
		}
		cout << endl << "Asi luce la cola ahora: " << C
		     << endl << endl
		     << "----------------------------------------"
		     << "----------------------------------------"
		     << "----------------------------------------"
		     << endl << endl;
	}

	//Vaciamos la cola.
	cout << "Vamos a vaciar la cola." << endl << endl;
	do
	{
		if (C.dequeue(val) == 0)
			cout << "Sacamos el valor " << val << " de la cola." << endl;
		else
			break;
	} while (true);

	cout << endl << "Asi luce la cola al final, cuando está vacia: " << C << endl << endl;
	
	return 0;
}