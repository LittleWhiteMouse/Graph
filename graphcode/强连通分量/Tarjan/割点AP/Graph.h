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

	void getAP();
	void AP(int v, vector<int>& dfn, vector<int>& low, int& time, vector<int>& parent);
};
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::getAP() {
	vector<int> dfn(V, -1);
	vector<int> low(V, -1);
	vector<int> parent(V, -1);
	int time = 0;
	int i = 0;
	for (int i = 0; i < V; i++)
	{
		if (dfn[i] == -1) {
			AP(i, dfn, low, time,parent);//root��parent��Ϊ-1
		}
	}
}
void Graph::AP(int v, vector<int>& dfn, vector<int>& low, int& time, vector<int>& parent) {
	dfn[v] = time++;
	low[v] = dfn[v];

	int child = 0;//��¼��ǰ�ڵ��DFS������

	for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
		if (dfn[*it] == -1) { //unvisited
			parent[*it] = v;
			child++;
			AP(*it, dfn, low,time,parent);
			low[v] = min(low[v], low[*it]);
		}
		else {
			if(*it!=parent[v])	 low[v] = min(low[v], dfn[*it]);
			//����ע�Ⱑ�������������ݵ����ȵ����ȣ��������������
			//Ҳ���ܻ��ݵ����ڵ㣬��������ɶ��Ŷ
		}
	}
	if (parent[v] == -1) { // v��root�����
		if (child > 1) cout << v << " ";
	}else if (parent[parent[v]] != -1 && low[v] >= dfn[parent[v]]) {
		// parent[v]��root�ڵ��Ǹ������
		cout << parent[v] << " ";
	}
}