#include <ArbolBinario.h>
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


struct convStrToFloat: public convertFromStringToX<float>
{
	float operator() (string s)
	{
		return stof(s);
	}
};

struct convFloatToStr: public convertFromXToString<float>
{
	string operator() (const float &val)
	{
		return to_string(val);
	}
};

int main(int argc, char **argv)
{
	arbolBinario<int> Ai;
	arbolBinario<float> Af;
	string descArbol;
	string Ci = "12,-5,8,@,234,@,@,-56,@,@,2,1,@,@,35,22,@,@,94,@,@";
	string Cf = "3.26,-12.6,15.4,@,4.45,@,@,-66,@,@,2.1,0.012,@,@,3.4e5,22.2e-2,@,@,94.12,@,@";

	cout << endl << "Llenamos el árbol con la siguiente cadena de números enteros: " 
	     << endl << Ci << endl << endl;

	convStrToInt cnvS2I;
	llenaArbol(Ai, Ci, ',', cnvS2I);

	cout << "Recorrido inorder:" << endl;
	Ai.inorder();
	cout << endl << endl;

	cout << "Recorrido preorder:" << endl;
	Ai.preorder();
	cout << endl << endl;

	cout << "Recorrido posorder:" << endl;
	Ai.posorder();
	cout << endl << endl;

	convIntToStr cnvI2S;
	generaDescripcion(Ai, descArbol, ',', cnvI2S);

	cout << "Generamos una descripción del árbol binario de enteros:" << endl
	     << descArbol << endl << endl;

	cout << "---------------------------------------"
         << "---------------------------------------" << endl;

	 cout << endl << "Llenamos el árbol con la siguiente cadena de números flotantes: " 
	     << endl << Cf << endl << endl;

	convStrToFloat cnvS2F;
	llenaArbol(Af, Cf, ',', cnvS2F);

	cout << "Recorrido inorder:" << endl;
	Af.inorder();
	cout << endl << endl;

	cout << "Recorrido preorder:" << endl;
	Af.preorder();
	cout << endl << endl;

	cout << "Recorrido posorder:" << endl;
	Af.posorder();
	cout << endl << endl;

	convFloatToStr cnvF2S;
	generaDescripcion(Af, descArbol, ',', cnvF2S);

	cout << "Generamos una descripción del árbol binario de enteros:" << endl
	     << descArbol << endl << endl;

	return 0;
}