/*
Find Middle of Circular Doubly Linked List

Given a circular doubly linked list of odd size n, the task is to print the middle element.
The tail of a circular doubly linked list is connected to head via its next pointer, and the previous pointer of head is connected to the tail.

Example 1:

    Input:
    LinkedList: 1<-->2<-->3
    (The first and the last node is connected,
    i.e 3 <--> 1)

    Output: 2

Your Task:
The task is to complete the function findMiddle() which takes head reference as an argument. The function should return the middle element of CDLL. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 103
*/

#include <iostream>

using namespace std;

struct Node  {
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

int findMiddle(Node*);
void printDll(Node*);
Node* insertInTail(Node*, int);


int main() {
    int dll[] = {1,2,3};
    Node* head = NULL;

    for(int i : dll) {
        head = insertInTail(head, i);
    }

    printDll(head);

    cout << "Middle Element: " << findMiddle(head);
}

int findMiddle(Node* head) {
    if(!head)
        return 0;
    
    Node* cur = head;
    Node* tail = head->prev;

    while(cur != tail) {
        cur = cur->next;
        tail = tail->prev;
    }

    return cur->data;
}

void printDll(Node* head) {
    Node* cur = head;

    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while(cur != head);

    cout << endl << endl;
}

Node* insertInTail(Node* head, int data) {
    Node* n = new Node(data);

    if(!head) {
        n->next = n;
        n->prev = n;
        return n;
    }

    Node* cur = head;
    while(cur->next != head) {
        cur = cur->next;
    }

    n->prev = cur;
    n->next = head;
    cur->next = n;
    head->prev = n;
    return head;
}