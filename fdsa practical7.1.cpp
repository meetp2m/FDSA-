#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int q[100];
    int front = 0, rear = -1;
    int choice, value;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> value;

            if (rear == n - 1) {
                cout << "Queue Overflow" << endl;
            } else {
                rear++;
                q[rear] = value;
                cout << "Front: " << q[front] << endl;
            }
        }
        else if (choice == 2) {
            if (front > rear) {
                cout << "Queue Underflow" << endl;
            } else {
                front++;
                if (front <= rear)
                    cout << "Front: " << q[front] << endl;
                else
                    cout << "Queue Empty" << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
