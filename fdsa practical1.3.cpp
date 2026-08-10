#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of words: ";
    cin>>n;

    string a[100];

    cout<<"Enter words:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int max=0;
    for(int i=1;i<n;i++)
    {
        if(a[i].length()>a[max].length())
        {
            max=i;
        }
    }
    cout<<"Longest word: "<<a[max]<<endl;
    cout<<"Number of letters: "<<a[max].length()<<endl;

    return 0;
}
