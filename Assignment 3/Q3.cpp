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
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    Stack st;
    char expr[100];

    cout << "Enter an expression: ";
    cin >> expr;

    int i = 0;
    bool balanced = true;

    while (expr[i] != '\0') {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) {
                balanced = false;
                break;
            }
            char topChar = st.pop();
            if (!isMatchingPair(topChar, ch)) {
                balanced = false;
                break;
            }
        }
        i++;
    }

    if (!st.isEmpty()) {
        balanced = false;
    }

    if (balanced) {
        cout << "Balanced Parentheses" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
