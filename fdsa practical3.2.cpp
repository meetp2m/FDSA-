#include<iostream>
using namespace std;

int main()
{
    int n,i,count0=0,count1=0,count2=0;
    int a[100];

    cout<<"Enter number of buckets: ";
    cin>>n;

    cout<<"Enter colour codes:"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        if(a[i]==0)
            count0++;
        else if(a[i]==1)
            count1++;
        else
            count2++;
    }

    i=0;
    while(count0>0)
    {
        a[i]=0;
        i++;
        count0--;
    }
    while(count1>0)
    {
        a[i]=1;
        i++;
        count1--;
    }
    while(count2>0)
    {
        a[i]=2;
        i++;
        count2--;
    }

    cout<<"Sorted colour codes: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;

    return 0;
}
