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


// DFS�������ͼһ��������ͨ����Ļ����л�������
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

// ������ͼ��һ��������ͨ������б���
bool AdjlistGraph::iscyclicDSF(int start,vector<bool> &visited) {
	vector<int> s; // ��Ϊ��Ҫ����ջ�е�Ԫ�أ�������vector������ջ��ʹ��
	vector<int> parent(V,-1);// ��ͷ���ĸ�Ԫ�ص���-1
	s.push_back(start);
	visited[start] = true;
	while (!s.empty()) // �˴�Ҳ���޸�
	{
		int v = s.back();
		bool flag = false;
		for (auto i = ++adj[v].begin(); i != adj[v].end(); i++)
		{	// �Ӹ�forѭ���������ڽӽڵ㣬���Ƿ��ѱ������ҷǵ�ǰ�ڵ�ĸ��ڵ�
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
