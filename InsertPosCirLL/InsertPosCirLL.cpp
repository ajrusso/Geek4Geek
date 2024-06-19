/*
Circular Linked List Insertaion At Position

You are given a circular linked list of size N. You need to insert an element data just after the given position pos.
The position of first element is 1. If the given position is greater than N, then don't insert anything as it is not possible.
As the given linked list is circular, it means that the tail is connected to the head of the list.

Example 1:

Input:
    LinkedList: 1->2->3->4->5
    (the first and last node is connected,
    i.e. 5 --> 1)
    position = 6, element = 10

Output: 1 2 3 4 5 

Example 2:

Input:
    LinkedList: 2->4->6->7->5->1->0
    (the first and last node is connected,
    i.e. 0 --> 2)
    position = 7,data = 99

Output: 2 4 6 7 5 1 0 99

Your Task:
You only need to complete the function insertAtPosition that takes head, pos, and data as parameters. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N, pos <= 103
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

void insertAtPosition(Node*, int, int);
void printList(Node*);


int main() {
    int pos = 3;
    int data = 99;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;

    cout << "Original: ";
    printList(head);

    insertAtPosition(head, pos, data);

    cout << "Insert " << data << " @ Pos: ";
    printList(head);
}

void insertAtPosition(Node* head, int pos, int data) {
    
    if(head) {
        Node* node = new Node(data);
        Node* cur = head;
        int count = 1;

        while(cur->next != head && count < pos) {
            cur = cur->next;
            ++count;
        }

        if(count == pos) {
            node->next = cur->next;
            cur->next = node;
        }
    }
}

void printList(Node* head) {
    cout << "{ ";
    if(head) {
        Node* cur = head;
        do{
            cout << cur->data << " ";
            cur = cur->next;
        } while(cur != head);
    }
    cout << "}";
    cout << endl << endl;
}