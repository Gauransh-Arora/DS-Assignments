/*
Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL
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

ListNode* reverseLL(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = convertArr2LL(arr, n);
    cout << "Original Linked List: ";
    print(head);
    cout << endl;
    head = reverseLL(head);
    cout << "Reversed Linked List: ";
    print(head);
    return 0;
}