#ifndef __ARBOL_BINARIO__
#define __ARBOL_BINARIO__

#include <iostream>
#include <nodoA.h>
#include <listaD.h>
#include <list>
#include <string>

using namespace std;


template <typename X>
nodoA < X > *creaNodoArbol (X & val)
{
	nodoA < X > *n;

	n = new nodoA (val);
	if (n == nullptr)
	{
		cerr << "Error en arbolBinario::creaNodo: no hay memoria." << endl;
		cerr.flush ();
		return nullptr;
	}
	return n;
}

template <typename X>
struct arbolBinario
{
	nodoA<X> *raiz;

	arbolBinario()
	{
		raiz = nullptr;
	}

	void borraArbol()
	{
	}

	void inorder()
	{
		if (raiz != nullptr)
			_inorder(raiz);
	}

	void preorder()
	{
		if (raiz != nullptr)
			_preorder(raiz);
	}

	void posorder()
	{
		if (raiz != nullptr)
			_posorder(raiz);
	}

	void _inorder(nodoA<string> *r)
	{
		if (r == nullptr)
			return;
		_inorder(r->izq);
		cout << r->dato << " ";
		_inorder(r->der);
	}

	void _preorder(nodoA<string> *r)
	{
		if (r == nullptr)
			return;
		cout << r->dato << " ";
		_preorder(r->izq);
		_preorder(r->der);
	}

	void _posorder(nodoA<string> *r)
	{
		if (r == nullptr)
			return;
		_posorder(r->izq);
		_posorder(r->der);
		cout << r->dato << " ";
		cout << " ";
	}

	void _inorder(nodoA<int> *r)
	{
		if (r == nullptr)
			return;
		_inorder(r->izq);
		cout << r-> dato << " ";
		_inorder(r->der);
	}

	void _preorder(nodoA<int> *r)
	{
		if (r == nullptr)
			return;
		cout << r-> dato << " ";
		_preorder(r->izq);
		_preorder(r->der);
	}

	void _posorder(nodoA<int> *r)
	{
		if (r == nullptr)
			return;
		_posorder(r->izq);
		_posorder(r->der);
		cout << r-> dato << " ";
	}
};


/*******************************************************************************
 *******************************************************************************
 *                           FUNCIONES MISCELANEAS                             *
 *                                                                             *
 * Las Siguientes funciónes nos permiten llenar el arbol a partir de descripc- *
 * iónes de la  información contenida en el  árbol codificada en una cadena de *
 * caracteres (std::string).                                                   *
 *                                                                             *
 * Dichas Descripciones estan almacenadas en una listaD<string>, como la vista *
 * en clase, una lista estandar (std::list<string>) y una cadena de caracteres *
 * (std::string) que utiliza un caracter como separador.                       *
 *                                                                             *
 * Tambien Se definen funciónes que vuelcan un árbol existente en una descrip- *
 * ción,  almacenada  en  una  listaD<string>,  o  una std::list<string> y una *
 * std::string.                                                                *
 *                                                                             * 
 * También se  definen dos  plantillas de functores que se deben utilizar como *
 * estructura base                                                             *
 * para que a través de  herencia  se definan functores que  conviertan de  un *
 * tipo dado a cadena y viceversa. Dichos functores base son:                  *
 *                                                                             * 
 *  - template <typename X> struct convertFromStringToX {....};                *
 *  - template <typename X> struct convertFromXStringTo {....};                *
 *                                                                             *
 *                                                                             *
 * Ademas, se definen dos funciones auxiliares:                                *
 *                                                                             *
 *   - printString: Imprime una cadena de caracteres  sustituyendo  caracteres * 
 *                  imprimibles como el salto de  linea, el regreso de carro y *
 *                  tabulador por su representación usando secuencias de esca- *
 *                  pe, \n, \r, \t, respectivamente.                           *
 *                                                                             *
 *   - extractToken: Extrae 'tokens' de una cadena de caracteres, dividida por *
 *                   un caracter separador.                                    *
 *                                                                             *
 *******************************************************************************
 ******************************************************************************/


/*!
\fn void printString(string &S)
\brief Imprime en stdout una cadena de caracteres, transformando caracteres no
       imprimibles, como salto de linea, retorno de carro, tabulador a su
       representación con secuencias de escape: \n', \r, \t, respectivamente.
\param const string &S -> Secuencia de caracteres a ser impresa.
*/
void printString(string &S)
{
	size_t idx, n;

	n = S.length();
	for (idx = 0; idx < n; ++idx)
		switch(S[idx])
		{
			case '\n':		
				cout << "\\n";
				break;
			case '\t':		
				cout << "\\t";
				break;
			case '\r':		
				cout << "\\r";
				break;
			default:
				cout << S[idx];
		}
}

/*!
\fn string extractToken(string &S, string sep=",")
\brief Extrae un 'token' de una cadena de caracteres.
       Se entiende que la cadena de caracteres está construida
       como una secuencias de sub-cadenas, separadas entre si
       por un separador. A cada una de esas sub-cadenas se lo
       conoce como un 'token'.
\param string &S  -> La cadena de la cual se van a extraer los 'tokens'.
                     La cadena es modificada por la función.
\param string sep -> Cadena de caracteres que contiene el separador.
\return La función regresa una cadena de caracteres que contiene el 'token' extraido.
*/
string extractToken(string &S, char sep=',')
{
	size_t idx;

	idx = S.find(sep);
	if (idx != string::npos)
	{
		string s;

		s = S.substr(0, idx);
		S.erase(0, idx + 1);
		return s;
	}
	return S;
}

