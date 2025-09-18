/*
Write a program to find the middle of a linked list.
Input: 1->2->3->4->5
Output: 3
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

int length(ListNode* head) {
    int cnt = 0;
    ListNode* temp = head;
    while(temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

ListNode* middleNode(ListNode* head) {
    int cnt = length(head);
    ListNode* temp = head;
    int mid = cnt/2;
    while(mid--) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = convertArr2LL(arr, n);
    print(head);
    cout<<endl;
    ListNode* mid = middleNode(head);
    cout<<mid->val;
    return 0;
}