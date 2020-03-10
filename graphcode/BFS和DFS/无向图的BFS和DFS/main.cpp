#include "AdjlistGraph.h"
int main(int argc, char ** argv) {
	AdjlistGraph g(9);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(2, 5);
	g.addEdge(1, 5);
	g.addEdge(1, 6);
	g.addEdge(4, 6);
	g.addEdge(2, 4);
	g.addEdge(7, 8);
	g.BFS();
	cout <<endl << "************" << endl;
	g.DFS();
	cout <<endl<<  "************" << endl;

	system("pause");
	return 0;
}