#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void insert(int x)
{
    Node *n=new Node{x,NULL};
    if(head==NULL)
        head=n;
    else
    {
        Node *t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void del(int x)
{
    if(head==NULL)
        return;

    if(head->data==x)
    {
        head=head->next;
        return;
    }

    Node *t=head;

    while(t->next!=NULL&&t->next->data!=x)
        t=t->next;

    if(t->next!=NULL)
        t->next=t->next->next;
}

void forward(Node *t)
{
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

void reverse(Node *t)
{
    if(t==NULL)
        return;

    reverse(t->next);
    cout<<t->data<<" ";
}

int main()
{
    int n,x;
    cout<<"Enter number of patients: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }
    cout<<"Queue: ";
    forward(head);
    cout<<"Enter token to delete: ";
    cin>>x;
    del(x);
    cout<<"After delete: ";
    forward(head);
    cout<<"Reverse: ";
    reverse(head);
    cout<<endl;

    return 0;
}
