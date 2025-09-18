/*
Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/

#include <bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    int n = q.size();
    int halfSize = n / 2;
    queue<int> q1;

    for(int i=0 ; i<halfSize ; i++){
        q1.push(q.front());
        q.pop();
    }

    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    vector<int>  v = {4, 7, 11, 20, 5, 9};
    for (int i = 0; i < v.size(); i++)
    {
        q.push(v[i]);
    }

    interleaveQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return  0;
}