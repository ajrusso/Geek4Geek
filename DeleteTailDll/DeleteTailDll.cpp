/*
Delete Tail of Doubly Linked List

Given a doubly linked list of size n, you have to delete the tail (last element) in the linked list.

Example 1:

    Input:
    LinkedList: 1<-->2

    Output:
    1
    1

Example 2:

    Input:
    LinkedList: 2<-->5<-->7<-->8<-->99<-->100

    Output:
    2 5 7 8 99
    99 8 7 5 2

Your Task:

The task is to complete the function deleteTail() which takes head reference and returns reference to the head node of the modifies list, which is then used to display the list. (The driver's code print the modified list twice, once forward and once backward)

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
2 <= number of nodes <= 103
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

Node* deleteTail(Node*);
void printDll(Node*);
Node* insertInTail(Node*, int);


int main() {
    int dll[] = {2,5,7,8,99,100};
    Node* head = NULL;

    for(int i : dll) {
        head = insertInTail(head, i);
    }

    printDll(head);

    head = deleteTail(head);

    printDll(head);
}

Node* deleteTail(Node* head) {
    if(!head)
        return head;

    if(!head->next)
        return NULL;

    Node* cur = head;
    while(cur->next) {
        cur = cur->next;
    }

    cur->prev->next = NULL;
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