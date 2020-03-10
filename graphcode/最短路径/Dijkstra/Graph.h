#pragma once
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#define INF INT_MAX

class Node {
public:
	int dst;
	int weight;
	Node(int d, int w):dst(d),weight(w) {}
};

class Graph {
public:
	int V;
	vector<list<Node>> adj;
	Graph(int v) :V(v) {
		for (int i = 0; i < v; i++)
		{
			list<Node> ls;
			adj.push_back(ls);
		}
	}
	void addEdge(int a, int b,int weight);
	vector<int> Dijkstra(int start);
};

void Graph::addEdge(int a, int b,int weight) {
	adj[a].push_back(Node(b, weight));
	adj[b].push_back(Node(a, weight));
}

vector<int> Graph::Dijkstra(int start) {
	set<int> A;
	vector<int> distance(V, INF);
	distance[start] = 0;
	while (A.size()<V)
	{
		//int minu = findmin(vector<int> distance);
		int minu;
		int minval = INF;
		for (int i = 0; i < V;i++) {
			if (A.find(i)==A.end() && distance[i] <= minval) {
				minu = i;
				minval = distance[i];
			}
		}

		A.insert(minu);

		//updatedistance(int minvertex);
		list<Node>::iterator it = adj[minu].begin();
		for (; it != adj[minu].end(); it++) {
			distance[(*it).dst] = min(distance[minu] + (*it).weight, distance[(*it).dst]);
		}
	}
	return distance;
}