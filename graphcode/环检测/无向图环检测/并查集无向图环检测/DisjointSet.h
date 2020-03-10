#pragma once
#include<vector>
class DisjointSet {
public:
	int V;
	int *parent; // parent[i]是i结点的父节点
	int *rank;   // rank[i]是树高

    DisjointSet(int v) :V(v) {
		rank = new int[V];
		parent = new int[V];
		for (int i = 0; i < V; i++)
			parent[i] = i;
	}
	int find(int i);          // 查找到i的root
	void merge(int i, int j); // 合并俩集合
};

int DisjointSet::find(int i) {
	if (parent[i] == i) return i;
	else {
		parent[i] = find(parent[i]);
		return parent[i];
	}
}

void DisjointSet::merge(int i, int j) {
	int iset = find(i);
	int jset = find(j);
	if (iset == jset) return;

	int irank = rank[iset];
	int jrank = rank[jset];
	if (irank == jrank) {
		parent[iset] = j;
		rank[jset]++;
	}
	else irank < jrank ? parent[iset] = j : parent[jset] = i;
}

class Edge {
public:
	int src;
	int dst;
	int weight;
	Edge():src(0),dst(0),weight(0) {}
	Edge(int s,int d,int w):src(s),dst(d),weight(w) {}
};

class Graph {
public:
	int V, E;//顶点和边数
	std::vector<Edge> edges;
	Graph(int v):V(v) {}
	Graph():V(0) {}
	void addEdge(Edge e);
	bool isCylic();
};
void Graph::addEdge(Edge e) {
	edges.push_back(e);
	E++;
}

bool Graph::isCylic(){
	DisjointSet subset(V);
	for (int i = 0; i < E; i++)
	{
		int x = subset.find(edges[i].src);
		int y = subset.find(edges[i].dst);
		if (x == y) return true;
		else
		{
			subset.merge(x, y);
		}
	}
	return false;
}