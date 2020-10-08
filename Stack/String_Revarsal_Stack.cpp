#include<iostream>
#include <string>

using namespace std;
int  tos, maxSize;
char S[100];
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
		cout <<S[i];
	}
	cout << endl;
}
int main()
{
	string str;
	cout << "Enter a string: "<<endl;
	getline(cin, str);
	int length =str.size();
	//cout << length <<endl;
	initStack(length);
	for ( int i = 0; i < length; i++)
	{
		push(str[i]);
	}
	//cout << endl;
	printStack();
	cout << "ended" << endl;
	return 0;
}