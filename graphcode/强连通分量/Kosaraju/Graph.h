#pragma once
#include<list>
#include<stack>
#include <vector>
#include<iostream>
using namespace std;
class Graph {
	int V;
	vector<list<int>> adj;
public:
	Graph(int _v) :V(_v) {
		for (int i = 0; i < _v; i++)
		{
			list<int> ls;
			adj.push_back(ls);
		}
	}
	void addEdge(int a, int b);
	void DFS(int start, vector<bool>& visited);
	void DFS(int start, vector<bool>& visited, stack<int> &order);
	Graph getTranspose();
	void getSCC();
};

void Graph::addEdge(int a, int b) {
	adj[a].push_back(b);
}
// ���ڵڶ���DFS���SCC
void Graph::DFS(int start, vector<bool>& visited) {
	stack<int> s;
	s.push(start);
	std::cout << start << " ";
	visited[start] = true;

	while (!s.empty())
	{
		int v = s.top();
		auto i = adj[v].begin();
		bool flag = false;
		for (; i != adj[v].end(); i++)
		{
			if (!visited[(*i)]) {
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			s.push(*i);
			std::cout << *i << " ";
			visited[(*i)] = true;
		}
		else {
			s.pop();
		}
	}
}
// ���ڵ�һ��DFS��¼�ڵ��˳�˳��
void Graph::DFS(int start, vector<bool>& visited,stack<int> &order) {
	stack<int> s;
	s.push(start);
	visited[start] = true;

	while (!s.empty()){
		int v = s.top();
		list<int>::iterator i = adj[v].begin();
		bool flag = false;
		for (; i != this->adj[v].end(); i++)
		{
			if (!visited[*i]) {
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			s.push(*i);
			visited[*i] = true;
		}
		else {
			order.push(s.top());
			s.pop();
		} 
	}
}

Graph Graph::getTranspose() {
	Graph g(V);
	for (int i = 0; i < V; i++){
		list<int>::iterator it = this->adj[i].begin();
		for (; it!=adj[i].end(); it++){
			g.adj[*it].push_back(i);
		}
	}
	return g;
}

void Graph::getSCC() {
	// ��һ��DFS
	vector<bool> visited(V, false);
	stack<int> firstorder; // �����˳�DFS��ʱ��洢�ڵ㡣
	for (int i = 0; i < V; i++){
		if (visited[i] != true){
			DFS(i, visited, firstorder);
		}
	}
	// �ڶ���DFS
	Graph g = this->getTranspose();
	vector<bool> visitedtwice(V, false);
	while (!firstorder.empty()){
		int val = firstorder.top();
		if (visitedtwice[val]==false)
		{
			g.DFS(val, visitedtwice);
			cout << endl;
		}
		firstorder.pop();
	}
}