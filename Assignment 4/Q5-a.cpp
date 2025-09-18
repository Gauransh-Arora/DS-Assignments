/*
Write a program to implement a stack using (a) Two queues
*/

#include <iostream>
#include <queue>
using namespace std;

struct Stack
{
    queue<int> q1, q2;

    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        cout << "Pushed " << x << " to stack" << endl;
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty, cannot pop" << endl;
            return;
        }
        int poppedValue = q1.front();
        q1.pop();
        cout << "Popped " << poppedValue << " from stack" << endl;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "Top element: " << s.top() << endl;
    s.pop();
    
    cout << "Top element: " << s.top() << endl;
    s.pop();
    
    cout << "Top element: " << s.top() << endl;
    s.pop();
    
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    
    return 0;
}