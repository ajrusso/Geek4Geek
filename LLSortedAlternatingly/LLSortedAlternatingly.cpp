/*
Linked List that is Sorted Alternatingly

You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

Example 1:

    Input:
    n = 6
    LinkedList = 1->9->2->8->3->7
    
    Output: 1 2 3 7 8 9
    
    Explanation: 
    After sorting the given list will be 1->2->3->7->8->9.

Example 2:

    Input:
    n = 5
    LinkedList = 13->99->21->80->50
    Output: 13 21 50 80 99

    Explanation:
    After sorting the given list will be 13->21->50->80->99.

Your Task:
You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list of size n in non-decreasing order. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= Number of nodes <= 100
0 <= Values of the elements in linked list <= 103
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void sort(Node**);
void addNode(Node**, int);
void printList(Node*);


int main() {
    Node* head = NULL;
    int arr[] = {1,9,2,8,3,7};

    for(int i : arr) {
        addNode(&head, i);
    }
    
    sort(&head);

    printList(head);
}

void sort(Node** head) {
    if (head == NULL || *head == NULL)
        return;

    vector<int> data = {};
    Node* cur = *head;
    while(cur != NULL) {
        data.push_back(cur->data);
        cur = cur->next;
    }

    sort(data.begin(), data.end());

    cur = *head;
    for(int i = 0; i < data.size(); i++) {
        cur->data = data[i];
        cur = cur->next;
    }
}

void addNode(Node** head, int x) {
    if(*head == NULL) {
        *head = new Node(x);
    } else {
        addNode(&(*head)->next, x);
    }
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}