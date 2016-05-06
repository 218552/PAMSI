p: obj/main.o obj/list.o obj/hash_table.o obj/assoc_table.o
	g++ -o p obj/main.o obj/list.o obj/hash_table.o obj/assoc_table.o
obj/main.o: src/main.cpp src/list.cpp inc/list.hpp inc/node.hpp inc/hash_table.hpp inc/assoc_table.hpp inc/stoper.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/main.cpp -o obj/main.o
obj/list.o: src/list.cpp inc/list.hpp inc/node.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/list.cpp -o obj/list.o
obj/hash_table.o: src/hash_table.cpp inc/hash_table.hpp inc/list.hpp inc/node.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/hash_table.cpp -o obj/hash_table.o
obj/assoc_table.o: src/assoc_table.cpp inc/hash_table.hpp inc/list.hpp inc/node.hpp inc/assoc_table.hpp
	g++ -Iinc -c -Wall -pedantic -std=c++11 src/assoc_table.cpp -o obj/assoc_table.o
clean: 
	rm -r obj/*.o p