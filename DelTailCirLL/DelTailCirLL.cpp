/*
Delete Tail of Circular Linked List

Given a circular linked list of size n, you have to delete the tail (last element) in the linked list.
In a circular linked list, the tail is connect to the head using the next pointer.

Example 1:

    Input:
    LinkedList: 1->2
    (the first and last node are connected,
    i.e. 2 --> 1)
    
    Output: 1

Example 2:

    Input:
    LinkedList: 2->5->7->8->99->100
    (the first and last node are connected,
    i.e. 100 --> 2)
    Output: 2 5 7 8 99

Your Task:
The task is to complete the function deleteTail() which takes head reference  and returns reference to the head node, which is then used to display the list. The printing is done automatically by the driver code.

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

Node* deleteTail(Node*);

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    head = deleteTail(head);

    Node* cur = head;
    do {
        cout << head->data << " ";
        head = head->next;
    } while(cur != head);
}

Node* deleteTail(Node* head) {
    Node* cur = head;

    if(!head)
        return NULL;

    if(head->next == head)
        return NULL;

    while(cur->next->next != head) {
        cur = cur->next;
    }
    
    delete cur->next;
    cur->next = head;
    return head;
}