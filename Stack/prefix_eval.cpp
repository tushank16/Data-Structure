#include<iostream>
#include<string.h>
using namespace std;
//prefix Evaluation
int s[100], MaxSize, tos;

void initStack(int size)
{
	MaxSize = size - 1;
	tos = -1;
}

void push(int e)
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
	char prefix[50],temp;
	int len, sum = 0;
	cout << "Enter prefix" << endl;
	cin >> prefix;
	len = strlen(prefix);		//length of prefix
	//character Array reversal
	for (int j = 0; j <=len/2; j++)
	{
		temp = prefix[j];
		prefix[j] = prefix[len - j - 1];
		prefix[len - j - 1] = temp;
	}
	initStack(len);				//instiantiating initstack
	//prefix eval logic
	for (int i = 0; i < len; i++)
	{
		if (prefix[i] == '+')
		{
			int a = pop();
			int b = pop();
			sum = a + b;
			push(sum);
		}
		if (prefix[i] == '-')
		{
			int a = pop();
			int b = pop();
			sum = a - b;
			push(sum);
		}
		if (prefix[i] == '*')
		{
			int a = pop();
			int b = pop();
			sum = a * b;
			push(sum);
		}
		if (prefix[i] == '/')
		{
			int a = pop();
			int b = pop();
			sum = a / b;
			push(sum);
		}
		if ('0' <= prefix[i] && prefix[i] < '10')
		{
			int psh = (int)prefix[i];
			psh = psh - 48;
			push(psh);
		}
	}
	cout << "Answer of prefix: " << sum;
	return 0;
}
