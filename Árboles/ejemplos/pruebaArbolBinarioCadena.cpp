#include <ArbolBinario.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string C = "C,E,F,@,H,@,@,B,@,@,G,A,@,@,N,J,@,@,K,@,@";
	arbolBinario<string> A;
	string descArbol;
	string screenSep(80,'-');

	cout << endl << "Llenamos el árbol con la siguiente cadena:" << endl
	     << "\"" << C << "\"" << endl << endl;

	llenaArbol(A, C, ',');

	cout << endl << screenSep << endl;

	cout << "Recorrido inorder:" << endl << endl;
	A.inorder();
	cout << endl;

	cout << endl << screenSep << endl;

	cout << "Recorrido preorder:" << endl << endl;
	A.preorder();
	cout << endl;

	cout << endl << screenSep << endl;

	cout << "Recorrido posorder:" << endl << endl;
	A.posorder();
	cout << endl;

	cout << endl << screenSep << endl;

	generaDescripcion(A, descArbol, ",");

	cout << "Generamos una descripción del árbol binario:" << endl
	     << endl << "\"" << descArbol << "\"" << endl << endl;

	return 0;
}