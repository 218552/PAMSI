p: obj/main.o obj/tree.o
	g++ -o p obj/main.o obj/tree.o
obj/main.o: src/main.cpp src/tree.cpp inc/tree.hpp inc/tree_node.hpp inc/stoper.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/tree.o: src/tree.cpp inc/tree.hpp inc/tree_node.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/tree.cpp -o obj/tree.o
clean:
	rm -r obj/*.o p
