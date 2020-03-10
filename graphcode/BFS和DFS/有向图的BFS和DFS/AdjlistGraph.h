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
// BFS����
void AdjlistGraph::BFS() {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] != true) { 
			BFS(i, visited); cout << endl;
		}
	}
}
// ��ͼ��һ��������ͨ������б���
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

// DFS����
void AdjlistGraph::DFS() {
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] != true) {
			DFS(i, visited); cout << endl;
		}
	}
}
// ��ͼ��һ��������ͨ������б���
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
			// ȥ�������е�δ���ʽ�㣬�ҵ����˳�
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
