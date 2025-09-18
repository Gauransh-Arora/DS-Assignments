/*
Write a program to implement a stack using (b) One Queue
*/

#include <iostream>
#include <queue>
using namespace std;

struct Stack
{
    queue<int> q;

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << "Pushed " << x << " to stack" << endl;
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty, cannot pop" << endl;
            return;
        }
        int poppedValue = q.front();
        q.pop();
        cout << "Popped " << poppedValue << " from stack" << endl;
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty()
    {
        return q.empty();
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