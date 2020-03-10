#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Node {
public:
	int dst;
	int weight;
	Node(int d, int w):dst(d), weight(w) {}
};

class Graph {
public:
	int V;
	vector<list<Node>> adj;

	Graph(int v):V(v) {
		for (int i = 0; i < v; i++){
			list<Node> ls;
			adj.push_back(ls);
		}
	}
	void addEdge(int a, int b, int weight);
	vector<int> SPFA(int start);
};
void Graph::addEdge(int a, int b,int weight) {
	adj[a].push_back(Node(b,weight));
}

vector<int> Graph::SPFA(int start) {
	vector<int> distance(V, INT_MAX);
	queue<int> que;
	distance[start] = 0;
	que.push(start);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto eit=adj[u].begin();eit!=adj[u].end();eit++){
			if (distance[u] + (*eit).weight < distance[(*eit).dst]) {
				distance[(*eit).dst] = distance[u] + (*eit).weight;
				que.push((*eit).dst);
			}
		}
	}
	return distance;
}

