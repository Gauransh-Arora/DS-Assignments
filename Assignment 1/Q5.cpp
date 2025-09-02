// Write a program to find sum of every row and every column in a two-dimensional 
// array. 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m , n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Enter the element at position " << i << " " << j << ": ";
            cin >> arr[i][j];
        }
    }
    cout << "The matrix is: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The sum of every row is: " << endl;
    for(int i = 0; i < m; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += arr[i][j];
        }
        cout << sum << endl;
    }

    cout << "The sum of every column is: " << endl;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += arr[j][i];
        }
        cout << sum << " ";
    }


    
    return 0;
}