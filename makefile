
all: Painting_Graph

Painting_Graph: main.o Graph.o 
	g++ main.o Graph.o -o Painting_Graph
main.o: main.cpp
	g++ -c main.cpp 
Graph.o: Graph.cpp
	g++ -c Graph.cpp
