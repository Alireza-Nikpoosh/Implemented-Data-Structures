#include<iostream>

using namespace std;



int main () {
	int x;
	cin>>x;
	int rev = 0 ,r;
	int temp = x;
	while(temp >= 1){
		r = temp%10;
		rev = rev*10 + r;
		temp /= 10;
	}
	bool x_prime = true;
	bool rev_prime = true;
	for(int i = 2 ; i<= x/2 ; i++){
		if(x % i == 0){
			x_prime = false;
			break;
		}
	}
	for(int i = 2; i<= rev/2 ; i++){
		if(rev%i == 0){
			rev_prime = false;
			break; 
		}
	}
	cout<<rev<<endl;
	if(rev_prime == true && x_prime == true){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
    return 0;
}
