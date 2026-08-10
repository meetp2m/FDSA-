#include<iostream>
using namespace std;

int search(int a[],int n,int key)
{
    if(n==0)
    {
        return -1;
    }

    if(a[0]==key)
    {
        return 0;
    }

    int x=search(a+1,n-1,key);

    if(x==-1)
    {
        return -1;
    }

    return x+1;
}

int main()
{
    int n,key;
    int a[100];

    cout<<"Enter number of plates: ";
    cin>>n;
    cout<<"Enter plates:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter plate to search: ";
    cin>>key;

    int linear=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            linear=i;
            break;
        }
    }

    int recursive=search(a,n,key);
    cout<<"Linear Search: "<<linear<<endl;
    cout<<"Recursive Search: "<<recursive<<endl;

    return 0;
}
