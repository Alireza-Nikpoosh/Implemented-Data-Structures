#include<iostream>
using namespace std;
void print(int A[],int n){
		for(int i = 0 ; i<n ; i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
};
int left(int index){return 2*index+1;}
int right(int index){return 2*index+2;}
int parent(int index){if (index%2==1) return index/2; else return index/2 -1;}
void swap(int A[],int i , int j){
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}
void max_heapify(int A[],int n,int i){ //i has violated the heap property
	int larger;
	if(A[left(i)]>A[i] && left(i)<n){
		larger=left(i);
	}
	else
		larger=i;
	if(A[right(i)]>A[larger] && right(i)<n){
		larger=right(i);
	}
	if(larger != i ){
		swap(A,i,larger);
		max_heapify(A,n,larger);
	}
}
void Build_Max_Heap(int A[],int n){
	for(int i = n/2 ; i>=0 ; i--){
		max_heapify(A,n,i);
	}	
}	

void Heap_Sort(int A[],int n){
	Build_Max_Heap(A,n);
	print(A,n);
	for(int i = n-1 ; i>=1 ; i--){
		swap(A,i,0);
		print(A,n);
		max_heapify(A,i,0);
		print(A,n);
	}
}

int main(){
	int n;
	cout<<"enter size: ";
	cin>>n;
	int A[n];
	for(int i = 0 ; i< n ; i++){
		cin>>A[i];
	}
	Heap_Sort(A,n);
	print(A,n);
}