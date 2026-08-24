#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

void imprimeArregloInt(unsigned int *A, unsigned int n, string varName)
{
	unsigned int i;

	cout << varName << "[" << n << "] = {";
	for (i = 0; i < n-1; ++i)
		cout << A[i] << ", ";
	cout << A[i] << "};" << endl;
}

void invierteArreglo1(unsigned int *A, unsigned int n)
{
	unsigned int *B;
	unsigned int i, j;

	B = new unsigned int[n];

	if (B != nullptr)
	{
		for (i = 0, j = n-1; i < n; ++i, --j)
			B[i] = A[j];

		for (i = 0; i < n; ++i)
			A[i] = B[i];
		delete []B;
	}
	else
		cerr << "Error en función invierteArreglo1: No se pudo obtener memoria dinámica."
	         << endl;
}

void invierteArreglo2(unsigned int *A, unsigned int n)
{
	unsigned int tmp, m = n/2;
	unsigned int i, j;

	for (i = 0, j = n-1; i < m; ++i, --j)
	{
		// SWAP (Intercambio) convencional/ 
		tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
}

void invierteArreglo3(unsigned int *A, unsigned int n)
{
	unsigned int m = n/2;
	unsigned int i, j;

	for (i = 0, j = n-1; i < m; ++i, --j)
	{
		//Swap utilizando XOR
		A[i] = A[i] ^ A[j];
		A[j] = A[j] ^ A[i];
		A[i] = A[i] ^ A[j];
	}
}

enum modos {none = 0, algo1, algo2, algo3};

int main(int argc, char **argv)
{
	modos invModo = none;
	unsigned int i, j, n;
	unsigned int *A;
	bool banderaImpresión = true;

	if (argc > 2)
	{
		n = stoi(argv[1]);
		
		switch(argv[2][0])
		{
			case '1':
				invModo = algo1;
				break;
			case '2':
				invModo = algo2;
				break;
			case '3':
				invModo = algo3;
				break;
			default:
			invModo = none;	
		}
		if (argc > 3 && toupper(argv[3][0]) == 'O')
			banderaImpresión = false;
	}
	else
	{
		cout << "Uso: " << argv[0] << " n Modo [o]" << endl << endl
		     << "Donde:" << endl << endl
		     << "   n    -> Tamaño del arreglo a invertir." << endl << endl
		     << "   Modo -> Tipo de método a usar:" << endl << endl
		     << "           1: Doble copia: copia el arreglo a otro arreglo de manera invertida" << endl
		     << "              y luego lo copia de regreso." << endl << endl
		     << "           2: SWAP: recorre la mitad del arreglo desde ambos extremos intercam-" << endl
		     << "              biando valores." << endl << endl
		     << "           3: SWAP XOR: igual que el método SWAP pero usando operador xor para" << endl
		     << "              intercambiar valores." << endl << endl
		     << "   o    -> Argumento opcional. Si el tercer argumento al invocar el programa es"<< endl
		     << "           la letra 'o' o la letra 'O', se omite la impresión del arreglos. " << endl
		     << "           Esto es útil cuando lo que nos interesa es saber cuanto tiempo tarda" << endl
		     << "           en ejecutarse el programa." << endl << endl
		     << "Tras la ejecución se imprime en pantalla el tiempo requerido para ejecutar un" << endl
		     << "programa, en nanosegundos." << endl << endl;
		exit(1);
	}		     

	if (n == 0)
		exit(1);

	A = new unsigned int[n];
	if (A == nullptr)
	{
		cerr << "Error: no se pudo obtener suficiente memoria para el arreglo." << endl;
		exit(1);
	}

	for (i = 0; i < n; ++i)
	{
		int val;

		val = lrand48() % 100;
		A[i] = val;
	}

	cout << endl;
	cout << "Se definió un arreglo \"A\" que contiene " << n << " elementos." << endl << endl;
	if (banderaImpresión == true)
	{
		cout << "El arreglo A, luce así:" << endl << endl;
		imprimeArregloInt(A, n, string("A"));
	}
	auto start = high_resolution_clock::now();
	auto end   = high_resolution_clock::now();

    switch (invModo)
    {
    	case algo3:
    		start = high_resolution_clock::now();
    		invierteArreglo3(A, n);
    		end = high_resolution_clock::now();
    		break;
    	case algo2:
    		start = high_resolution_clock::now();
    		invierteArreglo2(A, n);
    		end = high_resolution_clock::now();
    		break;
    	case algo1:
    	default:
    		start = high_resolution_clock::now();
    		invierteArreglo1(A, n);
    		end = high_resolution_clock::now();
    }
    
    auto time = duration_cast<nanoseconds>(end - start).count();

    
    if (banderaImpresión == true)
    {
    	cout << endl << "---------------------"<< endl << endl
    	     << "Tras invertirlo, el arreglo A, luce así:" << endl << endl;
		imprimeArregloInt(A, n, string("A"));
		cout << endl << "---------------------"<< endl;
    }

	cout << endl
		 << "Para invertir el arreglo se requirieron " << time << " nanosegundos."
	     << endl << endl;

	delete[] A;
	
	return 0;
}