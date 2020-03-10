#pragma once
class DisjointSet {
public:
	int V;
	int *parent; // parent[i]是i结点的父节点
	int *rank; // rank[i]是树高

    DisjointSet(int v) :V(v) {
		rank = new int[V];
		parent = new int[V];
		for (int i = 0; i < V; i++)
			parent[i] = i;
	}
	int find(int i); // 查找到i的root
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
	if (irank == jrank) {
		parent[iset] = j;
		rank[jset]++;
	}
	else irank < jrank ? parent[iset] = j : parent[jset] = i;
}