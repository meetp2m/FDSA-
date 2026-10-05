#include <iostream>
using namespace std;

int main() {
    int n,top = -1;
    int stack[100];

    cout<<"Enter stack size: ";
    cin>>n;

    int q;
    cout<<"Enter number of operations: ";
    cin>>q;

    while(q--) {
        int ch;
        cout<<"Enter 1 for Push, 2 for Pop: ";
        cin>>ch;

        if(ch == 1) {
            int x;
            cout<<"Enter value: ";
            cin>>x;

            if(top == n - 1)
                cout<<"Stack Full\n";
            else {
                top++;
                stack[top] = x;
                cout<<"Top = " <<stack[top]<<"\n";
            }
        }
        else if(ch == 2) {
            if(top == -1)
                cout<<"Stack Empty\n";
            else {
                cout<<"Removed = " <<stack[top]<<"\n";
                top--;
            }
        }
    }
    return 0;
}
