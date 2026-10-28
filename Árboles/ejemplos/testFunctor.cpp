#include <iostream>
#include <string>

using namespace std;

template <typename X>
struct convertXToString
{
	virtual string operator () (X &val)
	{
		return string();
	}
};

struct convertIntToString:public convertXToString<int>
{
	string operator () (int &val)
	{
		return to_string(val);
	}
};

template <typename X>
struct Dummy
{
	void Conversion(X val, convertXToString<X> &cnv)
	{
		cout << "Dummy: " << cnv(val) << endl;
	}
};

int main()
{
	string Numero("123.45"), out;
	int a = 145;

	convertXToString<string> genericConversor;
	convertIntToString intConversor;

	out = genericConversor(Numero);

	cout << endl << "Numero: " << Numero << endl;

	cout << endl << "out   : " << out    << endl;

	out = intConversor(a);

	cout << endl << "a   : " << a   << endl;

	cout << endl << "out : " << out << endl << endl;


	Dummy<string> DS;
	Dummy<int> DI;


	DS.Conversion("015", genericConversor);
	cout << endl;

	DI.Conversion(234, intConversor);

	return 0;
}