/*
Name:Tommy Lee Truong
Last Edit:July 15 2020
Program Name: Radix Sort
*/
# include <iostream>
using namespace std;


void setEqual(int a[][10], int  b[][10], int x,int m){
	for(int k =0; k <10; k++){
		a[x][k]=b[m][k];
	}

}
void countSort(int arr[][10], int n, int j){
	int zero=0;
	int one=0;
	int two=0;
	int three=0;
	int t0[n][10];
	int t1[n][10];
	int t2[n][10];
	int t3[n][10];
	for(int m=0; m<n; m++){
		if (arr[m][j]==0){
			setEqual(t0,arr,zero,m);
			zero++;
		}
		else if (arr[m][j]==1){
			setEqual(t1,arr,one,m);
			one++;
		}
		else if (arr[m][j]==2){
			setEqual(t2,arr,two,m);
			two++;
		}
		else if (arr[m][j]==3){
			setEqual(t3,arr,three,m);
			three++;
		}	
	}

	if(zero > 1){
		countSort(t0,zero,j+1);
	}
	if(one > 1){
		countSort(t1,one,j+1);
	}
	if(two > 1){
		countSort(t2,two,j+1);
	}
	if(three > 1){
		countSort(t3,three,j+1);
	}

	int x=0;
	for(int m=0; m<zero; m++){

		setEqual(arr,t0,x,m);

		x++;
	}
	for(int m=0; m<one; m++){

		setEqual(arr,t1,x,m);

		x++;
	}
	for(int m=0; m<two; m++){

		setEqual(arr,t2,x,m);

		x++;
	}
	for(int m=0; m<three; m++){

		setEqual(arr,t3,x,m);

		x++;
	}

}
void radixSort(int matrix[][10],int n){
int j=0;
		int m=0;
		while(m<n){
			if (matrix[m][j] > matrix[m+1][j]){
				m++;
			}
			else{
				countSort(matrix,n,j);
				m=n;
			}
		}
}

int main(){
	int n;
	int temp;
	cin >> n;
	int matrix[n][10];
	for(int i=0; i<n; i++){
		for(int j=0; j<10; j++){
			cin >> temp;
			if(temp>=0&&temp<4){
				matrix[i][j]=temp;
			}
			else{
				j--;
			}
			
		}
	}
	radixSort(matrix,n);
	for(int i=0; i<n; i++){
		for(int j=0; j<10; j++){
			cout << matrix[i][j]<<";";
		}
		cout << endl;
	}
}

