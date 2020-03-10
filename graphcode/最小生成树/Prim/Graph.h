#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Graph {
public:
	int V, E;
	vector<vector<int>> adj;
	Graph(int v):V(v) {
		for (int i = 0; i < v; i++)
		{
			vector<int> temp;
			for (int j = 0; j < v; j++)
			{
				temp.push_back(INT16_MAX);
			}
			adj.push_back(temp);
		}
	}
	void addEdge(int src, int dst, int weight);
	void PrimMST();
	vector<int> findmin(vector<bool> selected);
	void printMST(vector<int> mst, vector<int> weight);

};


void Graph::addEdge(int src, int dst, int weight) {
	adj[src][dst] = weight;
	adj[dst][src] = weight;
	E++;
}

void Graph::PrimMST() {
	vector<bool> selected(V,false);
	selected[0] = true;
	int i = 1; // 用于记录被选中的个数
	int key = 0; // 用于记录最新被选中的节点id
	vector<int> mst(V, -1);   // 存放父节点
	vector<int> weight(V, 0); // 存放MST权重
	while (i < V) {
		vector<int> a = findmin(selected);
		//a[0]:parent,a[1]:minid,a[2]:minvalue
		selected[a[1]] = true;
		mst[a[1]] = a[0];
		weight[a[1]] = a[2];
		key = a[1];
		i++;
	}
	printMST(mst, weight);
}
vector<int> Graph::findmin(vector<bool> selected) {
	int min = INT16_MAX;
	int min_id;
	int parent;
	for (int j = 0; j < V; j++){
		if (selected[j])
		{
			for (int i = 0; i < V; i++) {
				if (selected[i] == false && adj[j][i] < min) {
					min = adj[j][i];
					min_id = i;
					parent = j;
				}
			}
		}
	}
	vector<int> a{ parent,min_id,min };
	return a;
}


void Graph::printMST(vector<int> mst,vector<int> weight) {
	for (int i = 0; i < V; i++){
		cout << "weight:"<< weight[i]<<"  node:"<<i<<"---"<< mst[i] << endl;
	}
}