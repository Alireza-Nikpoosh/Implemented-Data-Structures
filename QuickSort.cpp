#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
//alireza nikpoosh
void print(int A[]){
  int n = 7;
  for(int i = 0 ; i<n ; i++){
  cout<<A[i]<<" ";
}
cout<<endl;
}
void swap(int A[],int i ,int j){
  int temp=A[i];
  A[i]=A[j];
  A[j]=temp;
}
int partition(int A[],int p,int r){

  int l = p-r;
  int pindex=p-1;
   srand(time(NULL));//generating random number using time 
  int pivot = rand() % l + p; //rand will be between p and r
  swap(A,pivot,r);
  print(A);
  int x=A[r];
  for(int i = p ; i<r ; i++){
    if(A[i]<=x){
    	pindex++;
      swap(A,pindex,i);
    }
  }
  print(A);
  swap(A,r,pindex);
  return pindex;
}
void quicksort(int A[],int p,int r){
  if(p<r){

    int q=partition(A,p,r);
    cout<<q<<endl;
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}


int main() {
int A[]={91, 8, 13, -86, -26, 41, 95};
int n = sizeof(A)/sizeof(A[0]);
 
print(A);
quicksort(A,0,n-1);
print(A);
 srand((unsigned) time(0));
cout<<rand()%n;
}