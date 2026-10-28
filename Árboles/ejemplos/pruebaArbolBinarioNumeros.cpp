#include <ArbolBinario.h>
#include <listaD.h> 
#include <iostream>
#include <string>

using namespace std;


struct convStrToInt: public convertFromStringToX<int>
{
	int operator() (string s)
	{
		return stoi(s);
	}
};

struct convIntToStr: public convertFromXToString<int>
{
	string operator() (const int &val)
	{
		return to_string(val);
	}
};

int main(int argc, char **argv)
{
	listaD<string> L;
	arbolBinario<int> A;
	listaD<string> descArbol;

	L.pushBack(string("12"));
	L.pushBack(string("-5"));
	L.pushBack(string("8"));
	L.pushBack(string("@"));
	L.pushBack(string("234"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("-56"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("2"));
	L.pushBack(string("1"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("35"));
	L.pushBack(string("22"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));
	L.pushBack(string("94"));
	L.pushBack(string("@"));
	L.pushBack(string("@"));

	cout << endl << "Llenamos el árbol con la siguiente cadena: " 
	     << endl << L << endl << endl;

	convStrToInt cnvS2I;
	llenaArbolFromListaD(A, L, cnvS2I);

	cout << "Recorrido inorder:" << endl;
	A.inorder();
	cout << endl << endl;

	cout << "Recorrido preorder:" << endl;
	A.preorder();
	cout << endl << endl;

	cout << "Recorrido posorder:" << endl;
	A.posorder();
	cout << endl << endl;

	convIntToStr cnvI2S;
	generaDescripcion(A, descArbol, cnvI2S);

	cout << "Generamos una descripción del árbol binario:" << endl
	     << descArbol << endl << endl;
	return 0;
}