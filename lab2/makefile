p: obj/main.o obj/interfejs.o
	g++ obj/main.o obj/interfejs.o -o p
obj/main.o: src/main.cpp inc/interfejs.hpp
	g++ -Iinc -Wall -pedantic -std=c++11 -c src/main.cpp -o obj/main.o
obj/interfejs.o: src/interfejs.cpp inc/interfejs.hpp
	g++ -Iinc -Wall -pedantic -std=c++11 -c src/interfejs.cpp -o obj/interfejs.o
clean:
	rm -r obj/main.o obj/interfejs.o p
delete:
	rm -r src/main.cpp~ src/interfejs.cpp~
