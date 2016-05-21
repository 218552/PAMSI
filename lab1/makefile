p: obj/main.o obj/funkcje.o
	g++ obj/main.o obj/funkcje.o -o p
obj/main.o: src/main.cpp inc/funkcje.hpp
	g++ -Iinc -Wall -pedantic -std=c++11 -c src/main.cpp -o obj/main.o
obj/funkcje.o: src/funkcje.cpp inc/funkcje.hpp
	g++ -Iinc -Wall -pedantic -std=c++11 -c src/funkcje.cpp -o obj/funkcje.o
clean:
	rm -r obj/main.o obj/funkcje.o p
delete:
	rm -r src/main.cpp~ src/funkcje.cpp~
