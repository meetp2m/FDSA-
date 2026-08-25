#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void front(int x)
{
    Node *n=new Node{x,head};
    head=n;
}
void end(int x)
{
    Node *n=new Node{x,NULL};

    if(head==NULL)
    {
        head=n;
        return;
    }
    Node *t=head;
    while(t->next!=NULL)
        t=t->next;
    t->next=n;
}

void position(int x,int p)
{
    if(p<=0)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    if(p==1)
    {
        front(x);
        return;
    }
    Node *t=head;
    for(int i=1;i<p-1&&t!=NULL;i++)
        t=t->next;
    if(t==NULL)
    {
        cout<<"Invalid position"<<endl;
        return;
    }
    Node *n=new Node{x,t->next};
    t->next=n;
}
void show()
{
    Node *t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
int main()
{
    int n,ch,x,p;

    cout<<"Enter number of operations: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"\n1. Insert at Front";
        cout<<"\n2. Insert at End";
        cout<<"\n3. Insert at Position";
        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch==1)
        {
            cout<<"Enter patient token: ";
            cin>>x;
            front(x);
        }
        else if(ch==2)
        {
            cout<<"Enter patient token: ";
            cin>>x;
            end(x);
        }
        else if(ch==3)
        {
            cout<<"Enter patient token: ";
            cin>>x;
            cout<<"Enter position: ";
            cin>>p;
            position(x,p);
        }

        cout<<"Queue: ";
        show();
    }
    return 0;
}
