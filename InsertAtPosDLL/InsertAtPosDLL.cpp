/*
Doubly Linked List Insertion at Given Position

Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.

Example 1:

Input:
    LinkedList: 2<->4<->5
    p = 2, x = 6 
    
    Output: 2 4 5 6
    
    Explanation: p = 2, and x = 6. So, 6 is
    inserted after p, i.e, at position 3
    (0-based indexing).

Example 2:

Input:
    LinkedList: 1<->2<->3<->4
    p = 0, x = 44
    
    Output: 1 44 2 3 4
    
    Explanation: p = 0, and x = 44 . So, 44
    is inserted after p, i.e, at position 1
    (0-based indexing).

Your Task:
The task is to complete the function addNode() which head reference, position and data to be inserted as the arguments, with no return type.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
0 <= p < N
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void addNode(Node*, int, int);
void printDLL(Node*);


int main() {
    int pos = 1;
    int data = 27;
    Node* head = new Node(8);
    addNode(head, 0, 5);
    addNode(head, 1, 1);
    addNode(head, 2, 10);
    addNode(head, 3, 5);
    addNode(head, 4, 9);
    addNode(head, 5, 9);
    addNode(head, 6, 3);
    addNode(head, 7, 5);
    addNode(head, 8, 6);
    addNode(head, 9, 6);
    addNode(head, 10, 2);


    printDLL(head);
    addNode(head, pos, data);
    printDLL(head);
}

void addNode(Node* head, int pos, int data) {
    Node* n = new Node(data);
    Node* cur = head;
    int count = 0;

    if(!head) {
        head = n;
        return;
    }

    while(count < pos) {
        cur = cur->next;
        count++;
    }

    n->next = cur->next;
    n->prev = cur;
    if(cur->next)
        cur->next->prev = n;
    cur->next = n;

}

void printDLL(Node* head) {
    Node* cur = head;
    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}