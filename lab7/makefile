p: obj/main.o obj/list.o obj/graph.o
	g++ -o p -g obj/main.o obj/list.o obj/graph.o
obj/main.o: src/main.cpp inc/stoper.hpp inc/graph.hpp inc/vertex.hpp inc/node.hpp inc/list.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/list.o: src/list.cpp inc/node.hpp inc/list.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/list.cpp -o obj/list.o
obj/graph.o: src/graph.cpp inc/vertex.hpp inc/list.hpp inc/graph.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/graph.cpp -o obj/graph.o
clean:
	rm -r obj/*.o p
