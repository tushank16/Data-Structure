#include<iostream>
using namespace std;
int S[100], tos, maxSize;
void initStack(int size) {
	maxSize = size;
	tos = -1;
}

void push(int e) {
	//Increment tos
	tos++;
	//accept e
	S[tos] = e;
}
int isFull() {
	if (tos == maxSize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int pop() {
	int temp;
	temp = S[tos];
	tos--;
	return temp;
}
int isEmpty() {
	if (tos == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int atTop() {
	return (S[tos]);
}
void printStack() {
	for (int i = tos; i > -1; i--)
	{
		cout << " " << S[i];
	}
	cout << endl;
}
int main()
{
	cout << "Enter no" << endl;
	int k, n, no;
	cin >> no;
	cout << endl;
	initStack(50);
	do
	{
		n = no / 2;
		//cout << n << endl;
		n = n * 2;
		//cout << n << endl;
		k = no - n;
		//cout <<"Binary"<< k << endl;
		no = no / 2;
		push(k);
	
	} while (no!=0);
	cout << endl;
	printStack();
	cout << "ended" << endl;
	return 0;
}