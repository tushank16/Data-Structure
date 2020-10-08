#include<iostream>
using namespace std;
int S[100], tos, maxSize;
//Functions

void initStack(int size){
	maxSize = size;
	tos = -1;
}

void push(int e){
	//Increment tos
	tos++;
	//accept e
	S[tos] = e;
}
int isFull(){
	if (tos== maxSize-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int pop(){
	int temp;
	temp =  S[tos];
	tos--;
	return temp;
}
int isEmpty(){
	if (tos == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int atTop(){
	return (S[tos]);
}
void printStack(){
	for (int i = tos; i > -1; i--)
	{
		cout<<" "<<S[i];
	}
	cout << endl;
}
void calc(){
	cout<<"In calculator"<<endl;
	if (tos == -1)
	{
		cout<<"All braces OK"<<endl;
	}
	if (tos < -1)
	{
		cout<<"Opeaning braces missing"<<endl;
	}
	if (tos > -1)
	{
		cout<<"Closing braces missing"<<endl;
	}
}

int main()
{
	cout<<"Enter Braces { or } \n\nFor Exit enter e\n\nfor calculate enter c\n";
	char openbrace ='{';
	char closebrace='}';
	initStack(50);
	char ip;
	do
	{
		cin>>ip;
		if (ip == openbrace)
		{
				/*if (isFull())
				{
					cout<<"Stack Full";
				}
				else*/
				{
					int e = 1;
					push(e);
				}
			cout<<": push(e)"<<endl;
		}
		else if (ip == closebrace)
		{
				/*if (isEmpty())
				{
					cout<<"coudnt start with closebrace '}'";
				}
				else*/
				{
					pop();
				}
			cout<<": pop()"<<endl;
		}
		else if (ip == 'c')
		{
			calc();	
		}
		else
		{
			cout<<"Enter { or }"<<endl;
		}
			
	} while (ip!='e');

	cout<<"Exited"<<endl;
	return 0;
}