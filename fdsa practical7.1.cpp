#include <iostream>
using namespace std;

int main() {
    int n, q[100], front=0, rear=-1, count=0;
    int choice, value;

    cout<<"Enter queue size: ";
    cin>>n;

    while(true) {
        cout<<"\n1.Join  2.Serve  3.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1) {
            cout<<"Enter token: ";
            cin>>value;

            if(count==n)
                cout<<"Queue Overflow\n";
            else {
                rear=(rear+1)%n;
                q[rear]=value;
                count++;
                cout<<"Front: "<<q[front]<<endl;
            }
        }
        else if(choice==2) {
            if(count==0)
                cout<<"Queue Underflow\n";
            else {
                front=(front+1)%n;
                count--;

                if(count==0)
                    cout<<"Queue Empty\n";
                else
                    cout<<"Front: "<<q[front]<<endl;
            }
        }
        else if(choice==3)
            break;
        else
            cout<<"Invalid choice\n";
    }
    return 0;
}
