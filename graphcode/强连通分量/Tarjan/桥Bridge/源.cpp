#include<iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char** argv) {
	Graph gra(8);
	gra.addEdge(0, 2);
	gra.addEdge(2, 1);
	gra.addEdge(3, 0);
	gra.addEdge(2, 4);
	gra.addEdge(4, 3);
	gra.addEdge(3, 7);
	gra.addEdge(7, 5);
	gra.addEdge(6, 7);
	gra.addEdge(6, 5);
	gra.getBridge();
	system("pause");
	return 0;
}