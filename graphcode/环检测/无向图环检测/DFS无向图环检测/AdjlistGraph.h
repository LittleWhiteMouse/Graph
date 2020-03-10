#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;
class AdjlistGraph
{
	int V;
	vector<list<int>> adj;
public:
	AdjlistGraph(int _V) :V(_V) {
		for (int i = 0; i < _V; i++)
		{
			list<int> ls;
			ls.push_back(i);
			adj.push_back(ls);
		}
	}
	void addEdge(int a, int b);
	
	bool iscyclicDSF();
	bool iscyclicDSF(int start,vector<bool> &visited);
};

void AdjlistGraph::addEdge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}


// DFS检查无向图一个极大连通区域的环，有环返回真
bool AdjlistGraph::iscyclicDSF() {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] != true) {
			if (iscyclicDSF(i, visited)) return true;
		}
	}
	return false;
}

// 对无向图的一个极大连通区域进行遍历
bool AdjlistGraph::iscyclicDSF(int start,vector<bool> &visited) {
	vector<int> s; // 因为需要遍历栈中的元素，所以用vector来代替栈的使用
	vector<int> parent(V,-1);// 令头结点的父元素等于-1
	s.push_back(start);
	visited[start] = true;
	while (!s.empty()) // 此处也被修改
	{
		int v = s.back();
		bool flag = false;
		for (auto i = ++adj[v].begin(); i != adj[v].end(); i++)
		{	// 加个for循环来遍历邻接节点，看是否已被遍历且非当前节点的父节点
			if (visited[(*i)] && parent[v]!=(*i) && parent[(*i)]!=v) {
				cout << (*i) << endl;
				return true;
			}
		}
		auto i = ++adj[v].begin();
		for (; i != adj[v].end(); i++){ 
			if (!visited[(*i)]) { 
				flag = true;
				break;
			}
		}
		if (flag == true){
			s.push_back(*i);
			visited[(*i)] = true;
			parent[(*i)] = v;
		}else s.pop_back();
	}
	return false;
}
