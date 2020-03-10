#include "Graph.h"
int main(int argc, char ** argv) {
	Graph g(9);
	g.addEdge(Edge(0, 1, 4));
	g.addEdge(Edge(0, 7, 8));
	g.addEdge(Edge(1, 2, 8));
	g.addEdge(Edge(2, 8, 2));
	g.addEdge(Edge(1, 7, 11));
	g.addEdge(Edge(7, 8, 7));
	g.addEdge(Edge(7, 6, 1));
	g.addEdge(Edge(6, 8, 6));
	g.addEdge(Edge(6, 5, 2));
	g.addEdge(Edge(2, 5, 4));
	g.addEdge(Edge(2, 3, 7));
	g.addEdge(Edge(3, 5, 14));
	g.addEdge(Edge(3, 4, 9));
	g.addEdge(Edge(4, 5, 10));
	g.KruskalMST();
	system("pause");
}