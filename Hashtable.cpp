// Alireza Nikpoosh
#include <iostream>
#include <string>
using namespace std;
class node{ //every node is an instance of this class
	public:
	int key;
	string name;
	node* next;
	node(int x,string i){
		key=x;		
		name=i;
		next=NULL;
	}
};
class linkedlist{
	public:
		 //points to the next node of what is initilized
		node* head;
		linkedlist(){
		head = NULL;
	}

	void insert(int key,string i){
		if(head == NULL){ //if we're adding the first element
			node* topnode=new node(key,i);
			head=topnode;
			return;
		}
		else{
				node* topnode=new node(key,i);
				
				node* iterator=head; //iterator initilized at head
				while(iterator->next != NULL){ //untill iterator points to the node 
					iterator=iterator->next; // 
				}
				iterator -> next = topnode;
				return;
			}

	}
		void list_delete(int k){
			
		if(head == NULL){ 
			cout<<"There's no key to terminate";
			return;
		}

		else{ 
			int len=1;
			int key_position=len;
			node* target=head;
			node* iterator = head;
			while(iterator->next != NULL){
				if(iterator->key==k){
					key_position=len;
					target=iterator;
				}
				len++;
				iterator=iterator->next;
			}
					if(iterator->key==k){
					key_position=len;
					target=iterator;
				}
			if(key_position==1 && target->key==k){
				if(head->next != NULL){
					node* temp=head;
					delete head;
					head=temp->next;
				}	
				else{
					head=NULL;
				}
			}
			else if(key_position == len && target->key==k){
				node* iterator=head;
				while(iterator->next != target){
				iterator=iterator->next;
				}
				iterator->next=NULL;
				delete target;
			}
			else{
				node* iterator=head;
				while(iterator->next != target){
				iterator=iterator->next;
				}
				node* temp=target->next;
				iterator->next=temp;
				delete target;
			}
		}
	}
string search(int k){
	node* iterator=head;
	while(iterator->key != k){
			if(iterator->next==NULL){
			return "not found";
			}
		iterator=iterator->next;
	}

	return iterator->name;
}
void print(){
		if(head==NULL){
			cout<<"NULL"<<endl;
			return;
		}
		node* iterator = head;
		while(iterator -> next !=NULL){
			cout<<"("<<iterator->key<<","<<iterator->name<<")"<<" -> ";
			iterator = iterator->next;
		}
				cout<<"("<<iterator->key<<","<<iterator->name<<")"<<endl;
	}
};
int hash_function(int pn,int n){	
int temp=pn;
int r,sum=0;
while(temp>1){
	r = temp%10;
	temp = temp/10;
	sum += r;
	}	
return sum%n;
}

int main(){

int phone_number_temp;
string name;
linkedlist hashtable_demo[3];
	hashtable_demo[hash_function(3344,3)].insert(3344,"Ali");
	hashtable_demo[hash_function(3321,3)].insert(3321,"Hasan");
	hashtable_demo[hash_function(3200,3)].insert(3200,"Sadegh");
	hashtable_demo[hash_function(3203,3)].insert(3203,"Alireza");
	hashtable_demo[hash_function(3211,3)].insert(3211,"Nahid");
	for( int i = 0 ; i<3 ; i++ ){
	cout<<i<<": ";
	hashtable_demo[i].print();
}
cout<<endl;
cout<<"deleting number 3200:"<<endl;
hashtable_demo[hash_function(3200,3)].list_delete(3200);
	for( int i = 0 ; i<3 ; i++ ){
	cout<<i<<": ";
	hashtable_demo[i].print();
}
cout<<"searching for number 3203:"<<endl;
cout<<"this number belongs to: "<<hashtable_demo[hash_function(3203,3)].search(3203)<<endl;
cout<<endl;


int n;
cout<<"how many phone numbers may you want save?"<<endl;
cin>>n;
linkedlist hashtable[n];
while(true){
		string input;
		getline(cin,input);
		if(input=="add"){
			cout<<"number:";
			cin>>phone_number_temp;
			cout<<endl<<"name:";
			cin>>name;
			hashtable[hash_function(phone_number_temp,n)].insert(phone_number_temp,name);
				for( int i = 0 ; i<n ; i++ ){
				cout<<i<<": ";
				hashtable[i].print();
			}
		}
		if(input=="delete"){
			cout<<"number:";
			cin>>phone_number_temp;
			hashtable[hash_function(phone_number_temp,n)].list_delete(phone_number_temp);
				for( int i = 0 ; i<n ; i++ ){
				cout<<i<<": ";
				hashtable[i].print();
			}	
		}
		if(input=="search"){
			cout<<"number:";
			cin>>phone_number_temp;
			cout<<"this number belongs to: "<<hashtable[hash_function(phone_number_temp,n)].search(phone_number_temp)<<endl;
		}
		if(input=="exit"){
			break;
		}
	}
}


