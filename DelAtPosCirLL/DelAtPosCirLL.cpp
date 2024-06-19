/*
Circular Linked List Delete at Position

Given a linked list of size n, you have to delete the node at position pos of the linked list and return the new head. The position of initial node is 1.
The tail of the circular linked list is connected to the head using next pointer.

Example 1:

    Input:
        LinkedList: 1->2->3->4->5
        (the first and last node are connected,
        i.e. 5 --> 1)
        position: 4
    
    Output: 1 2 3 5

Example 2:

    Input:
        LinkedList: 2->5->7->8->99->100
        (the first and last node are connected,
        i.e. 5 --> 1)
        position: 6
    
    Output: 2 5 7 8 99

Your Task:
The task is to complete the function deleteAtPosition() which takes head reference and pos as argument and returns reference to the new head node, which is then used to display the list. The printing is done automatically by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
2 <= number of nodes <= 103
1 <= pos <= n
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* deleteAtPosition(Node*, int);
void  printList(Node*);


int main() {
    // Create Circular Linked List
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;
    int pos = 1;

    // Print Original Circular Linked List
    printList(head);

    // Delete Given Position
    cout << "Delete Position " << pos << endl << endl;
    head = deleteAtPosition(head, pos);

    // Print Modified Circular Linked List
    printList(head);
}

Node* deleteAtPosition(Node* head, int pos) {
    if(!head)
        return NULL;
    if(head == head->next)
        return NULL;

    // Case 1: Delete Head
    if(pos == 1) {
        head->data = head->next->data;
        Node* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return head;
    }

    // Case 2: Delete Middle and Tail
    int count = 1;
    Node* cur = head;
    while(count != pos - 1) {
        count++;
        cur = cur->next;
    }

    Node* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;

    return head;
}

void printList(Node* head) {
    Node* cur = head;
    
    if(cur) {
        do{
            cout << cur->data << " ";
            cur = cur->next;
        } while(cur != head);
    }
    cout << endl << endl;
}