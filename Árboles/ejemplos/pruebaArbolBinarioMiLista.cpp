#include <ArbolBinario.h>
#include <listaD.h> 
#include <iostream>
#include <string>

using namespace std;


struct convXStrToStr: public convertFromXToString<string>
{
	string operator() (const string &s)
	{
		return s;
	}
};

struct convStrToStrX: public convertFromStringToX<string>
{
	string operator() (string s)
	{
		return s;
	}
};

int main(int argc, char **argv)
{
	listaD<string> L;
	arbolBinario<string> A;
	listaD<string> descArbol;

	L.pushBack(string("C"));
	L.pushBack(string("E"));
	L.pushBack(string("F"));
	L.pushBack(string("@"));
	L.pushBack(string("H"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("B"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("G"));
	L.pushBack(string("A"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("N"));
	L.pushBack(string("J"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("K"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));

	cout << endl << "Llenamos el árbol con la siguiente cadena: " 
	     << endl << L << endl << endl;
	
	convStrToStrX cnvSSX;
	llenaArbolFromListaD(A, L, cnvSSX);

	cout << "Recorrido inorder:" << endl;
	A.inorder();
	cout << endl << endl;

	cout << "Recorrido preorder:" << endl;
	A.preorder();
	cout << endl << endl;

	cout << "Recorrido posorder:" << endl;
	A.posorder();
	cout << endl << endl;

	convXStrToStr cnvSXS;
	generaDescripcion(A, descArbol, cnvSXS);

	cout << "Generamos una descripción del árbol binario:" << endl
	     << descArbol << endl << endl;
	return 0;
}