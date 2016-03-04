p: tablica_dynamiczna.o
	g++ tablica_dynamiczna.o -o p
tablica_dynamiczna.o: tablica_dynamiczna.cpp
	g++ -Wall -pedantic -std=c++11 -c tablica_dynamiczna.cpp 
clean:
	rm -r tablica_dynamiczna.o p
delete:
	rm -r tablica_dynamiczna.cpp~ 
