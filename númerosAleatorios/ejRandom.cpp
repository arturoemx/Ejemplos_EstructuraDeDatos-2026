#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{
	int i, val;
	uint semilla;

	if (argc > 1)
		semilla = atoi(argv[1]);
	else
	{
		cout << endl 
		     << "No se proporcióno  una semilla  para inicializar el generador de" << endl
		     << "números aleatorios, por  lo que se inicializará usando el número" << endl
		     << "de segundos transcurridos desde el primero de enero de 1970."<< endl << endl
		     << "Si quiere definir usted  la semilla del generador, pase el valor" << endl
		     << "por parámetro al inicializar el programa, como se muestra abajo:"
		     << endl << endl << "\t ./" << argv[0] << " SEMILLA " << endl << endl;

		semilla = time(nullptr);
	}

	srandom(semilla);

	cout << endl
	     << "Se inicializó el gen. de # aleatorios con la semilla "
	     << semilla << endl << endl;

	cout << "A continuación se imprimen 10 números aleatorios en el intervalo [0,99]"
	     << endl << endl;
	for (i=0;i<10;++i)
	{
		// Usamos el módulo para que sea el residuo de la division del 
		// número aleatorio que obtuvimos el que registramos.
		// Esto es útil, pues nos permite limitar el valor al intervalo [0,99].
		val = random() % 100;
		cout << "Numero aleatorio #" << i << ": " << val << endl;
	}
	cout << endl;

	return 0;
}