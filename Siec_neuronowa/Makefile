CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x
test: obj obj/main.o obj/neuralnetwork.o obj/test.o
	g++ -Wall -pedantic -std=c++0x -o test obj/main.o obj/neuralnetwork.o obj/test.o
obj/main.o: src/main.cpp inc/test.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp
obj/neuralnetwork.o: inc/neuralnetwork.hh inc/ineuralnetwork.hh src/neuralnetwork.cpp
	g++ -c ${CXXFLAGS} -o obj/neuralnetwork.o src/neuralnetwork.cpp
obj/test.o: inc/test.hh inc/neuralnetwork.hh src/test.cpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp
clean:
	rm obj/*.o test
