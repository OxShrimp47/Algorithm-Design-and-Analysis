/*
Name:Tommy Lee Truong
Last Edit:Aug 14 2020
Program Name: Minimum Spanning Tree
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <pair<int,int> > adj[],int x,int y, int w){
	adj[x].push_back(make_pair(y,w));
	adj[y].push_back(make_pair(x,w));	
	return;
}

int findZ(int min[],bool Q[],int v){
	int m= INT_MAX;
	int index;
	for(int i=0; i<v; i++){
		if(Q[i] == false && min[i] <m){
			m=min[i];
			index=i;
		}
	}
	return index;
}

void prime(vector<pair<int,int>> adj[], int v){
	int parent[v];
	int min[v];
	bool Q[v];
	int graph[v][v];
	for(int i =0; i<v;i++){
		min[i]=INT_MAX;
		Q[i]=false;
		for(int j=0; j<v;j++){
			graph[i][j]=0;
		}
	}
	for(int i=0; i<v;i++){
		for (auto j = adj[i].begin(); j!=adj[i].end(); j++){
			graph[i][j->first]=j->second;
		}
	}
	min[0]=0;
	parent[0]=-1;
	for(int i=0; i <v-1;i++){
		int z=findZ(min,Q,v);
		Q[z]=true;
		for(int j=0; j<v; j++){
			if(graph[z][j] && Q[j]==false && graph[z][j]<min[j]){
				parent[j]=z;
				min[j]=graph[z][j];
			}
		}
	}
	for(int i =1; i <v; i++){
		cout << parent[i]<<endl;
	}
	return;
}

int main(){
	int vertices;
	cin >> vertices;
	int edges;
	cin >> edges;
	vector<pair<int,int>> adj[vertices];
	int temp1;
	int temp2;
	int temp3;
	for(int i =0; i< edges; i++){
		cin >> temp1;
		cin >> temp2;
		cin >> temp3;
		addEdge(adj, temp1, temp2,temp3);
	}
	prime(adj,vertices);
	return 0;
}
