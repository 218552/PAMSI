p: obj/main.o
	g++ -o p obj/main.o
obj/main.o: src/main.cpp inc/stoper.hpp inc/graf.hpp inc/vertex.hpp inc/edge.hpp
	inc/node.hpp inc/list.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/list.o: src/list.cpp inc/node.hpp inc/list.hpp 
		g++ -Iinc -c -Wall -pedantic -std=c++11 src/list.cpp -o obj/list.o
clean:
	rm -r obj/*.o p
