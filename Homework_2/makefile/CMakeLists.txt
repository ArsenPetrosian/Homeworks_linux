INC=-I./include

all: Polinomial Pol
   g++ $(INC) build/Polinomial.o build/Pol.o -o build/Polinomial

Pol: Pol.cpp
   g++ $(INC) Pol.cpp -c -o build/Pol.o

Polinomial: include/Polinomial.h src/Polinomial.cpp
   g++ $(INC) src/Polinomial.cpp -c -o build/Polinomial.o
   
clean:
   rm -rf build/*
