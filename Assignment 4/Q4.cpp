/*
Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
b c Sample O/P: a -1 b b
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    queue<char> q;
    int arr[26]={0};
    for(int i=0;i<str.length();i++)
    {
        q.push(str[i]);
        arr[str[i]-'a']++;
        while(!q.empty())
        {
            if(arr[q.front()-'a']>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<" ";
                break;
            }
        }
        if(q.empty())
        {
            cout<<"-1 ";
        }
    }
    return 0;
}