/*
Write a program to count the number of occurrences of a given key in a singly linked
list and then delete all the occurrences.
Input: Linked List : 1->2->1->2->1->3->1 , key: 1
Output: Count: 4 , Updated Linked List: 2->2->3.
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* head = nullptr;

ListNode* convertArr2LL(int arr[], int n) {
    head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i=1; i<n; i++) {
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(ListNode* head) {
    ListNode* temp = head;
    while(temp) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int countdelete(ListNode*& head, int key) {
    int count = 0;
    ListNode* temp = head;
    ListNode* prev = nullptr;
    
    while(temp) {
        if(temp->val == key) {
            ListNode* nodeToDelete = temp;
            if(prev == nullptr) {
                head = head->next;
                temp = head;
            }
            else {
                prev->next = temp->next;
                temp = temp->next;
            }
            delete nodeToDelete;
            count++;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = convertArr2LL(arr, n);
    cout<<"Linked List: ";
    print(head);
    cout << endl;
    int key = 1;
    int count = countdelete(head, key);
    cout<<"Count: "<<count<<endl;
    cout<<"Updated Linked List: ";
    print(head);
    return 0;
}