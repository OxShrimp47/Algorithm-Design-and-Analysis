/*
Name:Tommy Lee Truong
Last Edit:June 26 2020
Program Name: Insertion Sort
*/
#include <iostream>

using namespace std;

class seq{
	public:
	int val;
	seq *next;
};

void insertBefore(seq** front, int new_val){
		
	seq* new_seq = new seq();
	new_seq->val = new_val;
	new_seq->next = *front;
	*front = new_seq;
	
}
void insertAfter(seq* prev, int new_val){
	
	if(prev == NULL){
		return;
	}
	seq* new_seq = new seq();
	new_seq->val = new_val;
	new_seq->next = prev->next;
	prev->next = new_seq;
}


void print(seq* print){
		while(print != NULL){
			cout<<print->val<<";";
			print=print->next;
		}

		cout<<'\n';
}


int main(int argc, char **argv){
	seq* Sequence = new seq();
	Sequence= NULL;
	int seqSize = 1;
	cin >> seqSize;
	int t =0;
	cin >> t;
	insertBefore(&Sequence,t);
	
	while (seqSize>1){
		cin >> t;
		
		if(t<= Sequence->val){
			insertBefore(&Sequence,t);
		}
		else{
			seq* temp = Sequence;
			while(temp->next!=NULL && t> temp->next->val ){
				temp=temp->next;
			}
			insertAfter(temp, t);
		}
		print(Sequence);
		
	
	
		seqSize--;
	}
return 0;
}
