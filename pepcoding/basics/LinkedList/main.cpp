#include <bits/stdc++.h>
#define ll long long

using namespace std;

//Node data-type
class Node{

public:
	int data;
	Node* next;
	
};

// creating LL
class LinkedList{

public:

	Node* head;
	Node* tail;
	int size;

	void addNode(int val){

		Node* temp = new Node();
		temp->data = val;
		temp->next = NULL;

		if(size == 0){

			head = temp;
			tail = temp;

		}else{

			tail->next = temp;
			tail = temp;

		}
		size++;
	}

	int si(){
		return size;
	}

	void display(){

		if(head == NULL){

			cout<<"Empty LinkedList";
			return;
		}

		Node* temp = new Node();
		temp = head;
		while(temp != NULL){
			if(temp->next == NULL){
				cout<<temp->data;
			}else{
				cout<<temp->data<<" -> ";
			}

			temp = temp->next;
		}

		cout<<endl<<endl;

	}

	void removeFirst(){
		if(head == NULL){
			cout<<"List is empty!\n";
		}else if(head->next == NULL){
			head = NULL;
			tail = NULL;
			size--;
		}else{
			Node* temp = new Node();
			temp = head;
			head = head->next;
			temp->next = NULL;			//we have to completely remove the head node
			size--;
		}
	}
	
};


int main(){
	
	LinkedList* li = new LinkedList();

	li->addNode(10);
	li->addNode(30);
	li->addNode(40);
	li->addNode(40);
	li->addNode(40);
	li->addNode(50);

	cout<<"Size of the LinkedList is "<<li->si()<<endl<<endl;

	li->display();
	li->removeFirst();
	li->display();
	li->removeFirst();
	li->display();
	li->removeFirst();
	

	delete li;


	return 0;
}