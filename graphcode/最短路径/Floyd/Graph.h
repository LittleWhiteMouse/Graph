#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF INT_MAX

class Graph {
public:
	int V;
	vector<vector<int>> adj;

	Graph(int v):V(v) {
		for (int i = 0; i < v; i++){
			vector<int> ls(V,INF);
			adj.push_back(ls);
		}
		for (int i = 0; i < v; i++)
		{
			adj[i][i] = 0;
		}
	}
	void addEdge(int a, int b, int weight);
	vector<vector<int>> FloydInside(int k, vector<vector<int>> matrx);
	vector<vector<int>> Floyd();
};
void Graph::addEdge(int a, int b,int weight) {
	adj[a][b] = weight;
}

vector<vector<int>> Graph::Floyd() {
	vector<vector<int>> res=adj;
	for (int i = 0; i < V; i++){
		res =FloydInside(i, res);
	}
	return res;
}
vector<vector<int>> Graph::FloydInside(int k, vector<vector<int>> matrx) {
	vector<vector<int>> newmatra=matrx;
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			if (i == j || i == k || j == k) continue;
			else if (matrx[i][k] != INF && matrx[k][j] != INF && (matrx[i][j] > matrx[i][k] + matrx[k][j]))
					newmatra[i][j] = matrx[i][k] + matrx[k][j];
		}
	}
	return newmatra;
}

