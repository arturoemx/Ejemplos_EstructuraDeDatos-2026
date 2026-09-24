all:  ejemploPilaB ejemploPila ejemploPilaH ejemploColaB ejemploCola ejemploColaH ejemploColaAlt

ejemploPila: ejemploPila.cpp include/arreglo.h include/Pila.h 
	g++ -Wall -I include -o ejemploPila ejemploPila.cpp

ejemploPilaB: ejemploPilaB.cpp include/PilaB.h
	g++ -Wall -I include -o ejemploPilaB ejemploPilaB.cpp

ejemploPilaH: ejemploPilaH.cpp include/arreglo.h include/PilaH.h
	g++ -Wall -I include -o ejemploPilaH ejemploPilaH.cpp

ejemploCola: ejemploCola.cpp include/arreglo.h include/Cola.h 
	g++ -Wall -I include -o ejemploCola ejemploCola.cpp

ejemploColaB: ejemploColaB.cpp include/ColaB.h
	g++ -Wall -I include -o ejemploColaB ejemploColaB.cpp

ejemploColaH: ejemploColaH.cpp include/arreglo.h include/ColaH.h
	g++ -Wall -I include -o ejemploColaH ejemploColaH.cpp

ejemploColaAlt: ejemploColaAlt.cpp include/arreglo.h include/ColaAlt.h 
	g++ -Wall -I include -o ejemploColaAlt ejemploColaAlt.cpp

clean:
	rm ejemploPilaB ejemploPila ejemploPilaH ejemploColaB ejemploCola ejemploColaH ejemploColaAlt
