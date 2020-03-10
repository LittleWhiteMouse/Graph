#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Edge {
public:
	int src;
	int dst;
	int weight;
	Edge(int s, int d, int w) :src(s), dst(d), weight(w) {}
};

class Graph {
public:
	int V;
	vector<Edge> edgelist;

	Graph(int v):V(v) {}
	void addEdge(int a, int b, int weight);
	vector<int> BellmanFord(int start);
};
void Graph::addEdge(int a, int b,int weight) {
	edgelist.push_back(Edge(a,b,weight));
}

vector<int> Graph::BellmanFord(int start) {
	vector<int> distance(V, INT_MAX);
	distance[start] = 0;
	for (int i = 1; i < V; i++){
		vector<Edge>::iterator eit;
		bool flag = false;
		for (eit=edgelist.begin();eit!=edgelist.end();eit++){
			if (distance[(*eit).src] + (*eit).weight < distance[(*eit).dst]) {
				distance[(*eit).dst] = distance[(*eit).src] + (*eit).weight;
				flag = true; // distance±»¸üÐÂ
			}
		}
		if (!flag) 	break;
	}
	return distance;
}

