#include <iostream>

using namespace std;

struct Stack
{
    int top = -1;
    int arr[100];

    bool isFull()
    {
        return top == 100 - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            ++top;
            arr[top] = x;
            cout << "Element added successfully" << endl;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is already empty" << endl;
        }
        else
        {
            // cout << top << endl;
            // cout << arr[top] << endl;

            cout << arr[top] << " Deleted " << endl;
            top--;
        }
    }

    void display()
    {

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void peek()
    {
        cout << "Top Element " << arr[top] << endl;
    }
};

int main()
{
    Stack st;
    int x;
    int flag = 1;
    while (flag)
    {
        int choice;
        cout << "-----Menu-----" << endl;
        cout << "1. push()" << endl;
        cout << "2. pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. display()" << endl;
        cout << "6. peek()" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> x;
            st.push(x);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            if (st.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 4:
            if (st.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;
        case 5:
            st.display();
            break;
        case 6:
            st.peek();
            break;
        case 7:
            flag = 0;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}