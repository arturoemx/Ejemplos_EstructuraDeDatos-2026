#include <ArbolBinario.h>
#include <list> 
#include <iostream>
#include <string>

using namespace std;

template < typename X > ostream & operator<< (ostream & s, list < X > &l)
{
   typename list <X>::iterator it;
   uint idx, sz;
	
	if (l.size() != 0)
	{
		it = l.begin();
		for (idx = 0, sz = l.size()-1;idx < sz; ++idx, ++it)
			s << "[" << *it << "]-";
		s << "[" << *it << "]";
	}
   return s;
}

struct convStrToStrX: public convertFromStringToX<string>
{
	string operator() (string s)
	{
		return s;
	}
};

struct convStrXToStr: public convertFromXToString<string>
{
	string operator() (const string &s)
	{
		return s;
	}
};

int main(int argc, char **argv)
{
	list<string> L;
	arbolBinario<string> A;
	list<string> descArbol;

	L.push_back(string("C"));
	L.push_back(string("E"));
	L.push_back(string("F"));
	L.push_back(string("@"));
	L.push_back(string("H"));
	L.push_back(string("@"));
	L.push_back(string("@"));
	L.push_back(string("B"));
	L.push_back(string("@"));
	L.push_back(string("@"));
	L.push_back(string("G"));
	L.push_back(string("A"));
	L.push_back(string("@"));
	L.push_back(string("@"));
	L.push_back(string("N"));
	L.push_back(string("J"));
	L.push_back(string("@"));
	L.push_back(string("@"));
	L.push_back(string("K"));
	L.push_back(string("@"));
	L.push_back(string("@"));

	cout << endl << "Llenamos el árbol con la siguiente cadena: " 
	     << endl << L << endl << endl;

	convStrToStrX cnvSSX;
	llenaArbolFromList(A, L, cnvSSX);

	cout << "Recorrido inorder:" << endl;
	A.inorder();
	cout << endl << endl;

	cout << "Recorrido preorder:" << endl;
	A.preorder();
	cout << endl << endl;

	cout << "Recorrido posorder:" << endl;
	A.posorder();
	cout << endl << endl;

	convStrXToStr cnvSXS;
	generaDescripcion(A, descArbol, cnvSXS);

	cout << "Generamos una descripción del árbol binario:" << endl
	     << descArbol << endl << endl;

	return 0;
}