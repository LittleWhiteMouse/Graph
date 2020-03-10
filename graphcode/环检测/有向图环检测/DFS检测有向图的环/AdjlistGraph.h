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
}


// DFS检查有向图一个极大连通区域的环，有环返回真
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

// 对有向图的一个极大连通区域进行遍历
bool AdjlistGraph::iscyclicDSF(int start,vector<bool> &visited) {
	vector<int> s; // 因为需要遍历栈中的元素，所以用vector来代替栈的使用
	s.push_back(start);
	visited[start] = true;
	while (!s.empty())
	{
		int v = s.back();
		bool flag = false;
		for (auto i = ++adj[v].begin(); i != adj[v].end(); i++)
		{	// 判断其邻接点是否在栈中，是则有环,返回退出
			// 其实邻接表是顺序访问的，这个循环可以和下面的循环放在一起，
			//  但是为了思路好看，就提出来了
			if (std::find(s.begin(), s.end(), *i) != s.end()) {
				cout << (*i) << endl;
				return true;
			}
		}
		auto i = ++adj[v].begin();
		for (; i != adj[v].end(); i++){ 
			if (!visited[(*i)]) { // 去找链表中的未访问结点，有就压入栈中
				flag = true;
				break;
			}
		}
		if (flag == true){
			s.push_back(*i);
			visited[(*i)] = true;
		}
		else s.pop_back();
	}
	return false;
}
