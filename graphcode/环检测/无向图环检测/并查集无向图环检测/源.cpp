#include<iostream>
#include "DisjointSet.h"
using namespace std;
#include<iostream>
#include"DisjointSet.h"
using namespace std;

int main(int argc,char ** argv) {
	Graph g(4);
	Edge e(0, 1, 1),f(0, 2, 1),c(1, 3, 1), h(2, 3, 1);
	g.addEdge(e);
	g.addEdge(f);
	g.addEdge(c);
	g.addEdge(h);
	
	if (g.isCylic()) cout << "true" << endl;
	else cout << "false" << endl;
	system("pause");
	return 0;
}