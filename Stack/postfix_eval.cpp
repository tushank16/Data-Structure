#include<iostream>
#include<string.h>
using namespace std;
//postfix Evaluation
int s[100],MaxSize, tos;

void initStack(int size)
{
	MaxSize = size - 1;
	tos = -1;
}

void push(char e)
{
	tos++;
	s[tos] = e;
}

int pop()
{
	int temp;
	temp = s[tos];
	tos--;
	return temp;
}

int main()
{
	char infix[50], postfix[50];
	int len, sum=0;
	cout << "Enter postfix"<<endl;
	cin >> postfix;
	len = strlen(postfix);
	initStack(len);
	for (int i = 0; i < len; i++)
	{
		if (postfix[i] == '+')
		{
			int a = pop();
			int b = pop();
			cout << b <<" plus "<< a <<endl;
			sum  = add(b,a);
			cout << "sum " << sum << endl;
			push(sum);
		}
		if (postfix[i] == '-')
		{
			int a = pop();
			int b = pop();
			cout << b << " minus " << a << endl;
			sum = sub(b, a);
			cout << "sum " << sum << endl;
			push(sum);
		}
		if (postfix[i] == '*')
		{
			int a = pop();
			int b = pop();
			cout << b << " multiply " << a << endl;
			sum = mul(b, a);
			cout << "sum " << sum << endl;
			push(sum);
		}
		if (postfix[i] == '/')
		{
			int a = pop();
			int b = pop();
			cout << b << " divide " << a << endl;
			sum = divi(b, a);
			cout << "sum " << sum << endl;
			push(sum);
		}
		if ('0' <= postfix[i] && postfix[i] < '10')
		{
			cout << "number " << postfix[i]<<endl;
			int psh = (int)postfix[i];
			psh = psh - 48;
			cout << "push " << psh << endl;
			push(psh);
		}
			
	}
	cout << "Answer of postfix: "<< sum;
	return 0;
}
