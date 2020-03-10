#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <stack>
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
	void BFS();
	void DFS();
	void BFS(int start, vector<bool> &visited);
	void DFS(int start,vector<bool> &visited);
};

void AdjlistGraph::addEdge(int a, int b) {
	adj[a].push_back(b);
}
// BFS遍历
void AdjlistGraph::BFS() {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] != true) { 
			BFS(i, visited); cout << endl;
		}
	}
}
// 对图的一个极大连通区域进行遍历
void AdjlistGraph::BFS(int start, vector<bool> &visited) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		cout << k << " ";
		for (auto i = adj[k].begin(); i!=adj[k].end(); i++){
			if (!visited[(*i)]) {
				q.push(*i);
				visited[(*i)] = true;
			}
		}
	}
}

// DFS遍历
void AdjlistGraph::DFS() {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] != true) {
			DFS(i, visited); cout << endl;
		}
	}
}
// 对图的一个极大连通区域进行遍历
void AdjlistGraph::DFS(int start,vector<bool> &visited) {
	stack<int> s;
	s.push(start);
	cout << start << " ";
	visited[start] = true;
	while (!s.empty())
	{
		int v = s.top();
		auto i = adj[v].begin();
		bool flag = false;
		for (; i != adj[v].end(); i++){ 
			// 去找链表中的未访问结点，找到就退出
			if (!visited[(*i)])
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			s.push(*i);
			cout << (*i) << " ";
			visited[(*i)] = true;
		}
		else s.pop();
	}
}
