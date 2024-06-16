/*
Delete Head of Circular Linked List

Given a circular linked list of size n, you have to delete the head of the linked list and return the new head.
In the circular linked list the tail of the list is connected to the head using the next pointer.
Note: Please also set the next of the original head to null.

Example 1:

    Input:
    LinkedList: 1->2
    (the first and last node are connected,
    i.e. 2 --> 1)
    
    Output: 2

Example 2:

    Input:
    LinkedList: 2->5->7->8->99->100
    (the first and last node are connected,
    i.e. 100 --> 2)
    
    Output: 5 7 8 99 100

Your Task:
The task is to complete the function deleteHead() which takes head reference. The function deletes the head node and returns a reference to the new head node, which is then used to display the list. The printing is done automatically by the driver code.

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

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* deleteHead(Node*);

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    head = deleteHead(head);

    if(head) {
        Node* cur = head;
        do{
            cout << cur->data << " ";
            cur = cur->next;
        } while(cur != head);
    }
}

Node* deleteHead(Node* head) {
    if(!head)
        return NULL;

    if(head->next == head)
        return NULL;

    head->data = head->next->data;
    Node* tmp = head->next->next;
    delete head->next;
    head->next = tmp;

    return head;
}