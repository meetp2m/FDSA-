#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

int main() {
    Node* top = NULL;
    int n;

    cout << "Enter number of operations: ";
    cin >> n;

    while (n--) {
        int ch;
        cout << "1. Visit  2. Back: ";
        cin >> ch;

        if (ch == 1) {
            string page;
            cout << "Enter page: ";
            cin >> page;

            Node* p = new Node;
            p->page = page;
            p->next = top;
            top = p;

            cout << "Current Page: " << top->page << endl;
        }
        else if (ch == 2) {
            if (top == NULL) {
                cout << "No History" << endl;
            }
            else {
                Node* p = top;
                top = top->next;
                delete p;

                if (top == NULL)
                    cout << "No History" << endl;
                else
                    cout << "Current Page: " << top->page << endl;
            }
        }
    }

    return 0;
}
