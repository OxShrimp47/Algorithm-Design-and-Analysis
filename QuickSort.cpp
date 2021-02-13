/*
Name:Tommy Lee Truong
Last Edit:July 12 2020
Program Name: Quick Sort
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int* a,int* b){
	int temp = *a;
	*a=*b;
	*b=temp;
	
}
int pivot(int seq[], int lo, int hi){
		int r = lo +rand()%(hi-lo);
		int x=seq[r];
		seq[r]=seq[hi];
		seq[hi]=x;
		int i=lo;
		int j=lo;
		for (i=lo;i<hi;i++){
			if(seq[i]<x){
				
				swap(&seq[j],&seq[i]);
				j++;	
			}
		}
		swap(&seq[j],&seq[hi]);
		return j;
}

void quickSort(int seq[],int lo, int hi){

	if (lo<hi){
		int x = pivot(seq,lo,hi);
		quickSort(seq,lo,x-1);
		quickSort(seq,x+1,hi);
	}
}

int main(){
	int size;
	cin >> size;
	int seq[size];
	for (int i=0; i<size;i++){
		cin >> seq[i];
	}
	quickSort(seq,0,size-1);
		for (int i=0; i<size;i++){
			cout << seq[i] <<";";
		}
}
