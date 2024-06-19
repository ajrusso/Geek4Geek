/*
Circular Linked List Head Insert

Given a circular linked list of size N, you need to insert an element data before the head and make it the new head. The tail of the linked list is connected to head.

Example 1:

    Input:
        LinkedList: 1->2->3->4
        (the first and last node is connected,
        i.e. 4 --> 1)
        data = 10
    
    Output: 10 1 2 3 4

Example 2:

Input:
    LinkedList: 1 2
    (the first and last node is connected,
    i.e. 2 --> 1)
    data = 5

Output: 5 1 2

Your Task:
The task is to complete the function insertInHead() which takes head reference and data as arguments and returns the head of the updated list. The printing is done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
1 <= Number of nodes <= 1000
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

Node* insertInHead(Node*, int);
void printList(Node*);


int main() {
    int data = 10;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    cout << "Original: ";
    printList(head);

    head = insertInHead(head, data);

    cout << "Insert " << data << " @ Head: ";
    printList(head);
}

Node* insertInHead(Node* head, int data) {
    Node* node = new Node(data);

    if(!head) {
        node->next = node;
        return node;
    }

    node->next = head->next;
    head->next = node;
    node->data = head->data;
    head->data = data;

    return head;
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