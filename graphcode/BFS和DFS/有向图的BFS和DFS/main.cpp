#include "AdjlistGraph.h"
int main(int argc, char ** argv) {
	AdjlistGraph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 4);
	g.BFS();
	cout <<endl << "************" << endl;
	g.DFS();
	cout <<endl<<  "************" << endl;

	system("pause");
	return 0;
}