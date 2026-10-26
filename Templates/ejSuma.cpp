#include <iostream>

using namespace std;

template <typename X>
X suma(X a, X b)
{
	return a+b;
}

int main()
{
	int a=5, b=7;
	float p=3.1416, e=2.71;

	cout << endl << "La suma de " << a << " y " << b << " es "
	     << suma(a, b) << endl;
	cout << endl << "La suma de " << p << " y " << e << " es "
	     << suma(p, e) << endl;
	return 0;
}