/*
Delete Head of Doubly Linked List

Given a doubly linked list of size n, you have to delete the head of the linked list and return the new head.
Note: Please set the previous of new head to null, and set the next of old head to null, and then delete the old head.

Example 1:

Input:
    LinkedList: 1<-->2

    Output:
    2
    2

Example 2:

Input:
    LinkedList: 2<-->5<-->7<-->8<-->99<-->100

    Output:
    5 7 8 99 100
    100 99 8 7 5

Your Task:
The task is to complete the function deleteHead() which takes head reference and returns reference to the new head node, which is then used to display the list. (The driver's code print the modified list twice, once forward and once backward)

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

Node* deleteHead(Node*);
void printDll(Node*);


int main() {
    int dll[] = {2,5,7,8,99,100};
    Node* head = new Node(dll[0]);
    
    Node* cur = head;
    for(int i = 1; i < sizeof(dll)/sizeof(dll[0]); i++) {
        cur->next = new Node(dll[i]);
        cur->next->prev = cur;
        cur = cur->next; 
    }

    printDll(head);

    for(int i = 0; i < sizeof(dll)/sizeof(dll[0]); i++) {
        head = deleteHead(head);
        printDll(head);
    }
}

Node* deleteHead(Node* head) {    
    if(!head)
        return head;

    if(!head->next) {
        delete head;
        return NULL;
    }

   Node* tmp = head;
   head = tmp->next;
   head->prev = NULL;
   delete tmp;
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