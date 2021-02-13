/*
Name:Tommy Lee Truong
Last Edit:July 20 2020
Program Name: Hash Table Chaining
*/
#include <iostream>
#include <list>
#include <iterator>
#include<bits/stdc++.h>
using namespace std;

class Hash
{
	int val;
	list<int> *seq;
	public:
		Hash(int h);
		void insert(int x){
			int add = x%val;
			seq[add].push_front(x);
		}
		void search(int x,int h, bool del);
		void print(){
			for (int i=0; i< val;i++){
				cout << i << ":";
				for(auto x : seq[i]){
					cout << x << "->";
				}
			cout << ";"<<endl;
			}
		}
};
Hash::Hash(int v)
{
	this->val = v;
	seq = new list<int>[val];
}

void Hash :: search(int x,int h ,bool del){
	int add = x%h;
	int count=0;
	list <int> :: iterator i;
	for (i= seq[add].begin();i !=seq[add].end();i++){
		if (*i == x){
			break;
		}
		count++;
	}
	if(del==false){
		if (i != seq[add].end()){
			cout <<x<< ":FOUND_AT"<<add<<","<<count<<";"<<endl;
		}
		else{
			cout <<x<< ":NOT_FOUND;"<<endl;
		}
	}
	else{
		if (i != seq[add].end()){
			seq[add].erase(i);
			cout <<x<< ":DELETED;"<<endl;
		}
		else{
			cout <<x<< ":DELETE_FAILED;"<<endl;
		}
	}
}

int main(){
	char c = 'n';
	int x=0;
	int m=0;
	cin >> m;
	Hash map(m);
	while (c != 'e'){
		cin >> c;
		if(c=='i'){
			cin >>x;
			map.insert(x);
		}
		if(c=='d'){
			cin >> x;
			map.search(x,m,true);
		}
		if(c=='s'){
			cin >> x;
			map.search(x,m,false);
		}
		if(c=='o'){
			map.print();
		}
	}
	return 0;
}
