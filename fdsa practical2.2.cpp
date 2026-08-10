#include<iostream>
using namespace std;

int recursive(int a[],int low,int high,int key)
{
    if(low>high)
        return -1;

    int mid=(low+high)/2;

    if(a[mid]==key)
        return mid;

    if(key<a[mid])
        return recursive(a,low,mid-1,key);

    return recursive(a,mid+1,high,key);
}

int main()
{
    int n,key,a[100];
    cout<<"Enter number of books: ";
    cin>>n;
    cout<<"Enter sorted book codes:"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter code to search: ";
    cin>>key;

    int low=0,high=n-1,iterative=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            iterative=mid;
            break;
        }
        if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    cout<<"Iterative: "<<iterative<<endl;
    cout<<"Recursive: "<<recursive(a,0,n-1,key)<<endl;

    return 0;
}
