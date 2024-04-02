/*
Delete Tail of Linked List

Given a linked list of size n, you have to delete the tail (last element) in the linked list.

Example 1:

    Input:
    LinkedList: 1->2
    
    Output: 1

Example 2:

    Input:
    LinkedList: 2->5->7->8->99->100
    
    Output: 2 5 7 8 99

Your Task:
The task is to complete the function deleteTail() which takes head reference and returns reference to the head node, which is then used to display the list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
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
    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(99);
    head->next->next->next->next->next = new Node(100);

    head = deleteTail(head);

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteTail(Node* head) {
    Node* cur = head;

    while(cur->next->next)
        cur = cur->next;

    cur->next = NULL;

    return head;
}