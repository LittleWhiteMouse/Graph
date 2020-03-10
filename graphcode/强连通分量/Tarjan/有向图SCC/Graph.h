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
		for (int i = 0; i < V; i++){
			list<int> ls;
			adj.push_back(ls);
		}
	}
	void addEdge(int v, int w);

	void getSCC();
	void SCC(int start, vector<int>& dfn, vector<int>& low, vector<int>& s, int& time);
};
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}
void Graph::getSCC() {
	vector<int> dfn(V, -1);
	vector<int> low(V, -1);
	vector<int> s;
	int time = 0;
	int i = 0;
	for (int i = 0; i < V; i++)
	{
		if(dfn[i] == -1) {
			SCC(i, dfn, low, s, time);
		}
	}
}
void Graph::SCC(int start, vector<int>& dfn, vector<int>& low, vector<int>& s, int& time){
	dfn[start] = time++;
	low[start] = dfn[start];
	s.push_back(start);
	
 	for (auto it = adj[start].begin(); it != adj[start].end(); it++){
		if (dfn[*it] == -1) { //unvisited
			SCC(*it, dfn, low, s, time);
			low[start] = min(low[start], low[*it]);
		}
		else{
			auto sit = find(s.begin(), s.end(), *it);
			if (sit != s.end()) // ÔªËØvisited²¢ÇÒin stack
			{
				low[start] = min(low[start], low[*it]);
			}
		}
	}
	if (dfn[start] == low[start]){
		while (!s.empty()&&(low[s.back()] == low[start])) {
			cout << s.back() << " ";
			s.pop_back();
		}
		cout << endl;
	}
}