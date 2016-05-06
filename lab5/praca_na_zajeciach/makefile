p: obj/main.o obj/list.o
	g++ -o p obj/main.o obj/list.o 
obj/main.o: src/main.cpp src/list.cpp p inc/list.hpp inc/node.hpp 
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/list.o: src/list.cpp inc/list.hpp inc/node.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/list.cpp -o obj/list.o
clean: 
	rm -r obj/*.o p