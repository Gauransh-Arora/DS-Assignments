// Find the matrix multiplication 

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "Enter the size of both the arrays: ";
    cin >> n;

    int arr1[n][n];
    int arr2[n][n];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << "Enter the element of the first array: ";
            cin >> arr1[i][j];
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << "Enter the element of the second array: ";
            cin >> arr2[i][j];
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }

    int arr3[n][n];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            arr3[i][j] = 0;
            for(int k=0 ; k<n ; k++){
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    cout << "The matrix multiplication is: \n";
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}