// Alireza Nikpoosh
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
vector <int> maximum_crossing_subarray(int A[],int low,int mid,int high){
	vector <int> cross;
	int n =(sizeof(A)/sizeof(A[0]));
	int left_sum=-100; //smallest possible integer
	int sum=0;
	int maximum_left_index;
	for(int i = mid;i>=low;i--){
		sum=sum+A[i];
		if(sum>left_sum){
		left_sum=sum;
		maximum_left_index=i;
		}
	}
	int	right_sum=-100; //smallest possible integer
	sum=0;
	int maximum_right_index;
	for(int i = mid+1;i<=high;i++){
		sum=sum+A[i];
		if(sum>right_sum){
		right_sum=sum;
		maximum_right_index=i;
		}
	}
	cross.push_back(maximum_left_index);
	cross.push_back(maximum_right_index);
	cross.push_back(right_sum+left_sum);
	return(cross);
}
vector <int> maximum_subarray(int A[],int low,int high){
	if(low==high){
		vector<int> indices_and_sum={low,high,A[0]};
		return(indices_and_sum);
		}
	int mid = (low + high)/2;
	vector<int>	indices_and_sum_left=maximum_subarray(A,low,mid); 
	vector<int>	indices_and_sum_right=maximum_subarray(A,mid+1,high);	
	vector<int> indices_and_sum_cross=maximum_crossing_subarray(A,low,mid,high);
	
	if(indices_and_sum_left.at(2)>indices_and_sum_right.at(2) && indices_and_sum_left.at(2)>indices_and_sum_cross.at(2)){
		return(indices_and_sum_left);
	}
		if(indices_and_sum_left.at(2)<indices_and_sum_right.at(2) && indices_and_sum_right.at(2)>indices_and_sum_cross.at(2)){
		return (indices_and_sum_right);
	}
	else{
		return (indices_and_sum_cross);
	}
	}

int main(){
	int A[] = {-6, 4, 5, -10, 1, 2, -8, 8, 3, -5, 6, -9, 7};
	int n=sizeof(A)/sizeof(A[0]);
	vector <int> Answer=maximum_subarray(A,0,n-1);
	cout<<"Left index:"<<Answer.at(0)<<endl;
		cout<<"Right index:"<<Answer.at(1)<<endl;
			cout<<"Sum:"<<Answer.at(2)<<endl;
} 
