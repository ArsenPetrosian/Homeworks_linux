all: Polinomial Pol
	g++ build/Polinomial.o build/Pol.o -o build/Polinomial

Pol: ../Pol.cpp
	g++ ../Pol.cpp -c -o build/Pol.o

Polinomial: ../Polinomial.h ../Polinomial.cpp
	g++ ../Polinomial.cpp -c -o build/Polinomial.o

clean:
	rm -rf build/*
