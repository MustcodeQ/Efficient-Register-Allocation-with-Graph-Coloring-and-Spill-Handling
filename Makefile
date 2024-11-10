all: main

main: main.o register_allocator.o interference_graph.o spill_code.o utils.o
	g++ -o main main.o register_allocator.o interference_graph.o spill_code.o utils.o

main.o: main.cpp register_allocator.h
	g++ -c main.cpp

register_allocator.o: register_allocator.cpp register_allocator.h interference_graph.h
	g++ -c register_allocator.cpp

interference_graph.o: interference_graph.cpp interference_graph.h
	g++ -c interference_graph.cpp

spill_code.o: spill_code.cpp spill_code.h
	g++ -c spill_code.cpp

utils.o: utils.cpp utils.h
	g++ -c utils.cpp

clean:
	rm *.o main
