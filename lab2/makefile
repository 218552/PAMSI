p: obj/main.o
	g++ obj/main.o -o p
obj/main.o: src/main.cpp
	g++ -Wall -pedantic -std=c++11 -c src/main.cpp -o obj/main.o
clean:
	rm -r obj/main.o p
delete:
	rm -r src/main.cpp~ 
