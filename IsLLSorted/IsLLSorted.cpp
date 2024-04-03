/*
Is Linked List Sorted

Given a linked list of size n, you have to find whether the given linked list is sorted or not.
The sorting can either be non-increasing or non-decreasing.

Example 1:

Input:
LinkedList: 5->5->6->7->8
Output: 1
Example 2:

Input:
LinkedList: 2->5->7->8->99->7
Output: 0
Your Task:
The task is to complete the function isSorted() which takes head reference as argument. The function returns true if the LL is sorted, else it returns false. (The driver code prints 1 when the returned value is true, otherwise 0)

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 103
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

bool isSorted(Node*);

int main() {
    Node* head = new Node(5);
    head->next = new Node(5);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(8);

    bool result = isSorted(head);

    cout << (result ? "Is Sorted" : "Is NOT Sorted");
}

bool isSorted(Node* head) {
    bool increasing = false;
    bool decreasing = false;

    while(head->next) {
        if(increasing) {
            if(head->data > head->next->data)
                return false;
        } else if(decreasing) {
            if(head->data < head->next->data)
                return false;
        } else {
            if(head->data < head->next->data )
                increasing = true;
            if(head->data > head->next->data)
                decreasing = true;
        } 

        head = head->next;
    }

    return true;
}
