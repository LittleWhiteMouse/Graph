#include<iostream>
#include "Graph.h"
using namespace std;
int main(int argc, char** argv) {
	Graph gra(11);
	gra.addEdge(0, 2);
	gra.addEdge(2, 1);
	gra.addEdge(1, 0);
	gra.addEdge(1, 5);
	gra.addEdge(5, 3);
	gra.addEdge(4, 5);
	gra.addEdge(3, 4);
	gra.addEdge(6, 4);
	gra.addEdge(6, 8);
	gra.addEdge(8, 9);
	gra.addEdge(9, 7);
	gra.addEdge(7, 6);
	gra.addEdge(7, 10);

	gra.getSCC();

	system("pause");
	return 0;

}