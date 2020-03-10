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

	bool  res  = g.iscyclicDSF();
	if (res) {
		cout <<  "there is a cycle in the graph" << endl;
	}
	else {
		cout << "there is no cycle in the graph" << endl;
	}
	

	system("pause");
	return 0;
}