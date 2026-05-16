#include<bits/stdc++.h>
using namespace std;

class queue_ST{
    public:
    stack<int> s1;
    stack<int> s2;

    void push(int x) {
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if(!s1.size()) {
            cout << " under flow" << endl;
            return INT_MIN;
        }
        int el =s1.top();
        s1.pop();
        return el;
    }

    int peek() {
        if(s1.empty()) {
            cout << " No elements" << endl;
            return INT_MIN;
        }
        return s1.top();
    }


};

int main() {
    queue_ST q;
    int choice;
    int value;

    while (true) {
        cout << "Choose an operation:\n";
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. peek\n";
        cout << "4. exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                q.push(value);
                break;
            case 2: {
                int result = q.pop();
                if (result != INT_MIN) {
                    cout << "Popped: " << result << '\n';
                }
                break;
            }
            case 3: {
                int result = q.peek();
                if (result != INT_MIN) {
                    cout << "Front: " << result << '\n';
                }
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

 
}