#include<iostream>
#include<string>
using namespace std;

// infix to postfix conversion

char s[100];
int MaxSize, tos;

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

char pop()
{
	char temp;
	temp = s[tos];
	tos--;
	return temp;
}

int isEmpty()
{
	if (tos == -1)
		return 1;
	else
		return 0;
}
int main()
{
	char infix[50], postfix[50];
	int i, len, pi = 0;
	cout << "Enter infix" << endl;
	cin >> infix;
	len = strlen(infix);

	initStack(len);
	for (i = 0;i < len ; i++)
	{
		char ch = infix[i];
		if (ch == '(')
		{
			cout<<"("<<endl;
			push(ch);
		}
		if (ch == ')')
		{
			cout << ")" << endl;
			while (s[tos] != '(')
			{
				postfix[pi] = pop();
				cout << "added to postfix " << postfix[pi] << endl;
				pi++;
			}
			pop();	//this is to remove '(' from stack
		}
		
		if (ch == '+' || ch == '-' ||  ch == '*' ||  ch == '/')
		{
			cout << "operator " << ch << endl;
			char pre = s[tos];
			if (pre == '+' || pre == '-' || pre == '*' || pre == '/')
			{
				cout << "precedence check of " << ch << " and operator on stack " << pre << endl;
				if ((ch == '+' || ch == '-') & (pre == '+' || pre == '-'))
				{
					cout << "precedence  of " << ch << " and " << pre << " is same or less " << endl;
					postfix[pi] = pop();
					cout << "operator added to postfix " << postfix[pi]<< endl;
					pi++;
				}
			}
			cout << "operator added on stack " << ch << endl;
			push(ch);
		}
		if ('0' <= ch && ch < '10')
		{	
			cout << "added to postfix "<<ch<< endl;
			postfix[pi] = ch;
			pi++;
		}
		
	}

	while (isEmpty() != 1)
	{
		postfix[pi] = pop();
		cout << "Popping opretor from stack " << postfix[pi] << endl;
		pi++;
	}
	postfix[pi] = '\0';
	cout << "postfix generated " << postfix << endl;

	return 0;
}