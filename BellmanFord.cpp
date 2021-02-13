/*
Name:Tommy Lee Truong
Last Edit:Aug 16 2020
Program Name: Bellman-Ford Algorithm
*/
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
  
struct Edge { 
    int x;
	int y;
	int w; 
}; 
  
struct Graph { 
    int v, e; 
    struct Edge* edge; 
}; 
  
struct Graph* makeGraph(int v, int e) 
{ 
    struct Graph* g = new Graph; 
    g->v = v; 
    g->e = e; 
    g->edge = new Edge[e]; 
    return g; 
} 
  
void BellmanFord(struct Graph* graph) 
{ 
    int v = graph->v; 
    int e = graph->e; 
    int dist[v]; 
    dist[0] = 0; 
    for (int i = 1; i < v; i++){
        dist[i] = INT_MAX; 
	}
    for (int i = 1; i < v ; i++) { 
        for (int j = 0; j < e; j++) { 
            int x = graph->edge[j].x; 
            int y = graph->edge[j].y; 
            int w = dist[x]+graph->edge[j].w; 
            if (dist[x] != INT_MAX && w < dist[y]){ 
                dist[y] = w; 
        	}
        } 
    } 
    for (int i = 0; i < e; i++) { 
        int x = graph->edge[i].x; 
        int y = graph->edge[i].y; 
        int w = dist[x]+graph->edge[i].w; 
            if (dist[x] != INT_MAX && w < dist[y]){
				cout << "FALSE"<<endl;
				return;
            } 
    } 
    cout << "TRUE"<<endl;
    for(int i=0; i<v;i++){
    	if(dist[i]!=INT_MAX){
    		cout << dist[i]<<endl;
		}
		else{
			cout << "INFINITY"<<endl;
		}
	}
  
    return; 
} 
  
// Driver program to test above functions 
int main(){ 
    int vertices; 
    cin >> vertices;
    int edges; 
    cin >> edges;
    struct Graph* g = makeGraph(vertices, edges);
    for(int i=0; i<edges; i++){
    	cin >> g->edge[i].x;
    	cin >> g->edge[i].y;
    	cin >> g->edge[i].w;
	}
    BellmanFord(g); 
    return 0; 
} 

