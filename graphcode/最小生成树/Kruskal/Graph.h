#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Edge {
public:
	int weight;
	int src;
	int dst;
	Edge():weight(0),src(0),dst(0) {}
	Edge(int s,int d,int w ):weight(w),src(s),dst(d){}
};

class Graph
{
public:
	int V, E;//边数和顶点数
	std::vector<Edge> edges;

	Graph() :V(0), E(0) {}
	Graph(int v):V(v) {}
	void addEdge(Edge e);
	void KruskalMST();
};

void Graph::addEdge(Edge e) {
	edges.push_back(e);
	E++;
}

class DisjointSet {
public:
	int V;
	int *parent;
	int *rank;

	DisjointSet(int v) :V(v) {
		rank = new int[V];
		parent = new int[V];
		for (int i = 0; i < V; i++)
			parent[i] = i;
	}

	int find(int i);
	void merge(int i, int j);
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
	if (irank==jrank)
	{
		parent[iset] = j;
		rank[jset]++;
	}
	else irank < jrank ? parent[iset] = j : parent[jset] = i;
}

int myCompare(Edge a, Edge b) {
	return a.weight < b.weight;
}

void Graph::KruskalMST() {
	vector<Edge> mstedges; // 存储mst的边
	
	// 1.对所有的边进行排序，从大到小排序
	sort(edges.begin(), edges.end(), myCompare);
	DisjointSet djs(V); // 创建并查集
	
	int i = 0; // 用来控制循环上限为所有边的数量
	int j = 0; // 用来控制循环下线为MST的边数量V-1
	while (j<V-1 && i<E )
	{
		// 2. 不断选择权值最小的边
		Edge edge = edges[i++];
		int x = djs.find(edge.src);
		int y = djs.find(edge.dst);
		if (x != y) {
			mstedges.push_back(edge);
			j++;
			djs.merge(x, y);
		}
		// 若属于同一集合则丢掉这条边
	}
	cout << "MST tree edges :*******************" << endl;
	for (auto it = mstedges.begin();it!=mstedges.end(); it++)
	{
		cout << (*it).src << "---" << (*it).dst << "---" << (*it).weight << endl;
	}
}