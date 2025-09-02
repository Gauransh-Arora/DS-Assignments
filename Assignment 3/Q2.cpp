#include <iostream>
using namespace std;

struct Stack {
    int top = -1;
    char arr[100];

    bool isFull() {
        return top == 100 - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char x) {
        if (isFull()) {
            cout << "Stack is full" << endl;
        } else {
            arr[++top] = x;
        }
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

int main() {
    Stack st;
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    int i = 0;
    while (str[i] != '\0') {
        st.push(str[i]);
        i++;
    }

    cout << "Reversed string: ";
    while (!st.isEmpty()) {
        cout << st.pop();
    }
    cout << endl;

    return 0;
}
