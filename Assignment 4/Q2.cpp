/*
Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

Queue create(int size)
{
    Queue q;
    q.size = size;
    q.front = 0;
    q.rear = -1;
    q.Q = new int[q.size];
    return q;
}

int isEmpty(Queue q)
{
    return (q.rear == -1);
}

int isFull(Queue q)
{
    return ((q.rear + 1) % q.size == q.front && q.rear != -1);
}

void enqueue(Queue &q, int x)
{
    if (isFull(q))
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        q.rear = (q.rear + 1) % q.size;
        q.Q[q.rear] = x;
    }
}

void dequeue(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        if (q.front == q.rear)
        {
            q.front = 0;
            q.rear = -1;
        }
        else
        {
            q.front = (q.front + 1) % q.size;
        }
    }
}

void display(Queue q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int i = q.front;
    do
    {
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    cout << endl;
}

void peek(Queue q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << q.Q[q.front] << endl;
    }
}

int main()
{
    Queue q = create(5);

    int choice, x;
    cout << "-----Menu-----" << endl;
    cout << "1. enqueue()" << endl;
    cout << "2. dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. display()" << endl;
    cout << "6. peek()" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter you choice: ";
    cin >> choice;

    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> x;
            enqueue(q, x);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            if (isEmpty(q))
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
            break;
        case 4:
            if (isFull(q))
                cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" << endl;
            break;
        case 5:
            display(q);
            break;
        case 6:
            peek(q);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Enter you choice: ";
        cin >> choice;
    }
    return 0;
}
