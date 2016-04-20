zad3: main.o
	g++ -o zad3 main.o lista.o stoper.o kolejka.o sort.o
main.o: interfejs.hh interfejsk.h kolejka.hh lista.hh sort.hpp stoper.h kolejka.cpp lista.cpp stoper.cpp main.cpp sort.cpp
	g++ -c main.cpp lista.cpp stoper.cpp kolejka.cpp sort.cpp
lista.o: lista.cpp lista.h interfejs.h
	g++ -c lista.cpp
stoper.o: stoper.cpp stoper.h
	g++ -c stoper.cpp
kolejka.o: kolejka.cpp lista.h kolejka.hh interfejsk.h
	g++ -c kolejka.cpp
sort.o: sort.cpp sort.hpp
	g++ -c sort.cpp
make clean:
	rm *.o zad3
