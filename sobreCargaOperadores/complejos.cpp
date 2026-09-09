#include <iostream>

using namespace std;

/******************************************************************************
*  Esta clase la utilizamos para ejemplificar el                              *
*  uso de la sobrecarga de operadores.                                        *
*                                                                             *
*  Define una estructura para almacenar números complejos y define métodos    *
*  para operar aritméticamente entre ellos. Falta definir un operador para    *
*  conjugación.                                                               *
******************************************************************************/
struct complejo
{
	//Atributos

	double re; // Componente real del número complejo.
	double im; // Componente imaginario del número complejo.

	//Métodos

	// Constructor por defecto.
	complejo()
	{
		re = im = 0;
	}
	
	// Constructor básico.
	complejo (double r, double i)
	{
		re = r;
		im = i;
	}

	// Constructor de copia.
	complejo(const complejo &c)
	{
		re = c.re;
		im = c.im;
	}
	
	// método que suma el número complejo b al
	// número complejo almacenado en el objeto que invoca.
	complejo suma(complejo b)
	{
		complejo c;
		c.re = re + b.re;
		c.im = im + b.im;
		return c;
	}

	// Método que suma el valor numérico b al
	// número complejo almacenado en el objeto que invoca.
	template <typename T>
	complejo suma(T b)
	{
		complejo c(*this);
		c.re += (double)b;
		return c;
	}

	// Método que suma el valor numérico b al
	// número complejo almacenado en el objeto que invoca.
		template <typename T>
	complejo resta(T b)
	{
		complejo c(*this);
		c.re -= (double)b;
		return c;
	}

	// Multiplica el número complejo almacenado en el objeto que
	// invoca por un número complejo que se pasa como parámetro.
	complejo multiplica(complejo y)
	{
		complejo c;
		c.re = re * y.re - im * y.im;
		c.im = re * y.im + im * y.re;
		return c;
	}

	
	// Divide el número complejo almacenado en el objeto que
	// invoca entre un número complejo que se pasa como parámetro.
	complejo divide(complejo z)
	{
		double den;
		
		den = z.re * z.re + z.im * z.im;
		if (den != 0)
		{
			complejo num;

			den = 1./den;
			num = *this * complejo(z.re, -z.im) * den;
			return num;
		}
		else
		{
			cerr << "Error en operator/ en struct complejo: denominador igual a 0."<< endl;
			cerr.flush();
			exit(1);
		}
	}

	
	// Método que divide el número complejo almacenado en el objeto que
	// invoca entre el valor numerico 'd' se se pasa como parámetro.
	template <typename T>
	complejo divide(T d)
	{
		if ((double)d != 0)
		{
			complejo num;

			num.re /= (double)d;
			num.im /= (double)d;
			return num;
		}
		else
		{
			cerr << "Error en operator/ en struct complejo: denominador igual a 0."<< endl;
			cerr.flush();
			exit(1);
		}
	}

	// Sobrecarga del operador '+' entre números complejos.
	complejo operator +(complejo &b)
	{
		complejo c;
		c.re = re + b.re;
		c.im = im + b.im;
		return c;
	}

	// Sobrecarga del operador '+' con un numérico.
	template <typename T>
	complejo operator +(T b)
	{
		complejo c(*this);
		c.re += b;
		return c;
	}

	// Sobrecarga del operador '-' entre números complejos.
	complejo operator -(complejo b)
	{
		complejo c;
		c.re = re - b.re;
		c.im = im - b.im;
		return c;
	}

	// Sobrecarga del operador '-' con un valor numérico.
	template <typename T>
	complejo operator -(T b)
	{
		complejo c(*this);
		c.re -= (double)b;
		return c;
	}


	// Sobrecarga del operador '*' entre números complejos.
	complejo operator *(complejo y)
	{
		complejo c;
		c.re = re * y.re - im * y.im;
		c.im = re * y.im + im * y.re;
		return c;
	}

	// Sobrecarga del operador '*' con un valor numérico.
	template <typename T>
	complejo operator *(T v)
	{
		complejo c;
		c.re = re * (double)v;
		c.im = im * (double)v;
		return c;
	}

	// Sobrecarga el operador '/' entre números complejos.
	complejo operator /(complejo z)
	{
		double den;
		
		den = z.re * z.re + z.im * z.im;
		if (den != 0)
		{
			complejo num;

			den = 1./den;
			num = *this * complejo(z.re, -z.im) * den;
			return num;
		}
		else
		{
			cerr << "Error en operator/ en struct complejo: denominador igual a 0."<< endl;
			cerr.flush();
			exit(1);
		}
	}

	// Sobrecarga el operador '/' con un valor numérico.
	template <typename T>
	complejo operator /(T d)
	{
		if ((double)d != 0.)
		{
			complejo num;

			num.re /= (double)d;
			num.im /= (double)d;
			return num;
		}
		else
		{
			cerr << "Error en operator/ en struct complejo: denominador igual a 0."<< endl;
			cerr.flush();
			exit(1);
		}
	}

	// Imprime el numero complejo
	void imprime()
	{
		cout << re;
		if (im > 0.)
			cout << " + " << im << "i";
		else if (im < 0)
				cout << " - " << -im << "i"; 
	}
};


// Sobrecarga del operador '+' con un número tipo T
template <typename T>
complejo operator +(T b, complejo &x)
{
	return x + b;
}

// Sobrecarga del operador '-' con un número tipo T
template <typename T>
complejo operator -(T b, complejo &x)
{
	complejo c(x); 
	c.re -= (double)b;
	return x - b;
}

// Sobrecarga del operador '*' con un número tipo T
template <typename T>
complejo operator *(T b, complejo &x)
{
	return x * b;
}

// Sobrecarga del operador '/' con un número tipo T
template <typename T>
complejo operator /(T b, complejo &x)
{
	return complejo((double)b, 0) / x;
}

//Sobrecargamos el operador <<
ostream &operator<< (ostream &os, complejo &z)
{
	os << z.re;
	if (z.im > 0.)
		os << " + " << z.im << "i";
	else if (z.im < 0)
			os << " - " << -z.im << "i";
	return os;
}


int main()
{
	complejo A(2,3), B(5,6), C, D;

	cout << "El valor A = " << A << endl<< endl;

	cout << "El valor B = " << B << endl<< endl;


	cout << "Despues de evaluar esto: C = A + B y D = A * B" << endl << endl;

	C = A + B;
	D = A * B;

	cout << "El valor C = " << C << endl<< endl;

	cout << "El valor D = " << D << endl<< endl;


	cout << "Despues de evaluar esto: A = D + B + C" << endl << endl;

	A = D + B + C;

	cout << "El valor A = " << A << endl<< endl;


	cout << "Despues de evaluar esto: B = C * 1.5" << endl << endl;

	B = C * 1.5;

	cout << "El valor B = " << B << endl<< endl;


	cout << "Despues de evaluar esto: D = B / A" << endl << endl;

	D = B / A;

	cout << "El valor D = " << D << endl<< endl;

	B = 0.5 - B;

	cout << "Despues de evaluar esto: B = 0.5 - B " << endl << endl;

	cout << "El valor B = " << B << endl<< endl;

	B = 2 * B;

	cout << "Despues de evaluar esto: B = 2 * B " << endl << endl;

	cout << "El valor B = " << B << endl<< endl;

	C = 1.25 / B;

	cout << "Despues de evaluar esto: C = 1.25 / B " << endl << endl;

	cout << "El valor C = " << C << endl<< endl;
}