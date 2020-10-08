#include<iostream>
using namespace std;
int s[50], maxSize, tos;
void initStack(int size) {
	maxSize = size;
	tos = -1;
}
void push(int e) {
	tos++;
	s[tos] = e;
}
bool isFull() {
	if (tos == maxSize - 1)
		return true;
	else
		return false;
}
int pop() {
	int temp = s[tos];
	tos--;
	return temp;
}
bool isEmpty() {
	if (tos == -1)
		return true;
	else
		return false;
}
int atTop() {
	return s[tos];
}
void printStack() {
	
	for (int i = tos; i > -1; i--) {
		cout << " " << s[i];
	}
	cout << endl;
}

int main() {
	int ch, e, size;
	cout << "Enter size" << endl;
	cin >> size;
	cout << endl;
	initStack(size);
	do {
		cout << "1.Push\n2.Pop\n3.AtTop\n4.print\n0.exit" << endl;
		cin >> ch;
		cout << endl;
		switch (ch) {
		case 1:
			if (isFull())
				cout << "Stack full" << endl;
			else {
				cout << "Enter value to be pushed" << endl;
				cin >> e;
				cout << endl;
				push(e);
			}
			break;
		case 2:
			if (isEmpty())
				cout << "Stack Empty" << endl ;
			else {
				e = pop();
				cout << "Popped" << e << endl;
			}
			break;
		case 3:
			if (isEmpty())
				cout << "Stack Empty";
			else {
				cout << "At top" << atTop() << endl;
			}

		case 4:
			if (isEmpty())
				cout << "Stack empty" << endl;
			else {
				printStack();
			}
			break;

		case 0:
			cout << "Exiting" << endl;
			break;

		}
	} while (ch != 0);


	return 0;
}