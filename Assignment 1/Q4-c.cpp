// Find the Transpose of a Matrix

#include <bits/stdc++.h>

using namespace std;

int main(){
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

    int transpose[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            transpose[i][j] = arr[j][i];
        }
    }

    cout << "The transpose of the matrix is: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}