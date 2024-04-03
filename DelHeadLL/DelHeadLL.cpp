/*
Delete Head of Linked List

Given a linked list of size n, you have to delete the head of the linked list and return the new head.
Note: Please also set the next of the original head to null.

Example 1:

    Input:
    LinkedList: 1->2
    
    Output: 2

Example 2:

    Input:
    LinkedList: 2->5->7->8->99->100

    Output: 5 7 8 99 100

Your Task:
The task is to complete the function deleteHead() which takes head referenceand returns reference to the new head node, which is then used to display the list. The printing is done automatically by the driver code.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
2 <= number of nodes <= 103
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

Node* deleteHead(Node*);


int main() {
    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(99);
    head->next->next->next->next->next = new Node(100);

    head = deleteHead(head);

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head) {
    return head->next;
}