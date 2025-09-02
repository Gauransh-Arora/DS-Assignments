#include <iostream>
using namespace std;

struct Stack {
    int top;
    int arr[100];

    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
};

int main() {
    Stack st;
    char expr[100];

    cout << "Enter a postfix expression (single-digit operands, no spaces): ";
    cin >> expr;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c >= '0' && c <= '9') {
            int num = c - '0';
            st.push(num);
        } else {
            int val1 = st.pop();
            int val2 = st.pop();

            if (c == '+') st.push(val2 + val1);
            else if (c == '-') st.push(val2 - val1);
            else if (c == '*') st.push(val2 * val1);
            else if (c == '/') st.push(val2 / val1);
        }
    }

    cout << "Result = " << st.pop() << endl;
    return 0;
}
