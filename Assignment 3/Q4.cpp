#include <iostream>
using namespace std;

struct Stack {
    int top = -1;
    char arr[100];

    bool isFull() { return top == 99; }
    bool isEmpty() { return top == -1; }

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
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

void infixToPostfix(char infix[], char postfix[]) {
    Stack st;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[j++] = st.pop();
            }
            st.pop();
        }
        else { 
            while (!st.isEmpty()) {
                char topOp = st.peek();

                int topPrec = 0, curPrec = 0;

                if (topOp == '^') topPrec = 3;
                else if (topOp == '*' || topOp == '/') topPrec = 2;
                else if (topOp == '+' || topOp == '-') topPrec = 1;

                if (ch == '^') curPrec = 3;
                else if (ch == '*' || ch == '/') curPrec = 2;
                else if (ch == '+' || ch == '-') curPrec = 1;

                if (topPrec >= curPrec) {
                    postfix[j++] = st.pop();
                } else break;
            }
            st.push(ch);
        }
        i++;
    }

    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
