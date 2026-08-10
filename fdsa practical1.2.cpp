#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of records: ";
    cin>>n;

    int a[100];
    cout<<"Enter book IDs:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"Books borrowed more than once: ";
    for(int i=0;i<n;i++)
    {
        int count=0;

        for(int j=0;j<n;j++)
        {
            if (a[i]==a[j])
            {
                count++;
            }
        }
        int found=0;

        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                found=1;
            }
        }
        if(count>1 && found==0)
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
