/*
Name:Tommy Lee Truong
Last Edit:July 7 2020
Program Name: Divide and Conquer
*/
#include<iostream>
#include <tuple>
using namespace std;
struct save{
	int low;
	int high;
	int sum;
};
auto FMC(int seq[],int low,int mid,int high)->save*{
	struct save* temp = new save;
	int Lsum = INT8_MIN;
	int sum = 0;
	for (int i= mid; i>=low; i--){
		sum = sum+seq[i];
		if(sum>Lsum){
			Lsum=sum;
			temp->low=i;
			//cout <<temp->low<<","<<Lsum<<'\n';
		}
	}
	int Rsum = INT8_MIN;
	sum = 0;
	for (int i= mid+1; i<high; i++){
		sum = sum+seq[i];
		if(sum>Rsum){
			Rsum=sum;
			temp->high=i;
			//cout <<temp->high<<","<<Rsum<<'\n';
		}
	}
	//cout <<temp->low<<","<<Lsum<<'\n';
	//cout <<temp->high<<","<<Rsum<<'\n';
	temp->sum=Lsum+Rsum;
					//cout <<temp->sum<<'\n';
	return temp;
}
auto FMS(int seq[], int low, int high)->save*{
	struct save* left = new save;

	struct save* right = new save;

	struct save* cross = new save;

	if(high==low){
		left->low=low;
		left->high=high;
		left->sum=seq[low];
					//	cout <<temp->sum<<'\n';
		return left;
	}
	else{
		int mid = (low+high)/2;
		auto left=FMS(seq,low,mid);
		auto right =FMS(seq,mid+1,high);
		auto cross=FMC(seq,low,mid,high);
		if(cross->sum >=right->sum && cross->sum>=left->sum){
		
				//cout <<cross->sum<<'\n';
			return cross;
		}
		else if(right->sum >=cross->sum && right->sum>=left->sum){
		
							//cout <<right->sum<<'\n';
			return right;
		}
					return left;//cout <<left->sum<<'\n';
	}

}
int main(){
	int size;
	cin>>size;
	int A[size];
	for(int i=0; i<size;i++){
		cin>>A[i];
	}
	auto final =FMS(A,0,size-1);
	cout <<final->sum;
	return 0;

}
