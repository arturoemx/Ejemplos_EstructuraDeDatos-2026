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

	void _inorder(nodoA<X> *r)
	{
		if (r == nullptr)
			return;
		_inorder(r->izq);
		cout << r->dato << " ";
		_inorder(r->der);
	}

	void _preorder(nodoA<X> *r)
	{
		if (r == nullptr)
			return;
		cout << r->dato << " ";
		_preorder(r->izq);
		_preorder(r->der);
	}

	void _posorder(nodoA<X> *r)
	{
		if (r == nullptr)
			return;
		_posorder(r->izq);
		_posorder(r->der);
		cout << r->dato << " ";
		cout << " ";
	}
};


/*******************************************************************************
 *******************************************************************************
 *                           FUNCIONES MISCELANEAS                             *
 *                                                                             *
 * Las siguientes funciónes nos permiten llenar el árbol a partir de descripc- *
 * iónes de la  información contenida en el  árbol codificada en una cadena de *
 * caracteres (std::string).                                                   *
 *                                                                             *
 * Dicha descripcion se  almacena como una  cadena de caracteres (std::string) *
 * que utiliza un caracter como separador.  Por ejemplo la cadena:             *
 *                                                                             *
 *                  "5,3,@,9,@,13,@,@,@,16,8,@,@,7,@,@"                        *
 *                                                                             * 
 *  donde  las  arrobas  representan  ligas  nulas,  representa  el  recorrido *
 *  preorder del siguiente árbol:                                              *
 *                                                                             * 
 *                                 raiz                                        *
 *                                  |                                          *
 *                              ____5____                                      *
 *                             /         \                                     *
 *                           _3_         _16_                                  *
 *                          /   \       /    \                                 *
 *                         @     9      8     7                                *
 *                              /      / \   / \                               *
 *                             13     @   @ @   @                              *
 *                            /  \                                             *
 *                           @    @                                            *
 *                                                                             *
 * También se definen funciónes que  vuelcan un  árbol existente en una cadena *
 * descriptiva, o sea, lo inverso de la funcion de llenado.                    *
 *                                                                             * 
 * También se  definen dos  plantillas de functores que se deben utilizar como *
 * estructura base para que a través de  herencia  se definan nuevos functores *
 * que conviertan de un  tipo dado a cadena y viceversa.                       * 
 *                                                                             * 
 *  Dichos functores base son:                                                 *
 *                                                                             * 
 *  - template <typename X> struct convertToX {....};                          *
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


nodoA<string> *_llenaArbol(string &S, nodoA<string> *p, char sep)
{
	string token;

	token = extractToken(S, sep);
	if (token.length() > 0)
	{
		nodoA<string> *nA;

		if (token == "@")
			return (nodoA<string> *)nullptr;

		nA = creaNodoArbol(token);
		nA->izq = _llenaArbol(S, nA, sep);
		nA->der = _llenaArbol(S, nA, sep);
		nA->padre = p;
		return nA;
	}
	else
	{
		cerr << "Error: cadena de definicion mal formada." << endl;
		exit(1);
	}
}

void llenaArbol(arbolBinario<string> &A, string S, char sep)
{
	A.borraArbol();
	A.raiz = _llenaArbol(S, (nodoA<string> *)nullptr, sep);
}

void _generaDescripcion(nodoA<string> *r, string &C, const string &sep)
{
	if (r == (nodoA<string> *)nullptr)
		C.append("@").append(sep);
	else
	{
		C.append(r->dato).append(sep);
		_generaDescripcion(r->izq, C, sep);
		_generaDescripcion(r->der, C, sep);
	}
}

void generaDescripcion(arbolBinario<string> &A, string &C, string sep)
{
	size_t l;

	C.clear();
	_generaDescripcion(A.raiz, C, sep);
	l = C.length();

	//Eliminamos el último caracter que es un separador.
	if (l > 1)
		C = C.substr(0, l-1);
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
void llenaArbol(arbolBinario<X> &A, string S, char sep, convertFromStringToX<X> &cnv)
{
	A.borraArbol();
	A.raiz = _llenaArbol(S, (nodoA<X> *)nullptr, sep, cnv);
}

template <typename X>
nodoA<X> *_llenaArbol(string &S, nodoA<X> *p, char sep, convertFromStringToX<X> &cnv)
{
	string token;

	token = extractToken(S, sep);
	if (token.length() > 0)
	{
		nodoA<X> *nA;
		X val;

		if (token == "@")
			return (nodoA<X> *)nullptr;
		val = cnv(token);
		nA = creaNodoArbol(val);
		nA->izq = _llenaArbol(S, nA, sep, cnv);
		nA->der = _llenaArbol(S, nA, sep, cnv);
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
void generaDescripcion(arbolBinario<X> &A, string &C, char sep, convertFromXToString<X> &cnv)
{
	size_t l;
	string separator(1, sep);

	C.clear();
	_generaDescripcion(A.raiz, C, separator, cnv);
	l = C.length();

	//Eliminamos el último caracter que es un separador.
	if (l > 1)
		C = C.substr(0, l-1);
}

template <typename X>
void _generaDescripcion(nodoA<X> *r, string &C, const string sep, convertFromXToString<X> &cnv)
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

#endif