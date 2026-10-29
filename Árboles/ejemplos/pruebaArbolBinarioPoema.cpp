#include <ArbolBinario.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string Poema = "Me|gustas|cuando|callas|porque|estás|@|@|como|@|@|ausente,|\ny|me|@|@|oyes|@|@|desde|lejos,|@|@|y|@|@|mi|voz|no|@|@|te|@|@|toca.|\nParece|@|@|que|@|@|los|ojos|se|@|@|te|@|@|hubieran|@|@|volado|\ny|@|@|parece|que|un|beso|te|cerrara|@|@|la|boca.|@|@|@|@|\n\nComo|todas|las|cosas|están|llenas|@|@|de|@|@|mi|alma|@|@|\nemerges|@|@|de|las|cosas,|@|@|llena|@|@|del|alma|@|@|mía.|@|@|\nMariposa|de|sueño,|te|@|@|pareces|@|@|a|mi|@|@|alma,|@|@|\ny|te|pareces|a|@|@|la|@|@|palabra|@|@|melancolía.\n\n|@|@|@|@|@";
	arbolBinario<string> P;
	string descArbol;
	string screenSep(80,'-');


	cout << endl << "Llenamos el árbol con la siguiente cadena:"
	     << endl << "\"";
	printString(Poema);
	cout << "\"" << endl;

	cout << endl << screenSep << endl;

	llenaArbol(P, Poema, '|');

	cout << "Recorrido inorder:" << endl << endl;
	P.inorder();
	cout << endl;

	cout << endl << screenSep << endl;

	cout << "Recorrido preorder:" << endl << endl;
	P.preorder();
	cout << endl;

	cout << endl << screenSep << endl;

	cout << "Recorrido posorder:" << endl << endl;
	P.posorder();
	cout << endl << endl;

	cout << endl << screenSep << endl;

	generaDescripcion(P, descArbol,"|");

	cout << "Generamos una descripción del árbol binario:" << endl << endl;
	printString(descArbol);
	cout << endl << endl;


	return 0;
}