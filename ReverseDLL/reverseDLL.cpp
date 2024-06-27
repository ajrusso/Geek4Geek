/*
Reverse a Double Linked List

Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

Example 1:

    Input:
    LinkedList: 3 <--> 4 <--> 5

    Output: 5 4 3

Example 2:

    Input:
    LinkedList: 75 <--> 122 <--> 59 <--> 196
    
    Output: 196 59 122 75

Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference as argument and this function should reverse the elements such that the tail becomes the new head and all pointers are pointing in the right order. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 104
0 <= value of nodes <= 104
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

Node* reverseDLL(Node*);
void printDll(Node*);


int main() {
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;

    printDll(head);

    head = reverseDLL(head);

    printDll(head);
}

Node* reverseDLL(Node* head) {
    Node* cur = head;
    Node* tmp = NULL;

    while(cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }

    if(tmp)
        head = tmp->prev;

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