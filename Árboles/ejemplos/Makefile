TOPDIR = ..

INCLUDEDIR = $(TOPDIR)/include

HEADERS = $(INCLUDEDIR)/ArbolBinario.h $(INCLUDEDIR)/nodoA.h

CXXFLAGS = -Wall -g -I $(INCLUDEDIR)

all: pruebaArbolBinarioLista pruebaArbolBinarioMiLista pruebaArbolBinarioNumeros pruebaArbolBinarioCadena pruebaArbolBinarioPoema testFunctor

pruebaArbolBinarioMiLista:pruebaArbolBinarioMiLista.cpp $(HEADERS) $(INCLUDEDIR)/nodoD.h $(INCLUDEDIR)/listaD.h
	g++ $(CXXFLAGS) -o pruebaArbolBinarioMiLista pruebaArbolBinarioMiLista.cpp

pruebaArbolBinarioNumeros:pruebaArbolBinarioNumeros.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioNumeros pruebaArbolBinarioNumeros.cpp

pruebaArbolBinarioLista:pruebaArbolBinarioLista.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioLista pruebaArbolBinarioLista.cpp

pruebaArbolBinarioCadena:pruebaArbolBinarioCadena.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioCadena pruebaArbolBinarioCadena.cpp

pruebaArbolBinarioPoema:pruebaArbolBinarioPoema.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioPoema pruebaArbolBinarioPoema.cpp

testFunctor:testFunctor.cpp
	g++ $(CXXFLAGS) -o testFunctor testFunctor.cpp

clean:
	rm pruebaArbolBinarioLista pruebaArbolBinarioMiLista pruebaArbolBinarioNumeros pruebaArbolBinarioCadena pruebaArbolBinarioPoema testFunctor