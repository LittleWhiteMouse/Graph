#pragma once
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Graph {
public:
	int V;
	vector<list<int>> adj;
	Graph(int v) :V(v) {
		for (int i = 0; i < V; i++) {
			list<int> ls;
			adj.push_back(ls);
		}
	}
	void addEdge(int v, int w);

	void getBridge();
	void Bridge(int v, vector<int>& dfn, vector<int>& low, int& time, vector<int>& parent);
};
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::getBridge() {
	vector<int> dfn(V, -1);
	vector<int> low(V, -1);
	vector<int> parent(V, -1);
	int time = 0;
	int i = 0;
	for (int i = 0; i < V; i++)
	{
		if (dfn[i] == -1) {
			Bridge(i, dfn, low, time,parent);
		}
	}
}
void Graph::Bridge(int v, vector<int>& dfn, vector<int>& low, int& time, vector<int>& parent) {
	dfn[v] = time++;
	low[v] = dfn[v];

	for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
		if (dfn[*it] == -1) { //unvisited
			parent[*it] = v;
			Bridge(*it, dfn, low,time,parent);
			low[v] = min(low[v], low[*it]);
		}
		else {
			if(*it!=parent[v])	 low[v] = min(low[v], dfn[*it]);
			//这里注意啊，不能让他回溯到祖先的祖先，这样会跳过割点
			//也不能回溯到父节点，这样还搞啥子哦
		}
	}
	if (parent[v]!=-1 && low[v] > dfn[parent[v]])
		cout << v << "-" << parent[v] << endl;
}