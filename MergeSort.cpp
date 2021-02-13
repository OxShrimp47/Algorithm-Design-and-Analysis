/*
Name:Tommy Lee Truong
Last Edit:July 3 2020
Program Name: Merge Sort
*/
#include <iostream>

using namespace std;

void merge(int arr[], int L, int C, int R){
	int Lsize=C-L+1;
	int Rsize=R-C;
	int Left[Lsize];
	int Right[Rsize];

	for(int i=0; i<Lsize; i++){
		Left[i]=arr[i+L];		
	}
	for(int i=0; i< Rsize; i++){
		Right[i]=arr[i+C+1];
	}
	
	int i=0;
	int j=0;
	int k=L;
	while(i<Lsize&&j<Rsize){
		if(Left[i] <= Right[j]){
			arr[k]=Left[i];
			i++;
			
		}
		else{
			arr[k]=Right[j];
			j++;
			
		}
		k++;
	}
	while(i < Lsize){
			arr[k]=Left[i];
			i++;
			k++;
	}
	while(j < Rsize){
			arr[k]=Right[j];
			j++;
			k++;
	}
}
void split(int arr[], int L, int R){
	if(L<R){
		int C =L +( R-L)/2;
		split(arr,L,C);
		split(arr, C+1, R);
		merge(arr, L, C, R);
	}
}
int main(int argc, char **argv){
	
	int seqSize = 1;
	cin>> seqSize;
	int seq[seqSize];
	for(int i =0; i<seqSize; i++){
		cin >> seq[i];
	}
	split(seq,0,seqSize-1);
	for(int i =0; i<seqSize; i++){
		cout << seq[i]<< ";";
	}
	return 0;
}
