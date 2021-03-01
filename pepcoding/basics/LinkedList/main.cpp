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

	int getFirst(){
		if(head == NULL){
			cout<<"List is empty! ";
			return -1;
		}else{
			return head->data;
		}
	}

	int getLast(){
		if(head == NULL){
			cout<<"List is empty! ";
			return -1;
		}else{
			return tail->data;
		}
	}

	int getAt(int idx){
		if(idx == 0){
			return getFirst();
		}else if(idx < 0 || idx >= size){
			return -1;

		}else if(idx == size-1){
			return getLast();
		}else{
			Node* temp = head;

			while(idx--){
				temp = temp->next;
			}

			return temp->data;
		}
	}

	void reverseList(){
		Node *cur = head;
		Node *prev = NULL;

		while(cur != NULL){
			Node *temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		tail = head;
		head = prev;
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
	li->addNode(140);
	li->addNode(46);
	li->addNode(68);
	li->addNode(9);
	li->addNode(72);
	li->display();

	cout<<"5th Indexed data = "<<li->getAt(5)<<endl;
	cout<<"-2 Indexed data = "<<li->getAt(-2)<<endl;
	cout<<"First Indexed data = "<<li->getFirst()<<endl;
	cout<<"Last Indexed data = "<<li->getLast()<<endl;

	cout<<"Reversing the list..."<<endl;
	li->reverseList();
	li->display();
	

	delete li;


	return 0;
}