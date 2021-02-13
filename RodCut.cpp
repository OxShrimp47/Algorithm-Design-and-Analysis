/*
Name:Tommy Lee Truong
Last Edit:July 24 2020
Program Name: Rod Cutting
*/
#include<iostream>
#include<list>
using namespace std;

struct rod{
	int cost;
	std::list<int> piece;
};

rod cut(int price[],int size){
	rod max;
	max.cost=price[size-1];
	max.piece.push_front(size);
	for(int i =0; i<size; i++ ){
		rod tempt;
		tempt=cut(price,size-i-1);
		if(max.cost<price[i]+tempt.cost){
			max.cost=tempt.cost+price[i];
			max.piece.clear();
			max.piece.push_front(i+1);
			while(tempt.piece.size()>0){
				max.piece.push_front(tempt.piece.front());
				tempt.piece.pop_front();
			}
		}
	}
	return max;
}

int main(){
	int size;
	cin >> size;
	int price[size];
	for (int i =0; i <size; i++){
		cin >> price[i];
	}
	rod final;
	final = cut(price,size);
	cout << final.cost <<endl;
	while(final.piece.size()>0){
		cout << final.piece.back() << " ";
		final.piece.pop_back();
	}
	cout << -1 << endl;
}
