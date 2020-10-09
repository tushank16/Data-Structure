#include<iostream>
using namespace std;
//Circular queue

//Global Data
int Q[100], MaxSize, Front, Rear, cnt;

void createQueue(int size)
{
	MaxSize = size;
	Front = 0;
	Rear = -1;
	cnt = 0;
}

int isFull()
{
	if (cnt == MaxSize)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
int isEmpty() {
	if (cnt == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void Enqueue(int e)
{
	if (isFull())
	{
		cout << "\n Queue is full";
	}
	else {
		Rear = (Rear + 1) % MaxSize;
		cnt++;
		Q[Rear] = e;
	}
	
}

int Dequeue()
{
	int temp;
	cnt--;
	temp = Q[Front];
	Front = (Front + 1) % MaxSize;
	return temp;
}

void printQueue() {
	int  i, c;
	i = Front;
	c = 0;
	while (c < cnt)
	{
		cout << Q[i] << " ";
		i = (i + 1) % MaxSize;
		c = c + 1;
	}
	cout << endl;
}

int main()
{
	int ch, e, size;
	cout << "Enter size" << endl;
	cin >> size;
	cout << endl;
	createQueue(size);
	do {
		cout << "\n\n1.Enqueue\n2.Dequeue\n3.isFull\n4.Print\n0.Exit" << endl;
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
				cout << "Queue not full" << endl;
			}
			else {
				cout << "Queue Full : " <<cnt << endl;
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