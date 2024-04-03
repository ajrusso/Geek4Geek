/*
Join Two Linked Lists

Given two linked lists of size n1 and n2 respectively, you have to join the head of second list to 
the tail of first so that we can traverse both the lists using head of 1st list.

Example 1:

    Input:
    LinkedList1: 5
    LinkedList2: 1->2

    Output: 5 1 2

Example 2:

    Input:
    LinkedList1: 1->2->9->6->5->7
    LinkedList2: 99->8->4

    Output: 1 2 9 6 5 7 99 8 4

Your Task:
The task is to complete the function joinTheLists() which takes head1 and head2 references as arguments.
The function returns head of the first list after joining both lists. The printing is done automatically
by the driver code.

Expected Time Complexity: O(n1).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes in a linkedlist <= 103
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

Node* joinTheLists(Node*, Node*);

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(6);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(7);

    Node* head2 = new Node(99);
    head2->next = new Node(8);
    head2->next->next = new Node(4);

    head1 = joinTheLists(head1, head2); 

    while(head1) {
        cout << head1->data << " ";
        head1 = head1->next;
    }
}

Node* joinTheLists(Node* head1, Node* head2) {
    Node* cur = head1;
    
    while(cur->next)
        cur = cur->next;

    cur->next = head2;
    return head1;
}