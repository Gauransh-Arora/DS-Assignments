/*
Develop a Menu driven program to demonstrate the following operations of Arrays 
——MENU——- 
1.CREATE 
2. DISPLAY 
3. INSERT 
4. DELETE 
5. LINEAR SEARCH 
6. EXIT 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        cout << "-----MENU-----" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        int n;
        cout << "Enter your choice: ";
        cin >> n;
        
        int size;
        int arr[100];
        switch(n){
            case 1: {
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the elements of the array: ";
                for(int i = 0; i < size; i++){
                    cin >> arr[i];
                }
                break;
            }
            case 2: {
                cout << "The array is: ";
                for(int i = 0; i < size; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 3: {
                cout << "Enter the element to be inserted: ";
                int element;
                cin >> element;
                cout << "Enter the position to be inserted: ";
                int position;
                cin >> position;
                for(int i = size; i > position; i--){
                    arr[i] = arr[i-1];
                }
                arr[position] = element;
                size++;
                break;
            }
            case 4: {
                cout << "Enter the position to be deleted: ";
                int position;
                cin >> position;
                for(int i = position; i < size; i++){
                    arr[i] = arr[i+1];
                }
                size--;
                break;
            }
            case 5: {
                cout << "Enter the element to be searched: ";
                int element;
                cin >> element;
                for(int i = 0; i < size; i++){
                    if(arr[i] == element){
                        cout << "Element found at position " << i << endl;
                        break;
                    }
                }
                cout << "Element not found" << endl;
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }        
    }
    return 0;
}