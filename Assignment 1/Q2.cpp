/*
Design the logic to remove the duplicate elements from an Array and after the 
deletion the array should contain the unique elements. 
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

    int temp[n];
    int j = 0;
    for(int i=0 ; i<n ; i++){
        int flag = 0;
        for(int k=0 ; k<j ; k++){
            if(arr[i]==temp[k]){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            temp[j] = arr[i];
            j++;
        }
    }

    cout << "The array after removing the duplicate elements is: ";
    for(int i=0 ; i<j ; i++){
        cout << temp[i] << " ";
    }

    return 0;
}