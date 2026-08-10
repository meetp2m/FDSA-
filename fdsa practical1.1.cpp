#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    int key;
    cout<<"Enter number of elements: ";
    cin>>n;
    
    int a[n];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i - 1;

        while(j>=0 && a[j]>key)
        {
            a[j + 1]=a[j];
            j--;
        }
            a[j + 1]=key;
    }
    cout<<"Sorted Array: ";
    for(i=0;i<n;i++)
    {
        cout <<a[i]<<" ";
    }
    return 0;
}
