#include <iostream>
#include <iomanip>
#include <Pila.h>

using namespace std;

enum hanoiCall {None=0, first, second, third, fourth, fifth};

struct hanoiState
{
	char a, b, c;
	unsigned int n;
	hanoiCall hC;

	hanoiState(char _a, char _b, char _c, unsigned int _n, hanoiCall _hC)
	{
		a = _a;
		b = _b;
		c = _c;
		n = _n;	
		hC = _hC;
	}
	hanoiState()
	{
		a = b = c = ' ';
		n = 0;
		hC =  None;		
	}
};

ostream &operator<<(ostream &s, hanoiState h)
{
	s << "State [" << h.a << ", " << h.b << ", " << h.c << ", " << h.n;
	switch (h.hC)
	{
	 	case first: 
	 		s << ", first  ]";
	 		break;
	 	case second:
	 		s << ", second ]";
	 		break;
	 	case third:
	 		s << ", third  ]";
	 		break;
	 	case fourth:
	 		s << ", fourth ]";
	 		break;
	 	case fifth:
	 		s << ", fifth ]";
	 		break;
	 	default:
	 		s << ", None   ]";
	}
	return s;
}

void HanoiI(char a, char b, char c, unsigned int N)
{
	Pila<hanoiState> pila((N+1));
	hanoiState *current;

	pila.push(hanoiState(a, b, c, N, first));
	do
	{
		current = &(pila.P[pila.SP-1]); // o current = pila.P + pila.SP - 1;
		switch(current->hC)
		{
			case first:
				if (current->n > 0)
					current->hC = second;
				else
					current->hC = fifth;
				break;
			case second:
				pila.push(hanoiState(current->a, current->c, current->b, current->n-1, first));
				break;
			case third:
				cout << right << std::setw(3) << setfill('0') << current->n  //Third->Fourth
		     		 << ": " << current->a << " -> " << current->b << endl;
		     	current->hC = fourth;
		     	break;
		    case fourth:
		    	pila.push(hanoiState(current->c, current->b, current->a, current->n-1, first));
		    	break;
		    case fifth:
		    	if (pila.SP > 1)
		    	{
		    		hanoiState *previous;

		    		previous = &(pila.P[pila.SP-2]);
		    		switch(previous->hC)
		    		{
		    			case second: previous->hC = third; break;
		    			case fourth: previous->hC = fifth; break;
		    			case first:  previous->hC = first; break;
		    			default:break;
		    		}
		    	}
		    	pila.pop();
		    	break;
		    default:break;
		}
	} while (pila.vacia() != true);
}

void HanoiR(char a, char b, char c, unsigned int N)
{
	if (N>0)  //First -> Second or First->Fifth
	{
		HanoiR (a, c, b, N - 1); //Second -> First
		cout << right << std::setw(3) << setfill('0') << N  //Third->Fourth
		     << ": " << a << " -> " << b << endl;
		HanoiR (c, b, a, N - 1);//Fourt->First
	}
} //Fifth: if prev->hC == Second, curr->hC = Third
  //       if prev->hC == Fourth, curr-> = Fifth
  //       if prev->hC == First, curr-> = First



int main(int argc, char **argv)
{
	unsigned int n;

	if (argc<2)
		n = 3;
	else
		n = (unsigned int)atoi(argv[1]);

	cout << endl << endl << "Hanoi Recursivo." << endl << endl;

   HanoiR('A', 'B', 'C', n);

   cout << endl << endl << "Hanoi Iterativo." << endl << endl;

   HanoiI('A', 'B', 'C', n);

   cout << endl << endl;

	return 0;
}
