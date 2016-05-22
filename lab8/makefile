p: obj/main.o obj/list.o obj/graph.o obj/queue.o
	g++ -o p -g obj/main.o obj/list.o obj/graph.o obj/queue.o
obj/main.o: src/main.cpp inc/stoper.hpp inc/graph.hpp inc/vertex.hpp inc/node.hpp inc/list.hpp inc/queue.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/list.o: src/list.cpp inc/node.hpp inc/list.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/list.cpp -o obj/list.o
obj/graph.o: src/graph.cpp inc/vertex.hpp inc/list.hpp inc/graph.hpp inc/queue.hpp inc/path.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/graph.cpp -o obj/graph.o
obj/queue.o: src/queue.cpp inc/node.hpp inc/list.hpp inc/queue.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/queue.cpp -o obj/queue.o
clean:
	rm -r obj/*.o p
