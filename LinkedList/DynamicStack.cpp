#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class DynamicStack
{
private:
    node *tos;
public:
    void initStack();
    void push(int e);
    void pop();
    void printStack();
};

void DynamicStack:: initStack()
{
    tos=NULL;
}
void DynamicStack:: push(int e)
{
    node *n;
    n = new node;
    n->data=e;
    n->next=NULL;

    if (tos==NULL)
    {
        tos=n;        
    }
    else
    {
        n->next=tos;
        tos=n;    
    }  
}
void DynamicStack:: pop()
{
    if (tos==NULL)
    {
        cout<<"Dynamic Stack Empty"<<endl;
    }
    else
    {
        node *t;
        t = tos;
        tos=tos->next;
        cout<<"Popped : "<<t->data<<endl;
        delete t;
    }  
}
void DynamicStack:: printStack()
{
    //printing will be LIFO
    if (tos==NULL)
    {
        cout<<"Dynamic Stack Empty"<<endl;
    }
    else
    {
        node *t;
        t = tos;
        while (t!=NULL)
        {
            cout<<" "<<t->data;
             t=t->next;
        }
        cout<<endl;
    }  
}

int main(){
    int ch=0,e=0;
    DynamicStack ds;
    ds.initStack();
    cout<<"Dynamic Stack"<<endl;
    do
    {
        cout<<"\n1. Push\n2. Pop\n3. PrintStack\n0. Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 0:
            cout<<"Exiting"<<endl;
            break;
        case 1:
            cout<<"Enter no to push"<<endl;
            cin>>e;
            ds.push(e);
            break;
        case 2:
            ds.pop();
            break;
        case 3:
            ds.printStack();
            break;    
        default:
            cout<<"Enter Valid input"<<endl;
            break;
        }
    } while (ch!=0);
        
    return 0;
}

