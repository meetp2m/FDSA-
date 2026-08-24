#include<iostream>
using namespace std;

int main()
{
    int n,i,j,temp,key;
    int a[100],b[100],c[100];

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter marks:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        c[i]=a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"Bubble Sort: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[min])
                min=j;
        }
        temp=b[i];
        b[i]=b[min];
        b[min]=temp;
    }
    cout<<"Selection Sort: ";
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    for(i=1;i<n;i++)
    {
        key=c[i];
        j=i-1;
        while(j>=0 && c[j]>key)
        {
            c[j+1]=c[j];
            j--;
        }
        c[j+1]=key;
    }
    cout<<"Insertion Sort: ";
    for(i=0;i<n;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}
