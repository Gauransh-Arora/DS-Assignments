/*
Reverse the elements of an array
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "The array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    int i=0 , j =n-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    cout << "The reversed array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}