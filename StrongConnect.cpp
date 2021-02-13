/*
Name:Tommy Lee Truong
Last Edit:Aug 7 2020
Program Name: Strongly Connected Components
*/
#include<iostream>
#include<list>
#include<stack>

using namespace std;

class graph{
	int vertices;
	list<int> *adjacent;
	void read(int v, bool visit[], stack<int> &Stack);
	void DFS(int v, bool visit[], int low[], int *l);

	
	public:
		graph(int vertices);
		void addE(int v, int w);
		void lowestSCC();
		graph transpose();
};

graph:: graph(int vertices){
	this->vertices = vertices;
	adjacent = new list<int>[vertices];
}

void graph::DFS(int v, bool visit[], int low[], int *l){
	visit[v] = true;
			list<int>::iterator i;
	if(v<*l){
		*l=v;
	}

	for(i=adjacent[v].begin();i != adjacent[v].end(); ++i){
		
		if(!visit[*i]){

			DFS(*i, visit, low,l);
			
		}
		
	}
	low[v]=*l;
	return;
}
graph graph::transpose(){
	graph g(vertices);
	for(int v=0; v < vertices; v++){
		list<int>::iterator i;
		for(i=adjacent[v].begin();i != adjacent[v].end(); ++i){
			g.adjacent[*i].push_back(v);
		}
	}
	return g;
}

void graph::addE(int v, int w){
	adjacent[v].push_back(w);
	return;
} 

void graph::read(int v, bool visit[], stack<int> &Stack){
	visit[v]=true;
	list<int>::iterator i;
	for(i =adjacent[v].begin(); i != adjacent[v].end(); ++i){
		if(!visit[*i]){
			read(*i,visit,Stack);
		}
	}
	Stack.push(v);
	return;
}

void graph::lowestSCC(){
	stack<int> Stack;
	bool *visit = new bool[vertices];
	int *low =new int[vertices];
	for(int i=0; i < vertices; i++){
		visit[i] = false;
	}
	for(int i=0; i< vertices;i++){
		if(visit[i]==false){
			read(i, visit, Stack);
		}
	}
	graph g = transpose();
	for(int i=0;i<vertices;i++){
		visit[i]=false;
	}
	while(Stack.empty() ==false){
		int v =Stack.top();
		Stack.pop();
		if(visit[v]==false){
			int *l;
			*l=v;
			g.DFS(v,visit,low,l);
		}
	}
	for(int i=0; i<vertices;i++){
		cout << low[i]<<endl;
	}
	return;
}

int main(){
	int vertices;
	cin >> vertices;
	graph g(vertices);
	int edges;
	cin >> edges;
	for(int i=0; i <edges; i++){
		int temp1;
		int temp2;
		cin >> temp1;
		cin >> temp2;
		g.addE(temp1,temp2);
	}
	g.lowestSCC();
	return 0; 
}
