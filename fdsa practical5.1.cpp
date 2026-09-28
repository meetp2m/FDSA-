#include<iostream>
using namespace std;

struct Node{
    string song;
    Node*prev;
    Node*next;
};

Node*head=NULL;

void addBegin(string s){
    Node*n=new Node{s,NULL,head};
    if(head!=NULL) head->prev=n;
    head=n;
}

void addEnd(string s){
    Node*n=new Node{s,NULL,NULL};
    if(head==NULL){
        head=n;
        return;
    }
    Node*t=head;
    while(t->next!=NULL) t=t->next;
    t->next=n;
    n->prev=t;
}

void insertAfter(string x,string s){
    Node*t=head;
    while(t!=NULL&&t->song!=x) t=t->next;
    if(t==NULL) return;
    Node*n=new Node{s,t,t->next};
    if(t->next!=NULL) t->next->prev=n;
    t->next=n;
}

void deleteFirst(){
    if(head==NULL) return;
    Node*t=head;
    head=head->next;
    if(head!=NULL) head->prev=NULL;
    delete t;
}

void display(){
    Node*t=head;
    int count=0;
    while(t!=NULL){
        cout<<t->song<<" ";
        count++;
        t=t->next;
    }
    cout<<"\nCount: "<<count<<endl;
}

int main(){
    addBegin("A");
    display();

    addEnd("B");
    display();

    addEnd("C");
    display();

    insertAfter("B","D");
    display();

    deleteFirst();
    display();

    return 0;
}
