/*
Is the Doubly Linked List Circular

Given a doubly linked list, the task is to check if it is circular or not.

Example 1:

    Input:
    LinkedList: 2<->3<->4<->5<->6

    Output: 0

Example 2:

    Input:
    LinkedList: 4<-->6
    (the last and the first node is connected,
    i.e. 6 <--> 4

    Output: 1

User Task:
The task is to complete the function isCircular() which takes head reference as an argument. The function should return true if the doubly LL is circular and false if it is not. (if the returned value if true, the driver code prints 1, otherwise 0)

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 106
*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

bool isCircular(Node*);
void printDll(Node*);


int main() {
    Node* head = new Node(4);
    head->next = new Node(6);
    head->next->next = head;
    head->next->prev = head;
    head->prev = head->next;

    printDll(head);

    cout << (isCircular(head) ? "Is " : "Is NOT ") << "Circular" << endl;  
}

bool isCircular(Node* head) {
    if(!head)
        return true;
        
    Node* cur = head;
    do{
        if(!cur)
            return false;
        
        cur = cur->next;
    } while(cur != head);

    return true;
}

void printDll(Node* head) {
    Node* cur = head;

    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while(cur != head);

    cout << endl << endl;
}