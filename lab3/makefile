p: obj/main.o obj/list.o obj/stack.o obj/queue.o
	g++ -o p obj/main.o obj/list.o obj/stack.o obj/queue.o 
obj/main.o: src/main.cpp src/list.cpp src/stack.cpp src/queue.cpp inc/list.hpp inc/stack.hpp inc/node.hpp inc/queue.hpp inc/stoper.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/list.o: src/list.cpp inc/list.hpp inc/node.hpp
	g++ -c -Wall -pedantic -std=c++11 src/list.cpp -o obj/list.o
obj/stack.o: src/stack.cpp inc/stack.hpp inc/node.hpp inc/list.hpp
	g++ -c -Wall -pedantic -std=c++11 src/stack.cpp -o obj/stack.o
obj/queue.o: src/queue.cpp inc/queue.hpp inc/node.hpp inc/list.hpp
	g++ -c -Wall -pedantic -std=c++11 src/queue.cpp -o obj/queue.o
clean: 
	rm -r obj/*.o p