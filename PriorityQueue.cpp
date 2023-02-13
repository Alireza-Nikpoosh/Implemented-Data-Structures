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
void min_heapify(int A[],int n,int i){ //i has violated the heap property
	int smallest;
	if(A[left(i)]<A[i] && left(i)<n){
		smallest=left(i);
	}
	else
		smallest=i;
	if(A[right(i)]<A[smallest] && right(i)<n){
		smallest=right(i);
	}
	if(smallest != i ){
		swap(A,i,smallest);
		min_heapify(A,n,smallest);
	}
}

void Heap_extract_min(int A[],int& n){
	int min=A[0];
	A[0]=A[n-1];
	n=n-1;
	cout<<n<<endl;
	print(A,n);
	min_heapify(A,n,0);
	cout<<"popped:"<<min<<endl;
}
void heap_replace_key(int A[],int n,int i,int key){
	A[i]=key;
	while(i>0 && A[parent(i)]>A[i]){
		swap(A,i,parent(i));
		i=parent(i);
	}
}
void insert_heap(int A[],int& n, int key){
	n=n+1;
	A[n-1]=+1252485; //lower limit 
	heap_replace_key(A,n,n-1,key);
}
int main(){
	int m;
	cout<<"enter max size of heap: ";
	cin>>m;
	int A[m];
	for(int i = 0 ; i<m ; i++){
		A[i]=0;
	}
	int n = 0;
	//queuing:
	insert_heap(A,n,5);
		print(A,n);
	insert_heap(A,n,4);
		print(A,n);
	insert_heap(A,n,3);
		print(A,n);
	insert_heap(A,n,2);
		print(A,n);
	insert_heap(A,n,5);
	print(A,n);
	//dequeuing:
	Heap_extract_min(A,n);
	print(A,n);
	Heap_extract_min(A,n);
	print(A,n);
}