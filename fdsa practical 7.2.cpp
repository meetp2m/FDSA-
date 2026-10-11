#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    int n,x;
    string op;

    cout<<"Enter number of operations: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Enter operation: ";
        cin>>op;

        if(op=="arrive"){
            cin>>x;
            q.push(x);
        }
        else if(op=="attend"){
            if(!q.empty())
                q.pop();
        }

        if(q.empty())
            cout<<"Current front: Empty"<<endl;
        else
            cout<<"Current front: "<<q.front()<<endl;
    }

    return 0;
}
