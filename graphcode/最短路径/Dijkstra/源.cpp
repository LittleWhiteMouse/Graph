#include<iostream>
#include "Graph.h"
using namespace std;
int main(int argc, char** argv) {
	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(1, 2, 8);
	g.addEdge(2, 8, 2);
	g.addEdge(7, 8, 7);
	g.addEdge(8, 6, 6);
	g.addEdge(7, 6, 1);
	g.addEdge(6, 5, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);
	g.addEdge(4, 5, 10);
	vector<int> a = g.Dijkstra(0);
	for (int k=0;k<9;k++)
	{
		cout << k << " distance:" << a[k]<<endl;
	}


	system("pause");
	return 0;
}

