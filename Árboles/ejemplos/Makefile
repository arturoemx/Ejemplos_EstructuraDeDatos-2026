TOPDIR = ..

INCLUDEDIR = $(TOPDIR)/include

HEADERS = $(INCLUDEDIR)/ArbolBinario.h $(INCLUDEDIR)/nodoA.h

CXXFLAGS = -Wall -g -I $(INCLUDEDIR)

all: pruebaArbolBinarioNumeros pruebaArbolBinarioCadena pruebaArbolBinarioPoema testFunctor

pruebaArbolBinarioNumeros:pruebaArbolBinarioNumeros.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioNumeros pruebaArbolBinarioNumeros.cpp

pruebaArbolBinarioCadena:pruebaArbolBinarioCadena.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioCadena pruebaArbolBinarioCadena.cpp

pruebaArbolBinarioPoema:pruebaArbolBinarioPoema.cpp $(HEADERS)
	g++ $(CXXFLAGS) -o pruebaArbolBinarioPoema pruebaArbolBinarioPoema.cpp

testFunctor:testFunctor.cpp
	g++ $(CXXFLAGS) -o testFunctor testFunctor.cpp

clean:
	rm pruebaArbolBinarioNumeros pruebaArbolBinarioCadena pruebaArbolBinarioPoema testFunctor