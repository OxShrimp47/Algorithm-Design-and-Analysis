/*
Name:Tommy Lee Truong
Last Edit:Aug 5 2020
Program Name: Huffman Codes
*/
#include <iostream> 
using namespace std; 
#define MAX_TREE_HT 100

struct node{
	int freq;
	char val;
	struct node * left;
	struct node * right;
};

struct heap{
	int size;
	int length;
	struct node ** arr;
};

void swap(struct node ** a, struct node ** b){
	struct node* temp=*a;
	*a=*b;
	*b=temp;
}

void heapify(struct heap* heap, int x){
	int lowest =x;
	int l = 2*x +1;
	int r = 2*x+2;
	if(l < heap->size && heap->arr[l]->freq < heap->arr[lowest]->freq){
		lowest = l;
	}
	if(r < heap->size && heap->arr[r]->freq < heap->arr[lowest]->freq){
		lowest = r;
	}
	if(lowest != x){
		swap(&heap->arr[lowest], &heap->arr[x]);
		heapify(heap,lowest);
	}
}

struct heap* make(node*arr[6] ){
	heap* heap=(struct heap*)malloc(sizeof(struct heap));
	heap->arr=arr;
	heap->size=6;
	heap->length=6;
	int n = heap->size-1;
	for(int i =(n-1)/2;i>=0;--i){
		heapify(heap,i);
	}
	return heap;
}

int one(struct heap* heap){
	return(heap->size==1);
}

struct node* extract(struct heap* heap){
	struct node* temp = heap->arr[0];
	heap->arr[0]=heap->arr[heap->size -1];
	--heap->size;
	heapify(heap,0);
	return temp;
}
	
void insert(struct heap* heap, struct node* node){
	++heap->size;
	int i = heap->size -1;
	while(i && node->freq < heap->arr[(i-1)/2]->freq){
		heap->arr[i] = heap->arr[(i-1)/2];
		i=(i-1)/2;		
	}
	heap->arr[i]=node;
}

struct node* tree(node * arr[6]){
	node* left;
	node* right;
	node* top;
	heap* Heap = make(arr);
	while(!one(Heap)){
		left=extract(Heap);
		right=extract(Heap);
		top=(struct node*)malloc(sizeof(struct node));
		top->freq=left->freq+right->freq;
		top->val='x';
		top->left=left;
		top->right=right;
		insert(Heap,top);
	}
	return extract(Heap);
}

int leaf(struct node* root){
	return !(root->left) && !(root->right);
}

void print(int arr[], int n){
	for(int i=0;i<n;++i){
		cout<<arr[i];
	}
	cout<<endl;
}

void Code(node * root, int arr[], int top, char dest){
	if(root->left){
		arr[top] =0;
		Code(root->left,arr,top+1,dest);
	}
	if(root->right){
		arr[top]=1;
		Code(root->right,arr,top+1,dest);
	}
	if(leaf(root) && root->val==dest){
		cout << root->val <<":";
		print(arr,top);
	}
}

int main(){
	node* arr[6];
	for(int i =0; i < 6; i++){
		arr[i]= (struct node*)malloc(sizeof(struct node));
		cin >> arr[i]->freq;
		arr[i]->val=(char)i+65;
		arr[i]->left=NULL;
		arr[i]->right=NULL;
	}
	node* root =tree(arr);
	int max[MAX_TREE_HT];
	for(int i =0; i < 6; i++){
		Code(root,max,0,(char)i+65);
	}
	return 0;
}
