
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char c)
{
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    return 0;
}

int main()
{
    string s, ans="";
    stack<char> st;

    cout<<"Enter infix expression: ";
    cin>>s;

    for(char c:s)
    {
        if(c>='0' && c<='9')
            ans+=c;

        else if(c=='(')
            st.push(c);

        else if(c==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }

        else
        {
            while(!st.empty() && st.top()!='(' &&
                  priority(st.top())>=priority(c))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    cout<<"Postfix expression: "<<ans;

    return 0;
}
