#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
class DynamicQueue
{
public:
    node *rear, *front;
    void createDQueue();
    void Enqueue(int e);
    void dequeue();
    void printstack();
};

void DynamicQueue:: createDQueue()
{
    rear=front=NULL;
}

void DynamicQueue:: Enqueue(int e)
{
    node *n;
    n = new node;
    n->data=e;
    n->next=NULL;
    if (rear == NULL)
    {
        rear=front=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }    
}

void DynamicQueue:: dequeue()
{
    if (front==NULL)
    {
        cout<<"Empty Queue"<<endl;
    }
    else
    {
        node *t;
        t = front;
        front=front->next;
        cout<<"Poped : "<<t->data<<endl;
        delete t;
    }
}

void DynamicQueue:: printstack()
{
    if (front==NULL)
    {
        cout<<"Empty Queue"<<endl;
    }
    else
    {
        node *t;
        t = front;
        while (t!=NULL)
        {      
            cout<<" "<<t->data;
            t=t->next;
        }
        delete t;
    }
}

int main()
{
	DynamicQueue dq;
	int e,ch=0;
	dq.createDQueue();
	do{
		cout<<"\nEnter Choise\n1:push\n2:pop\n3:print queue\n0:Exit"<<endl;
	    cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter data:";
				cin>>e;
				dq.Enqueue(e);
				break;
			case 2:
				dq.dequeue();
				break;
			case 3:
				dq.printstack();
				break;
			case 0:
				cout<<"Exiting\n\n";
				break;
			default:cout<<"error\n\n";
				break;
		}
		
	}while(ch!=0);
	return 0;
}