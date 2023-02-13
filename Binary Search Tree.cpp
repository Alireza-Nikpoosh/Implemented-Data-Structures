#include<iostream>
#include<string>

using namespace std;


class Node{
public:
 int key;
 Node* parent;
 Node* LC;
 Node* RC;

 Node(){
  LC=NULL;
  RC=NULL;
  parent=NULL;
 }
};


class BST{
public:
 Node* root=NULL;
 int num_nodes=0;
 
 
 
	 void insert(int x){
		  Node* newnode = new Node;
		  if(root==NULL){
		   root=newnode;
		   root->key = x; //x will be the root 
		   return;
		  }
		  
		  Node* i = root;
		  while(true){ //the loop is bound to break because we will reach a NULL node eventually
		   if(x <= i->key){
			    if(i->LC == NULL){
			     newnode->key = x;
			     newnode->parent=i;
			     i->LC=newnode;
			     num_nodes++;
			     return;
			    }
			    else{
			     i=i->LC;
			    }
		   }
		   else{
			    if(i -> RC == NULL){
			     newnode->key = x;
			     newnode->parent=i;
			     i->RC=newnode;
			     num_nodes++;
			     return;
			    }
			    else{
			     i=i->RC;
			    }
		   }
		 }
	 }
	 
	void inorder_traversal(Node* i){
		if(i == NULL){
			return;
		}
	  inorder_traversal(i->LC);
	  cout<<i->key<<",";
	  inorder_traversal(i->RC);
	}
	
	int Tree_Min(Node* i){
		if(i->LC == NULL){
			return i->key;
		}
		Tree_Min(i->LC);
	}
	int Tree_Max(Node* i){
		if(i->RC == NULL){
			return i->key;
		}
		Tree_Max(i->RC);
	}

	Node* Tree_search(Node* i , int x){
		if(i == NULL || i->key == x){
			return i;
		}
		else if(x > i->key){
			return Tree_search(i->RC , x);
		}
		else
			return Tree_search(i->LC , x);
	}
	int Successor(int x){
		Node* i = Tree_search(root,x); //find the node holding the value x
		if(i -> RC != NULL){ //if there is a subtree we call the Tree_Min function on it
			return Tree_Min(i->RC);
		}
		Node* j=i->parent; //else we traverse in reverse
		while(j != NULL && i == j->RC){
			i=j;
			j=j->parent;
		}
		return j->key;
	}
	int PreDecessor(int x){
		Node* i = Tree_search(root,x);
		if(i->LC != NULL){
			return Tree_Max(i->LC);
		}
		Node* j = i->parent;
		while(j != NULL && i == j->LC){
			i=j;
			j=j->parent;
		}
		return j->key;
	}

	void Tree_Delete(int x){
		Node* i = Tree_search(root,x); //finding the node holding value x
		if(i->parent == NULL){//if i has no parent so we're deleting the root
			if(i->LC != NULL && i->RC != NULL){ // if it has two children
				Node* S=Tree_search(root,Tree_Min(i->RC));
				int temp = S->key;
				Tree_Delete(S->key);
				i->key = temp;
			}
			else{
				delete i;
			}
			return;
		}
		
		
		bool is_right; //this boolean indicates if i is the right child of its parent or not
		if(i->key > i->parent->key)
			is_right=true;
		else is_right=false;
		if(i->LC == NULL && i->RC == NULL){//case 1: no children
				if(is_right){
					i->parent->RC=NULL;
				}
				else {
					i->parent->LC=NULL;
				}
				delete i;
			}
		else if(i->RC == NULL){ //case 2: i only has a left child
			Node* temp = i->parent; //i's parent
			if(is_right){ //so i was the left child of its own parent and we change the LC of temp
				temp->RC=i->LC;
				delete i;
			}
			else{ // i was the right child and we change the RC of temp
				temp->LC=i->LC;
				delete i;
			}
		}
		else if(i->LC == NULL){ //case 3: i has only a right child
			Node* temp= i->parent;
			if(is_right){ //so i was the left child of its own parent and we change the LC of temp
				temp->RC=i->RC;
				delete i;
			}
			else{ // i was the right child and we change the RC of temp
				temp->LC=i->RC;
				delete i;
			}
		}
		else{ //case 4 : i has two children
		Node* S=Tree_search(root,Tree_Min(i->RC));//we find i's successor
		int temp = S->key;
		Tree_Delete(S->key);
		i->key = temp;
		}
}
};


 
int main(){
BST a;
int i = -1;
int Test_Array[9]={15,24,5,7,1,13,27,18,19};
//inserting the static array elements in a Binary Search Tree whish is a dynamic data structure
for(int i = 0 ; i<sizeof(Test_Array)/sizeof(Test_Array[0]) ; i++){
	a.insert(Test_Array[i]);
}
cout<<"the minimum element: "<<a.Tree_Min(a.root)<<endl;
cout<<"the maximum element: "<<a.Tree_Max(a.root)<<endl;
a.inorder_traversal(a.root);
cout<<endl;
Node* search_0 = a.Tree_search(a.root,27);
Node* search_1 = a.Tree_search(a.root,11);
cout<<"27 is at adress "<<search_0<<" and holds the correct value of "<<search_0->key<<endl;
cout<<"1 is at adress "<<search_1<<" so it's not in the tree"<<endl;
cout<<"the PreDecessor and Successor of 19:"<<endl;
cout<<a.PreDecessor(19)<<endl;
cout<<a.Successor(19)<<endl;
cout<<"the PreDecessor and Successor of 19:"<<endl;
cout<<a.PreDecessor(13)<<endl;
cout<<a.Successor(13)<<endl;
cout<<"the tree after deleting 7:"<<endl;
a.Tree_Delete(7);
a.inorder_traversal(a.root);
cout<<endl<<"the tree after deleting the root:"<<endl;
a.Tree_Delete(15);
a.inorder_traversal(a.root);
}
