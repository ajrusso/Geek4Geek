/*
Compare Circular Doubly Linked Lists

Given two circular doubly linked lists of sizes n1 and n2 respectively, the task is check if the corresponding elements of the lists are same or not.
The tail of a circular doubly linked list is connected to head via its next pointer, and the previous pointer of head is connected to the tail.

Example 1:

    Input:
    LinkedList1: 1
    LinkedList2: 1

    Output: 1

Example 2:

    Input:
    LinkedList1: 2<->5<->7<->8<->99<->100
    LinkedList2: 7<->8<->9<->73<->2

    Output: 0

Your Task:
The task is to complete the function compareCLL() which takes head1 and head2 references as an arguments. The function should return true if all the corresponding elements of the lists are same, else it should return false. (The driver's code print 1 if the returned value is true, otherwise false.)

Expected Time Complexity: O(n1 + n2).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 105
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

bool compareCll(Node*, Node*);
void printDll(Node*);
Node* insertInTail(Node*, int);


int main() {
    int dll1[] = {1,2,1,2};
    int dll2[] = {1,2};
    Node* head1 = NULL;
    Node* head2 = NULL;

    for(int i : dll1) {
        head1 = insertInTail(head1, i);
    }

    for(int i : dll2) {
        head2 = insertInTail(head2, i);
    }

    cout << "DLL 1: ";
    printDll(head1);

    cout << "DLL 2: ";
    printDll(head2);

    cout << ((compareCll(head1, head2)) ? "DLL1 = DLL2" : "DLL1 != DLL2") << endl;
}

bool compareCll(Node* head1, Node* head2) {
    Node* cur1 = head1;
    Node* cur2 = head2;

    do{
        if(cur1->data != cur2->data)
            return false;
        cur1 = cur1->next;
        cur2 = cur2->next;
    } while(cur1 != head1 && cur2 != head2);

    if(cur1 == head1 && cur2 == head2)
        return true;
    
    return false;
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