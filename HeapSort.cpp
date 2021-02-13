/*
Name:Tommy Lee Truong
Last Edit:July 12 2020
Program Name: Heap Sort
*/
#include <iostream>
using namespace std;

void heapify(int seq[], int size, int i){
	int large= i;
	int left = 2*i +1;
	int right = 2*i +2;
	if(left < size && seq[left]>seq[large]){
		large=left;
	}
		if(right < size && seq[right]>seq[large]){
		large=right;
	}
	if(large !=i){
		int temp= seq[i];
		seq[i]=seq[large];
		seq[large]=temp;
		heapify(seq,size,large);
	}
}

void sort(int seq[], int size){
	for (int i=size/2-1;i>=0;i--){
		heapify(seq,size,i);
	}
		for (int i=size-1;i>0;i--){
			int temp= seq[0];
			seq[0]=seq[i];
			seq[i]=temp;
			heapify(seq,i,0);
	}
}

int main(){
	int size;
	cin >> size;
	int seq[size];
	for (int i=0; i<size;i++){
		cin >> seq[i];
	}
	sort(seq,size);
		for (int i=0; i<size;i++){
		cout << seq[i] <<";";
	}
	
}
