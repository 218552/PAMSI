p: main.o
	g++ main.o stack.o list.o -o p
main.o: inc/list.hpp inc/node.hpp inc/stack.hpp src/main.cpp src/list.cpp src/stack.cpp
	g++ -Wall -pedantic -std=c++11 -c src/list.cpp src/stack.cpp src/main.cpp 
stos.o: inc/list.hpp inc/node.hpp inc/stack.hpp src/stack.cpp
	g++ -Wall -pedantic -std=c++11 -c src/stack.cpp
list.o: inc/list.hpp inc/node.hpp inc/stack.hpp src/list.cpp
	g++ -Wall -pedantic -std=c++11 -c src/list
clean: 
	rm -r main.o stack.o list.o p
delete:
	rm -r main.cpp~ 