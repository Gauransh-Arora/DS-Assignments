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

void insertAtBeginning(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << val << " at the beginning" << endl;
}

void insertAtEnd(int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Inserted " << val << " at the end" << endl;
}

void insertBefore(int target, int val) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    if (head->val == target) {
        insertAtBeginning(val);
        return;
    }
    
    ListNode* temp = head;
    while (temp->next != nullptr && temp->next->val != target) {
        temp = temp->next;
    }
    
    if (temp->next == nullptr) {
        cout << "Node with value " << target << " not found" << endl;
    } else {
        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " before " << target << endl;
    }
}

void insertAfter(int target, int val) {
    ListNode* temp = head;
    while (temp != nullptr && temp->val != target) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Node with value " << target << " not found" << endl;
    } else {
        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " after " << target << endl;
    }
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    ListNode* temp = head;
    head = head->next;
    cout << "Deleted " << temp->val << " from the beginning" << endl;
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    if (head->next == nullptr) {
        cout << "Deleted " << head->val << " from the end" << endl;
        delete head;
        head = nullptr;
        return;
    }
    
    ListNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    
    cout << "Deleted " << temp->next->val << " from the end" << endl;
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecificNode(int val) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    if (head->val == val) {
        deleteFromBeginning();
        return;
    }
    
    ListNode* temp = head;
    while (temp->next != nullptr && temp->next->val != val) {
        temp = temp->next;
    }
    
    if (temp->next == nullptr) {
        cout << "Node with value " << val << " not found" << endl;
    } else {
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted node with value " << val << endl;
        delete nodeToDelete;
    }
}

void searchNode(int val) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    ListNode* temp = head;
    int position = 1;
    
    while (temp != nullptr) {
        if (temp->val == val) {
            cout << "Node with value " << val << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    
    cout << "Node with value " << val << " not found" << endl;
}

void display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    cout << "List: ";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

int main(){
    int choice, val, target;
    
    cout << "-----Menu-----" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert before a node" << endl;
    cout << "4. Insert after a node" << endl;
    cout << "5. Delete from beginning" << endl;
    cout << "6. Delete from end" << endl;
    cout << "7. Delete specific node" << endl;
    cout << "8. Search node" << endl;
    cout << "9. Display list" << endl;
    cout << "10. Exit" << endl;
    
    cout << "\nEnter your choice: ";
    cin >> choice;
    
    while(choice != 10) {
        switch(choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                insertAtBeginning(val);
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                insertAtEnd(val);
                break;
                
            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert before " << target << ": ";
                cin >> val;
                insertBefore(target, val);
                break;
                
            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert after " << target << ": ";
                cin >> val;
                insertAfter(target, val);
                break;
                
            case 5:
                deleteFromBeginning();
                break;
                
            case 6:
                deleteFromEnd();
                break;
                
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                deleteSpecificNode(val);
                break;
                
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                searchNode(val);
                break;
                
            case 9:
                display();
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
        cout << "\nEnter your choice: ";
        cin >> choice;
    }

    return 0;
}