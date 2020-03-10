#include<iostream>
#include "Graph.h"

using namespace std;
int main(int argc, char** argv) {
	Graph g(7);
	g.addEdge(0, 1, 6);
	g.addEdge(0, 2, 5);
	g.addEdge(0, 3, 5);
	g.addEdge(2, 1, -2);
	g.addEdge(3, 2, -2);
	g.addEdge(1, 4, -1);
	g.addEdge(2, 4, 1);
	g.addEdge(4, 6, 3);
	g.addEdge(3, 5, -1);
	g.addEdge(5, 6, 3);
	vector<int> distance = g.BellmanFord(0);
	for (auto i = distance.begin(); i < distance.end(); i++){
		cout << *i << " ";
	}
	system("pause");
	return 0;
}