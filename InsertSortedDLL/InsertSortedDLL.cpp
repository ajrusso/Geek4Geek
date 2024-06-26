/*
Insert in Sorted way in a Sorted DLL

Given a sorted doubly linked list and an element X, your need to insert the element X into correct position in the sorted DLL.

Note: The DLL is sorted in ascending order

Example:

Input:
LinkedList:

X = 9
Output:

Your Task:
You only need to complete the function sortedInsert() that takes head reference and x as arguments and returns the head of the modified list.The resulting DLL should be in ascending order. The printing and checking tasks are done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 103
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

Node* sortedInsert(Node*, int);
void printDll(Node*);


int main() {
    int dll[] = {3,5,8,10,12};
    int element = 9;
    Node* head = NULL;
    
    for(int i: dll) {
        head = sortedInsert(head, i);
    }

    printDll(head);

    head = sortedInsert(head, element);

    printDll(head);
}

Node* sortedInsert(Node* head, int x) {
    Node* n = new Node(x);
    Node* cur;

    if(!head)
        return n;

    cur = head;
    while(cur->next && x >= cur->data)
        cur = cur->next;

    if(!(cur->next) && x >= cur->data) {
        cur->next = n;
        n->prev = cur;
        return head;
    } 

    n->next = cur;
    n->prev = cur->prev;
    if(cur->prev)
        cur->prev->next = n;
    else 
        head = n;
    cur->prev = n;
    
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