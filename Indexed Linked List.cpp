// Alireza Nikpoosh
#include <iostream>

using namespace std;
class node{ //every node is an instance of this class
	public:
	int data;
	int index;
	node* next;
	node(int x,int i){
		data=x;		
		index=i;
		next=NULL;
	}
};
class linkedlist{
	public:
		int index; //points to the next node of what is initilized
		node* head;
		linkedlist(){
		index=0;
		head = NULL;
	}
	void list_delete_at(int i){ // assuming 0<=i<=index
		if(head == NULL){ //if we're adding the first element
			cout<<"There's no node to terminate";
			return;
		}
		else if(i==0){
			if(index != 1){
					node* temp=head->next;
					delete head;
				 	head = temp;
					node* iterator = head;
						while(iterator->next != NULL){
						iterator->index=iterator->index - 1;	
						iterator= iterator ->next;
					}
					iterator->index=iterator->index - 1;
					index--;
				return;
				}
			else{
				head=NULL;
				index--;
			}
	}
		else if(i==index-1){ 
			node* iterator = head;
			while(iterator->next->next != NULL){
				iterator=iterator->next;
			}
			
			node* temp_1 =iterator->next; //points to the node we want to delete
			iterator -> next=NULL; //points to NULL since it's the last index
			delete temp_1;
	
			index--;
		}
		else{ 
			node* iterator = head;
			while(iterator->index != i-1){
				iterator=iterator->next;
			}
			
			node* temp_1 =iterator->next; //points to the node we want to delete
			node* temp_2 = iterator -> next ->next;
			iterator->next=temp_2;
			delete temp_1;
			
			iterator = iterator->next;
			while(iterator->next != NULL){
			iterator->index=iterator->index - 1;	
			iterator= iterator ->next;
				}
			iterator->index=iterator->index - 1;
			index--;
		}

	}
	void insert(int data,int i){
		if(head == NULL){ //if we're adding the first element
			node* topnode=new node(data,0);
			index++;
			head=topnode;
			return;
		}
		else if(i==index){
				node* topnode=new node(data,index);
				
				node* iterator=head; //iterator initilized at head
				while(iterator->next != NULL){ //untill iterator points to the node 
					iterator=iterator->next; // 
				}
				iterator -> next = topnode;
				index++;
				return;
			}

		else if(i==0){

					node* newnode=new node(data,i);
					node* tempadress = head;
					head=newnode;
					newnode -> next = tempadress;
					node* iterator = newnode ->next;
						while(iterator->next != NULL){
						iterator->index=iterator->index + 1;	
						iterator= iterator ->next;
					}
					iterator->index=iterator->index + 1;
					index++;
					return;	
				}
		else{
				node* newnode=new node(data,i);
				
				node* iterator = head;
			
				while(iterator->index != i-1){
					
					iterator= iterator ->next;
				}
				
				node* tempadress = iterator->next;
				
				iterator->next=newnode;
				newnode->next=tempadress;
			
				iterator = newnode ->next;
				while(iterator->next != NULL){
					iterator->index=iterator->index + 1;	
					iterator= iterator ->next;
				}
				iterator->index=iterator->index + 1;	
				index++;
			}
	}
void search(int k){
	node* iterator = head;
	cout<<"indexes with key value of "<<k<<": "<<endl;
	while(iterator !=NULL){
		if(iterator -> data == k){
			cout<<iterator->index<<endl;
		}
		iterator=iterator -> next;
	}
}
void swap_nodes(int i , int j){
	node* iterator_i = head; //finding node with index i
	node* temp_prev_i=NULL;//points to the previous node
	while(iterator_i->index != i){
		temp_prev_i=iterator_i;
		iterator_i=iterator_i->next;
	}
	
	node* iterator_j = head; //finding node with index i
	node* temp_prev_j=NULL;//points to the previous node
	while(iterator_j->index != j){
		temp_prev_j=iterator_j;
		iterator_j=iterator_j->next;
	}
	
	//if i is the first node
    if (temp_prev_i == NULL)
    	head = iterator_j;
    else
        temp_prev_i->next = iterator_j;
 
  	//if j is the first node
    if (temp_prev_j == NULL)
 	    head = iterator_i;
    else
        temp_prev_j->next = iterator_i;
 	

    node* temp = iterator_j->next;
    iterator_j->next = iterator_i->next;
    iterator_i->next = temp;
    
    //swap the indexes
    int temp_index=iterator_i->index;
    iterator_i->index=iterator_j->index;
    iterator_j->index=temp_index;
}
void print(){
		if(index==0){
			cout<<"empty list"<<endl;
			return;
		}
		node* iterator = head;
		while(iterator -> next !=NULL){
			cout<<"("<<iterator->data<<","<<iterator->index<<")"<<" -> ";
			iterator = iterator->next;
		}
				cout<<"("<<iterator->data<<","<<iterator->index<<")"<<endl;
	}
};

int main(){
	cout<<"Linked List Implementation:"<<endl;
	linkedlist a;
	cout<<"inserting 3,5,7,6,5,12,20 adjacently: "<<endl;
	a.insert(3,0);
	a.insert(5,1);
	a.insert(7,2);
	a.insert(6,3);
	a.insert(5,4);
	a.insert(12,a.index);
	a.insert(20,a.index);
	a.print();

	cout<<"inserting 15 at index 2:"<<endl;
	a.insert(15,2);
	a.print();
	
	cout<<"deleting node at index 3:"<<endl;
	a.list_delete_at(0);
	a.print();
		
	cout<<"deleting node at the last index:"<<endl;
	a.list_delete_at(a.index-1);
	a.print();

		
	cout<<"deleting node at index 0:"<<endl;
	a.list_delete_at(0);
	a.print();
	

	a.search(5);
	
	cout<<"swapping nodes with index 1 and 3: "<<endl;
	a.swap_nodes(1,3);
	a.print();
	
	cout<<"swapping nodes with index 0 and 4: "<<endl;
	a.swap_nodes(0,4);
	a.print();
	
}
