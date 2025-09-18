#include <iostream>

using namespace std;

typedef struct{
    int arr[100];
    int front , rear;
} queue;

queue init(){
    queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int size(queue q){
    return (q.rear - q.front + 1);
}

int isEmpty(queue q){
    return ((q.front == -1) || (q.front > q.rear));
}

int isFull(queue q){
    return (q.rear == 99);
}

int front(queue q){
    if(isEmpty(q)){
        cout << "Queue is empty" << endl;
    }else{
        return q.arr[q.front];
    }
}

queue enqueue(queue q, int x){
    if(isFull(q)){
        cout << "Queue is full" << endl;
    }else{
        if(q.front == -1){
            q.front = 0;
        }
        q.rear = q.rear + 1;
        q.arr[q.rear] = x;
    }
    return q;   
}

queue dequeue(queue q){
    if(isEmpty(q)){
        cout << "Queue is empty" << endl;
    }else{
        q.front = q.front + 1;
    }
    return q;
}

void print(queue q){
    for(int i=q.front ; i<= q.rear ; i++){
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int flag = 1;
    queue q = init();

    while(flag){
        int choice , x;
        cout << "-----Menu-----" << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. display()" << endl;
        cout << "6. peek()" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter you choice: " ; 
        cin >> choice;

        switch (choice)
        {           
        case 1:
            cout << "Enter number: ";
            cin >> x;
            q = enqueue(q , x);
            break;
        
        case 2:
            q = dequeue(q);
            break;
        
        case 3:
            if(isEmpty(q)){
                cout << "Queue is empty" << endl;
            }else{
                cout << "Queue is not empty" << endl;
            }
            break;
        
        case 4:
            if(isFull(q)){
                cout << "Queue is full" << endl;
            }else{
                cout << "Queue is not full" << endl;
            }
            break;
        
        case 5:
            print(q);
            break;
        
        case 6:
            cout << front(q) << endl;
            break;
        
        case 7:
            flag = 0;
            break;
        
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    }

    return 0;       
}