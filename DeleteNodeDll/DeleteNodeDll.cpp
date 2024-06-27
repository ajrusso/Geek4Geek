/*
Delete Node in Doubly Linked List

Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

    Input: LinkedList = 1 <--> 3 <--> 4, x = 3
    
    Output: 1 3  
    
    Explanation: After deleting the node at
    position 3 (position starts from 1),
    the linked list will be now as 1 <--> 3.
    
    Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
    
    Output: 5 2 9

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
2 <= size of the linked list(n) <= 105
1 <= x <= n
1 <= node.data <= 109
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* deleteNode(Node*, int);
Node* insertInTail(Node*, int);
void printDll(Node*);


int main() {
    Node* head = NULL;
    int dll[] = {1,5,2,9};
    int x = 4;

    for(int i : dll) {
        head = insertInTail(head, i);
    }

    printDll(head);

    head = deleteNode(head, x);

    printDll(head);
}

Node* deleteNode(Node* head, int x) {
    Node* cur;
    int count; 

    if(!head)
        return NULL;

    if(!head->next) {
        delete head;
        return NULL;
    }

    cur = head; 
    count = 1;
    while(count < x) {
        count++;
        cur = cur->next; 
    }

    if(!cur->prev) {
        cur->next->prev = NULL;
        head = cur->next;
    } else if(!cur->next) {
        cur->prev->next = NULL;
    } else {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    
    delete cur;
    return head;
}

void printDll(Node* head) {
    Node* cur = head;

    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl << endl;
}

Node* insertInTail(Node* head, int data) {
    Node* n = new Node(data);

    if(!head) {
        return n;
    }

    Node* cur = head;
    while(cur->next) {
        cur = cur->next;
    }

    n->prev = cur;
    cur->next = n;
    return head;
}