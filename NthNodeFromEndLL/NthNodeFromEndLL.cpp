/*
Nth Node From End of Linked List

Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from
the end of the linked list.

Example 1:

    Input:
    N = 2
    LinkedList: 1->2->3->4->5->6->7->8->9

    Output: 8

    Explanation: In the first example, there
    are 9 nodes in linked list and we need
    to find 2nd node from end. 2nd node
    from end is 8.  

Example 2:

    Input:
    N = 5
    LinkedList: 10->5->100->5

    Output: -1

    Explanation: In the second example, there
    are 4 nodes in the linked list and we
    need to find 5th from the end. Since 'n'
    is more than the number of nodes in the
    linked list, the output is -1.

Your Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head
and N and you need to return Nth from the end or -1 in case node doesn't exist.

Note:
Try to solve in a single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= L <= 106
1 <= N <= 106
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

int getNthFromLast(Node*, int);

int main() {
    int n = 10;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next= new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    int result = getNthFromLast(head, n);

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl << endl << "The " << n << " node from the end of the list is " << result << endl << endl;
}

int getNthFromLast(Node* head, int n) {
    Node* first = head;
    Node* sec = head;
    
    int i = 0;
    while(i < n && first) {
        first = first->next;
        i++;
    }

    if(i != n)
        return -1;

    while(first) {
        first = first->next;
        sec = sec->next;
    }

    return sec->data;
}