#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
};

class CircularLinkedList
{
	public:
	struct node *root;
	void createDLL()
	{
		root=NULL;
	}
	void insertLeft(int e)
	{
		node *n;
		n=new node;
		n->data=e;
		n->left==NULL;
		if(root==NULL)
		{
			root=n;
        }	
		else
		{
			n->right=root;
			root->left=n;
            root=n;		
        }
	}
    void deleteLeft()
	{
		node *t;
		if(root==NULL){
		    cout<<"Empty List"<<endl;
        }
		if (root->left==NULL &&  root->right ==NULL )
		{
			cout<<"Deleted: "<<root->data;
			root=NULL;
			delete t;
		}
		else
		{
			t=root;
			root=root->right;
			root->left = NULL;
			cout<<"Deleted: "<<t->data;
			delete t;
		}
	}
	void insertRight(int e)
	{
		node *n,*t;
		n=new node;
		n->data=e;
		n->right=n->left=NULL;
		if(root==NULL)
		{
			root=n;
		}
		else
		{
			t=root;
			while(t->right!=NULL)
			{
				t=t->right;
			}
			t->right=n;
			n->left=t;
		}
	}
	
	void deleteRight()
	{
		if(root==NULL){
		    cout<<"Empty List"<<endl;
		}
		
		else
		{
			node *t,*t2;
			t=root;
			if (root->left==NULL && root->right ==NULL )
			{
				cout<<"Deleted: "<<root->data;
				root=NULL;
			}
			else{
				while(t->right!=NULL)
				{
					t=t->right;
				}
				t2=t->left;
				t2->right = NULL;
				cout<<"Deleted: "<<t->data;
				delete t;
			}
			
		}
	}
	void ReversePrint()
	{
		if(root==NULL)
		{
			cout<<"Empty List"<<endl;
		}
		else
        {
		    node *t;
            t=root;
            while(t->right!=NULL)
            {
                t=t->right;
            }   
		    while(t!=NULL)
		    {
			    cout<<" "<<t->data;
			    t=t->left;
		    }
		}
	}
};

int main()
{
	CircularLinkedList DLL;
	DLL.createDLL();
	int ch=0,e;
	do
	{
		cout<<"\n1.insertleft:\n2.insertRight:\n3.deleteLeft:\n4.deleteRight:\n5.printList:\n0.Exit:\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter Data: ";
				cin>>e;
				DLL.insertLeft(e);
				break;
				
			case 2:
				cout<<"Enter Data: ";
				cin>>e;
				DLL.insertRight(e);
				break;
				
			case 3:
				DLL.deleteLeft();
				break;
				
			case 4:
				DLL.deleteRight();
				break;
				
			case 5:
				DLL.ReversePrint();
				break;
				
			case 0:
				cout<<"Exiting"<<endl;
				break;
				
			default:
				cout<<"Invalid Input"<<endl;
		}
	}while(ch!=0);
	return 0;
}
