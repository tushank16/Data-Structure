#include<iostream>
using namespace std;
//Linear queue

//Global Data
int Q[100], MaxSize, Front, Rear;

void createQueue(int size)
{
	MaxSize = size;
	Front = 0;
	Rear = -1;
}

void Enqueue(int e)
{
	Rear++;
	Q[Rear] = e;
}

int Dequeue()
{
	int temp;
	temp = Q[Front];
	Front++;
	return temp;
}

int isFull()
{
	if (Rear == MaxSize-1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
int isEmpty() {
	if (Front > Rear)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
void printQueue() {
	for (int  i = Front; i <= Rear; i++)
	{
		cout << Q[i] << " ";
	}
	cout <<endl;
}

int main()
{
	int ch, e, size;
	cout << "Enter size" << endl;
	cin >> size;
	cout << endl;
	createQueue(size);
	do {
		cout << "\n1.Enqueue\n2.Dequeue\n3.isFull\n4.Print\n0.Exit" << endl;
		cin >> ch;
		cout << endl;
		switch (ch) {
		case 1:
			if (isFull())
				cout << "Queue full" << endl;
			else {
				cout << "Enter value to be Enqueue" << endl;
				cin >> e;
				cout << endl;
				Enqueue(e);
			}
			break;
		case 2:
			if (isEmpty())
				cout << "Queue Empty" << endl;
			else {
				e = Dequeue();
				cout << "Dequeued : " << e << endl;
			}
			break;
		case 3:
			if (isEmpty())
			{
				cout << "Queue Empty" << endl;
			}
			else {
				cout << "is Full : " << isFull() << endl;
			}
			break;

		case 4:
			if (isEmpty())
			{
				cout << "Queue empty" << endl;
			}
			else {
				printQueue();
			}
			break;

		case 0:
			cout << "Exiting" << endl;
			break;

		}
	} while (ch != 0);
	return 0;
}