INC=-I./include
LIN=-L./build

all: Polinomial.a Pol
	g++ $(INC) $(LIN) build/Pol.o -lPolinomial -o build/Polinomial

Pol: Pol.cpp
	g++ $(INC) Pol.cpp -c -o build/Pol.o

Polinomial.a: Polinomial
	ar rcs build/libPolinomial.a build/Polinomial.o

Polinomial: include/Polinomial.h src/Polinomial.cpp
	g++ $(INC) src/Polinomial.cpp -c -o build/Polinomial.o

clean:
	rm -rf build/*
