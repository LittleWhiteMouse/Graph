#include<iostream>
#include "Graph.h"

using namespace std;
int main(int argc, char** argv) {
	Graph g(4);
	g.addEdge(0, 1, 3);	g.addEdge(0, 3, 7); g.addEdge(1, 0, 8);
	g.addEdge(1, 2, 2);	g.addEdge(2, 0, 5);	g.addEdge(2, 3, 1);
	g.addEdge(3, 0, 2);
	vector<vector<int>> a = g.Floyd();
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}