#include <iostream>
#include <stack>
using namespace std;

int priority(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    stack<char> st;
    string ans = "";

    for (char c : s) {
        if (isdigit(c))
            ans += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')') {
            while (st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && priority(st.top()) >= priority(c)) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << ans;

    return 0;
}
