#include<iostream>
using namespace std;
struct node {
	int data;
	struct node* next;
};
class LinkedList {
	node* root;
public:

	void createList() {
		root = NULL;
	}

	void insertLeft(int e) {
		node* n;
		n = new node;
		n->data = e;
		n->next = NULL;
		if (root == NULL)
			root = n;
		else {
			n->next = root;
			root = n;
		}
	}
	void insertRight(int e) {
		node* n, * t;
		n = new node;
		n->data = e;
		n->next = NULL;
		if (root == NULL)
		root = n;
		else {
			t = root;
			while (t->next != NULL) {
				t = t->next;
			}
			t->next = n;
		}
	}
	void deleteLeft() {
		if (root == NULL)
			cout << "Empty list" << endl;
		else {
			node* t;
			t = root;
			root = root->next;
			cout << "Deleted: " << t->data << endl;
			delete t;
		}
	}
	void deleteRight() {
		if (root == NULL)
			cout << "Empty list" << endl;
		else {
			node* t, * t2;
			t = t2 = root;
			while (t->next != NULL) {
				t2 = t;
				t = t->next;
			}
			t2->next = NULL;
			cout << "Deleted: " << t->data << endl;
			delete t;
		}
	}
	void printList() {
		if (root == NULL)
			cout << "Empty list" << endl;
		else {
			node* t;
			t = root;
			while (t != NULL) {
				cout << t->data << " ";
				t = t->next;
			}
			cout << endl;
		}
	}
	bool search(int key) {

		if (root == NULL) {
			cout << "Empty list" << endl;
			return false;
		}
		else {
			node* t;
			t = root;
			while (t != NULL) {
				if (t->data == key)
				t = t->next;
				return true;
			}
			if (t == NULL) {
				cout << "Not found" << endl;
				return false;
			}
			return false;
		}
	}
	void deleteElement(int key) {
		if (root == NULL)
			cout << "Empty list" << endl;
		else {
			node* t, * t2;
			t = t2 = root;
			while (t != NULL && t->data != key) {
				t2 = t;
				t = t->next;
				cout << "while" << endl;
			}
			if (t != NULL) {
				if (t == root)
					root = root->next;
				else if (t->next == NULL)
					t2->next = NULL;
				else
					t2->next = t->next;
				delete t;
			}
			else {
				cout << "not found" << endl;
			}

		}
	}


};
int main()
{
	
	int no,e;
	cout << "Select operation for Linked List" << endl;
	LinkedList ref;
	ref.createList();
	do {
		cout << "\n1.Insert Left\n2.Insert Right\n3.Delete Left\n4.Delete Right\n5.Printlist\n6.Search\n7.Delete Element\n0.Exit" << endl;
		cin >> no;
		cout << endl;
		switch (no) {
		case 1:
			cout << "\nEnter element for Left Insertion" << endl;
			cin >> e;
			ref.insertLeft(e);
			break;
		case 2:
			cout << "\nEnter element for Right Insertion" << endl;
			cin >> e;
			ref.insertRight(e);
			break;
		case 3:
			ref.deleteLeft();
			break;
		case 4:
			ref.deleteRight();
			break;
		case 5:
			ref.printList();
			break;
		case 6:
			cout << "\nEnter element to be searched" << endl;
			cin >> e;
			ref.search(e);
			break;
		case 7:
			cout << "\nEnter element for deletion" << endl;
			cin >> e;
			ref.deleteElement(e);
			break;
		case 0:
			cout << "Exiting" << endl;
			break;
		}
	} while (no != 0);
	return 0;
}