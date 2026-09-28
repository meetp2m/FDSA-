#include<iostream>
using namespace std;

struct SNode{
    int data;
    SNode* next;
};

struct DNode{
    int data;
    DNode* next;
    DNode* prev;
};

SNode* shead=NULL;
DNode* dhead=NULL;

void sjoin(int x){
    SNode* n=new SNode{x,NULL};
    if(shead==NULL){
        shead=n;
        n->next=shead;
    }else{
        SNode* t=shead;
        while(t->next!=shead)t=t->next;
        t->next=n;
        n->next=shead;
    }
}

void sleave(int x){
    if(shead==NULL)return;
    SNode*t=shead,*p=NULL;
    do{
        if(t->data==x){
            if(t==shead){
                if(shead->next==shead)shead=NULL;
                else{
                    SNode*last=shead;
                    while(last->next!=shead)last=last->next;
                    shead=shead->next;
                    last->next=shead;
                }
            }else p->next=t->next;
            delete t;
            return;
        }
        p=t;
        t=t->next;
    }while(t!=shead);
}

void sdisplay(){
    if(shead==NULL){
        cout<<"Circle is empty"<<endl;
        return;
    }
    SNode*t=shead;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=shead);
    cout<<endl;
}

void djoin(int x){
    DNode*n=new DNode{x,NULL,NULL};
    if(dhead==NULL){
        dhead=n;
        n->next=dhead;
        n->prev=dhead;
    }else{
        DNode*last=dhead->prev;
        n->next=dhead;
        n->prev=last;
        last->next=n;
        dhead->prev=n;
    }
}

void dleave(int x){
    if(dhead==NULL)return;
    DNode*t=dhead;
    do{
        if(t->data==x){
            if(t->next==t)dhead=NULL;
            else{
                t->prev->next=t->next;
                t->next->prev=t->prev;
                if(t==dhead)dhead=t->next;
            }
            delete t;
            return;
        }
        t=t->next;
    }while(t!=dhead);
}

void ddisplay(){
    if(dhead==NULL){
        cout<<"Circle is empty"<<endl;
        return;
    }
    DNode*t=dhead;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=dhead);
    cout<<endl;
}

int main(){
    int type,n,op,x;
    cout<<"Enter 1 for Singly Circular or 2 for Doubly Circular: ";
    cin>>type;
    cout<<"Enter number of operations: ";
    cin>>n;

    while(n--){
        cout<<"Enter operation: ";
        cin>>op;

        if(op==1){
            cout<<"Enter student: ";
            cin>>x;
            if(type==1)sjoin(x);
            else djoin(x);
        }else if(op==2){
            cout<<"Enter student: ";
            cin>>x;
            if(type==1)sleave(x);
            else dleave(x);
        }else if(op==3){
            cout<<"Current circle: ";
            if(type==1)sdisplay();
            else ddisplay();
        }
    }
    return 0;
}
