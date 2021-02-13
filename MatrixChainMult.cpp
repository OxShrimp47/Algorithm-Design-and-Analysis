/*
Name:Tommy Lee Truong
Last Edit:July 31 2020
Program Name: Matrix Chain Multiplication
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(int *beak, int *cnt,int i, int j, int MatNum){
	if (i!=j){
		cout << "(";
		print(beak, cnt,i, *((beak +i*MatNum)+j),MatNum);
		print(beak, cnt, *((beak +i*MatNum)+j)+1,j,MatNum);
		cout << ")";
	}
	else{
		cout << "A" << *cnt;
		*cnt=*cnt+1;
		return;
	}
}

void MatrixChain(int arr[], int MatNum){
	int matrix[MatNum][MatNum];
	int beak[MatNum][MatNum];
	for(int i=0; i <MatNum; i++){
		matrix[i][i]=0;
	}
	for(int h=2; h<MatNum; h++){
		for(int i=1; i<MatNum-h+1;i++){
			int j= i +h-1;
			matrix[i][j] = INT_MAX;
			for(int k=i; k<=j-1; k++){
				int cost =matrix[i][k] +matrix[k+1][j]+arr[i-1]*arr[k]*arr[j];
				if(cost<matrix[i][j]){
					matrix[i][j]=cost;
					beak[i][j]=k;
				}
			}
		}
	}
	int* cnt;
	*cnt=0;
	cout<<matrix[1][MatNum-1] <<endl;
	print((int *)beak,cnt,1,MatNum-1,MatNum);
}

int main(){
	int MatNum=0;
	cin >> MatNum;
	MatNum++;
	int arr[MatNum];
	for (int i =0; i<MatNum; i++){
		cin >> arr[i];
	}
	MatrixChain(arr,MatNum);
	cout << endl;
	return 0;
}
