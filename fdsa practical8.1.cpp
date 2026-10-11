#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

Node* insert(Node *root,int x){
    if(root==NULL) return new Node(x);
    if(x<root->data) root->left=insert(root->left,x);
    else if(x>root->data) root->right=insert(root->right,x);
    return root;
}

void inorder(Node *r){
    if(r==NULL) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void preorder(Node *r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node *r){
    if(r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

void levelorder(Node *r){
    if(r==NULL) return;
    queue<Node*> q;
    q.push(r);
    while(!q.empty()){
        Node *t=q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}

int main(){
    Node *root=NULL;
    int n,x;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(int i=0;i<n;i++){
        cin>>x;
        root=insert(root,x);
    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    cout<<"\nLevel order: ";
    levelorder(root);
    cout<<endl;
    return 0;
}
