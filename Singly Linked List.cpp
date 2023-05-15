#include<iostream>
using namespace std;

struct node{
	node* next;
	int data;
};

node *head = NULL;

void insert(){
	int input;
	cout << "\nEnter the value you want to insert -> ";
	cin >> input;
	node *temp = new node;
	if (head == NULL){
		temp -> next = NULL;
		temp -> data = input;
		head = temp;
		cout << endl << head -> data << " has been added to the list\n";
	}
	else{
		node *traveler = head;
		while (traveler -> next != NULL){
			traveler = traveler -> next;
		}
		traveler -> next = temp;
		temp -> data = input;
		temp -> next = NULL;
		cout << endl << temp -> data << " has been added to the list\n";
	}
}
void remove(){
	if (head == NULL)
		cout << "\nList is empty\n";
	else if (head -> next == NULL){
		cout << endl << head -> data << " has been deleted\n";
		delete head;
		head = NULL;
	}
	else{
		node *traveler = head;
		while (traveler -> next -> next != NULL){
			traveler = traveler -> next;
		}
		cout << endl << traveler -> next -> data << " has been deleted\n";
		delete traveler -> next;
		traveler -> next = NULL;
	}
}
void print(){
	if (head != NULL){
		node *traveler = head;
		int i = 1;
		while (traveler != NULL){
			cout << endl << i << ". Element -> " << traveler -> data;
			traveler = traveler -> next;
			i++;
		}
		cout << endl;
	}
	else
		cout << "\nList is empty\n";
}
void find(){
	if (head != NULL){
		node *traveler = head;
		bool isFound = false;
		int input, i = 1;
		cout << "\nEnter the element you want to find -> ";
		cin >> input;
		while (traveler != NULL){
			if (traveler -> data == input){
				isFound = true;
				cout << endl << input << " is found at " << i << ". node\n";
			}
			i++;
			traveler = traveler -> next;
		}
		if (isFound == false)
			cout << endl << input << " did not found\n";
	}
	else 
		cout << "\nThere is nothing to find\n";
}

int main(){
	int menu = 1;
	while (menu){
		cout << "\n0 - Quit\n1 - Insert\n2 - Remove\n3 - Print\n4 - Find\nYour input -> ";
		cin >> menu;
		switch (menu){
			case 0:
				cout << "\nGood bye\n";
				break;
			case 1:
				insert();
				break;
			case 2:
				remove();
				break;
			case 3:
				print();
				break;
			case 4:
				find();
				break;
			default:
				cout << "\nPlease enter a valid input\n";
		}
	}
}

