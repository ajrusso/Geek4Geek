/*
Merge Sort on Doubly Linked List

Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Example 1:

    Input:
    n = 8
    value[] = {7,3,5,2,6,4,1,8}

    Output:
    1 2 3 4 5 6 7 8
    8 7 6 5 4 3 2 1

    Explanation: After sorting the given
    linked list in both ways, resultant
    matrix will be as given in the first
    two line of output, where first line
    is the output for non-decreasing
    order and next line is for non-
    increasing order.

Example 2:

    Input:
    n = 5
    value[] = {9,15,0,-1,0}

    Output:
    -1 0 0 9 15
    15 9 0 0 -1

    Explanation: After sorting the given
    linked list in both ways, the
    resultant list will be -1 0 0 9 15
    in non-decreasing order and 
    15 9 0 0 -1 in non-increasing order.

Your Task:
The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing. The printing is done automatically by the driver code.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(logn)

Constraints:
1 <= n <= 104
0 <= values[i] <= 105
*/

#include <iostream>
#include <vector>
#include <algorithm>


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

Node* sortDoubly(Node*);
Node* add2End(Node*, int);


int main() {
    int n = 8;
    Node* head = NULL;
    head = add2End(head, 7);
    head = add2End(head, 3);
    head = add2End(head, 5);
    head = add2End(head, 2);
    head = add2End(head, 6);
    head = add2End(head, 4);
    head = add2End(head, 1);
    head = add2End(head, 8);

    head = sortDoubly(head);

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* sortDoubly(Node* head) {
    vector<int> v = {};

    Node* temp = head;
    while(temp) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end());

    temp = head;
    int i = 0;
    while(temp) {
        temp->data = v[i++];
        temp = temp->next; 
    }

    return head;
}

Node* add2End(Node* head, int data) {
    if(!head) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(data);
        temp->next->prev = temp;
    }
    return head;
}