template <typename X=string>
struct convertFromStringToX
{
	virtual X operator()(string s) = 0;
};

template <typename X=string>
struct convertFromXToString
{
	virtual string operator()(const X &val) = 0;
};

template <typename X>
void llenaArbolFromListaD(arbolBinario<X> &A, listaD<string> &L, convertFromStringToX<X> &cnv)
{
	A.borraArbol();
	A.raiz = _llenaArbolFromListaD(L.raiz, (nodoA<X> *)nullptr, cnv);
}

template <typename X>
nodoA<X> *_llenaArbolFromListaD(nodoD<string> *&n, nodoA<X> *p, convertFromStringToX<X> &cnv)
{
	if (n != nullptr)
	{
		nodoA<X> *nA;
		X val;

		if (n->dato == "@")
			return (nodoA<X> *)nullptr;
		
		val = cnv(n->dato);
		nA = creaNodoArbol(val);
		n = n->sig;
		nA->izq = _llenaArbolFromListaD(n, nA, cnv);
		n = n->sig;
		nA->der = _llenaArbolFromListaD(n, nA, cnv);
		nA->padre = p;
		return nA;
	}
	else
	{
		cerr << "Error: lista de definicion mal formada." << endl;
		exit(1);
	}
}

template <typename X>
void llenaArbolFromList(arbolBinario<X> &A, list<string> &L, convertFromStringToX<X> &cnv)
{
	list<string>::iterator r = L.begin(), end = L.end();
	A.borraArbol();
	A.raiz = _llenaArbolFromList(r, end, (nodoA<X> *)nullptr, cnv);
}

template <typename X>
nodoA<X> *_llenaArbolFromList(list<string>::iterator &it, list<string>::iterator &end, nodoA<X> *p, convertFromStringToX<X> &cnv)
{
	if (it != end)
	{
		nodoA<X> *nA;
		X val;

		if (*it == "@")
			return (nodoA<X> *)nullptr;

		val = cnv(*it);
		nA = creaNodoArbol(val);
		nA->izq = _llenaArbolFromList(++it, end, nA, cnv);
		nA->der = _llenaArbolFromList(++it, end, nA, cnv);
		nA->padre = p;
		return nA;
	}
	else
	{
		cerr << "Error: lista de definicion mal formada." << endl;
		exit(1);
	}
}

template <typename X>
void llenaArbolFromString(arbolBinario<X> &A, string S, char sep, convertFromStringToX<X> &cnv)
{
	A.borraArbol();
	A.raiz = _llenaArbolFromString(S, (nodoA<X> *)nullptr, sep, cnv);
}

template <typename X>
nodoA<X> *_llenaArbolFromString(string &S, nodoA<X> *p, char sep, convertFromStringToX<X> &cnv)
{
	string token;

	token = extractToken(S, sep);
	if (token.length() > 0)
	{
		nodoA<X> *nA;

		if (token == "@")
			return (nodoA<X> *)nullptr;

		nA = creaNodoArbol(token);
		nA->izq = _llenaArbolFromString(S, nA, sep, cnv);
		nA->der = _llenaArbolFromString(S, nA, sep, cnv);
		nA->padre = p;
		return nA;
	}
	else
	{
		cerr << "Error: cadena de definicion mal formada." << endl;
		exit(1);
	}
}

template <typename X>
void generaDescripcion(arbolBinario<X> &A, string &C, string sep, convertFromXToString<X> &cnv)
{
	size_t l;

	C.clear();
	_generaDescripcion(A.raiz, C, sep, cnv);
	l = C.length();

	//Eliminamos el último caracter que es un separador.
	if (l > 1)
		C = C.substr(0, l-1);
}

template <typename X>
void _generaDescripcion(nodoA<X> *r, string &C, const string &sep, convertFromXToString<X> &cnv)
{
	if (r == (nodoA<X> *)nullptr)
		C.append("@").append(sep);
	else
	{
		C.append(cnv(r->dato)).append(sep);
		_generaDescripcion(r->izq, C, sep, cnv);
		_generaDescripcion(r->der, C, sep, cnv);
	}
}

template <typename X>
void generaDescripcion(arbolBinario<X> &A, listaD<string> &L, convertFromXToString<X> &cnv)
{
	L.borraLista();
	_generaDescripcion(A.raiz, L, cnv);
}

template <typename X>
void _generaDescripcion(nodoA<X> *r, listaD<string> &L, convertFromXToString<X> &cnv)
{
	if (r == (nodoA<X> *)nullptr)
		L.pushBack("@");
	else
	{
		L.pushBack(cnv(r->dato));
		_generaDescripcion(r->izq, L, cnv);
		_generaDescripcion(r->der, L, cnv);
	}
}

template <typename X>
void generaDescripcion(arbolBinario<X> &A, list<string> &L, convertFromXToString<X> &cnv)
{
	L.clear();
	_generaDescripcion(A.raiz, L, cnv);
}

template <typename X>
void _generaDescripcion(nodoA<X> *r, list<string> &L, convertFromXToString<X> &cnv)
{
	if (r == (nodoA<X> *)nullptr)
		L.push_back("@");
	else
	{
		L.push_back(cnv(r->dato));
		_generaDescripcion(r->izq, L, cnv);
		_generaDescripcion(r->der, L, cnv);
	}
}

#endif